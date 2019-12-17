
#include <stdio.h>

#include "map.h"

void increment(struct node *node);
void decrement(struct node *node);
void square(struct node *node);
void cube(struct node *node);

/**
 * This program emulates the usage of our singly
 * linked list in order to test the implementation
 * of our map-function.
 */
int main() {

    struct list *list = init_list();
    append(list, 2);
    append(list, 5);
    append(list, 4);
    append(list, 3);

    printf("\n---------------------\n\n");

    print_list(list);

    printf("\nmapping \"increment\"\n");
    map(list, increment);
    print_list(list);

    printf("\nmapping \"decrement\"\n");
    map(list, decrement);
    print_list(list);

    printf("\nmapping \"square\"\n");
    map(list, square);
    print_list(list);

    printf("\nmapping \"cube\"\n");
    map(list, cube);
    print_list(list);

    printf("\n---------------------\n\n");

    // Very important!
    remove_list(list);

    return 0;
}

void increment(struct node *node) {
    node->value = node->value + 1;
}

void decrement(struct node *node) {
    node->value = node->value - 1;
}

void square(struct node *node) {
    node->value = node->value * node->value;
}

void cube(struct node *node) {
    node->value = node->value * node->value * node->value;
}

