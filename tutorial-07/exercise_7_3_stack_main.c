
#include <stdio.h>
#include <stdlib.h>
#include "exercise_7_3_stack_implementation.h"


int main() {
    int max = 10;
    char *stack_memory = malloc(sizeof(char) * max);

    struct Stack my_stack;
    print_stack_debug(&my_stack);

    init(&my_stack, stack_memory, max);
    print_stack_debug(&my_stack);

    push(&my_stack, 'H');
    push(&my_stack, 'e');
    push(&my_stack, 'l');
    print_stack_debug(&my_stack);

    char pop_result = pop(&my_stack);
    printf("Pop -> %c (%d)\n", pop_result, pop_result);
    print_stack_debug(&my_stack);

    char peek_result = peek(&my_stack);
    printf("Peek -> %c (%d)\n", peek_result, peek_result);
    print_stack_debug(&my_stack);

    return 0;
}