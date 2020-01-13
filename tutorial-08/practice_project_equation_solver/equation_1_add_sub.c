/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 08
************************************************************************************/


#include <stdio.h>

int evaluate_add_sub(char *equation, int max_length);

int main() {
    char equation_1[100] = "14+33-4-78+5";
    int solution_1 = evaluate_add_sub(equation_1, 100);

    printf("Equation: %s, Solution: %d", equation_1, solution_1);

    return 0;
}

/**
 * This method evaluates an equation containing only
 * addition- and subtraction-operators.
 */
int evaluate_add_sub(char *equation, int max_length) {

    int sum = 0;
    int current_sign = 1;

    for (int i=0; i<max_length; i++) {

        int current_number = 0;
        while (48 <= equation[i] && equation[i] <= 57) {
            current_number *= 10;
            current_number += equation[i] - 48;
            i++;
        }
        sum += current_sign * current_number;

        if (equation[i] == 43) {
            current_sign = 1;
        } else if (equation[i] == 45) {
            current_sign = -1;
        }

        if (equation[i] == '\0') {
            break;
        }
    }

    return sum;
}
