#include <stdio.h>

void apply(int *number, void (*function)(int *));

void increment(int *number);
void decrement(int *number);
void square(int *number);
void cube(int *number);

int main() {
    int number = 3;

    printf("Number is %d\n", number);

    printf("\nApplying \"increment\"\n");
    apply(&number, increment);
    printf("Number is %d\n", number);

    printf("\nApplying \"decrement\"\n");
    apply(&number, decrement);
    printf("Number is %d\n", number);

    printf("\nApplying \"square\"\n");
    apply(&number, square);
    printf("Number is %d\n", number);

    printf("\nApplying \"cube\"\n");
    apply(&number, cube);
    printf("Number is %d\n", number);
}


/**
 * This is a higher order function that apply
 * a given "function" to an element "number"
 *
 * @param number - element to apply the function on
 * @param function - function to be applied
 */
void apply(int *number, void (*function)(int *)) {
    function(number);
}


void increment(int *number) {
    *number += 1;
}

void decrement(int *number) {
    *number -= 1;
}

void square(int *number) {
    *number = *number * *number;
}

void cube(int *number) {
    *number = *number * *number * *number;
}

