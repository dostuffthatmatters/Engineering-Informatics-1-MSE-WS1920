#include <stdio.h>
#include <stdlib.h>

#include "string_operations.h"


struct equation_node *init_node(char *equation);
void free_node(struct equation_node *node);

int evaluate_node(struct equation_node *node);
int evaluate_mul_div(char *equation);


struct equation_node {
    char *equation;
    struct equation_node *left_child;
    struct equation_node *right_child;
};


int main() {

    char equation[256] = "14+33-4*5/2*3-78/3+5*30";
    struct equation_node *node = init_node(equation);
    int solution = evaluate_node(node);

    free_node(node);

    printf("Equation: %s, Solution: %d", equation, solution);
    return 0;
}


/**
 * This method initializes a node with a given equation and
 * returns a pointer to this node.
 */
struct equation_node *init_node(char *equation) {
    struct equation_node *node = calloc(sizeof(struct equation_node), 1);
    node->equation = deepcopy_string(equation);
    return node;
}


/**
 * This method frees up all memory used by an equation_node
 * and all its child nodes (recursively).
 */
void free_node(struct equation_node *node) {
    if (node->left_child != NULL) {
        free_node(node->left_child);
    }
    if (node->right_child != NULL) {
        free_node(node->right_child);
    }
    free(node->equation);
    free(node);
}


/**
 * This method evaluates the value
 * of a node containing an equation.
 */
int evaluate_node(struct equation_node *node) {

    // Looking for the first appearance of a plus-sign
    int index_add = char_in_string('+', node->equation);

    if (index_add == -1) {
        // In case there is no plus-sign in the given equation

        // Looking for the first appearance of a minus-sign
        int index_sub = char_in_string('-', node->equation);

        if (index_sub == -1) {
            // In case there IS NO minus-sign in the given
            // equation either the solution can be directly
            // calculated (given it only contains '*' and
            // '/'  operators)
            return evaluate_mul_div(node->equation);
        } else {
            // In case there IS a minus-sign in the given
            // equation the calculation gets recursively
            // split up into two node-evaluations
            char *left_child_equation = slice_string(node->equation, 0, index_sub - 1);
            struct equation_node *left_child = init_node(left_child_equation);

            // You have to swap the plus- and minus-signs
            // in the second equation because -(5-7) == -5+7
            char *right_child_equation = slice_string(node->equation, index_sub + 1, 99);
            swap(right_child_equation, '-', '+');
            struct equation_node *right_child = init_node(right_child_equation);

            return evaluate_node(left_child) - evaluate_node(right_child);
        }

    } else {
        // In case there IS a plus-sign in the given
        // equation the calculation gets recursively
        // split up into two node-evaluations
        char *left_child_equation = slice_string(node->equation, 0, index_add - 1);
        struct equation_node *left_child = init_node(left_child_equation);

        char *right_child_equation = slice_string(node->equation, index_add + 1, 99);
        struct equation_node *right_child = init_node(right_child_equation);

        return evaluate_node(left_child) + evaluate_node(right_child);
    }
}


/**
 * This method evaluates an equation containing only
 * multiplication- and division-operators.
 *
 * This happens sequentially so 5*4/5*16/4 gets
 * evaluated as (((5*4)/5)*16)/4.
 *
 * IMPORTANT: The divisions are always pure integer
 * division so the remainder of the division will be
 * ignored.
 */
int evaluate_mul_div(char *equation) {

    int product = 1;
    int current_sign = '*';

    for (int i=0; i<100; i++) {

        int current_number = 0;
        while (48 <= equation[i] && equation[i] <= 57) {
            if (equation[i] == ' ') {
                i++;
                continue;
            }
            current_number *= 10;
            current_number += equation[i] - 48;
            i++;
        }

        switch (current_sign) {
            case '*': product *= current_number; break;
            case '/': product /= current_number; break;
        }

        if (equation[i] == 42 || equation[i] == 47) {
            current_sign = equation[i];
        }

        if (equation[i] == '\0') {
            break;
        }
    }

    return product;
}
