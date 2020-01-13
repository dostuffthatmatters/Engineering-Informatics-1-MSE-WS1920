/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 07
************************************************************************************/


#ifndef ENGINEERING_INFORMATICS_1_MSE_WS1920_STACK_H
#define ENGINEERING_INFORMATICS_1_MSE_WS1920_STACK_H

struct Stack {
    int max;  // Max number of elements the stack can hold
    char *top;
    char *bottom;
};

void print_stack_debug(struct Stack *s);

void init(struct Stack *s, char *buffer, int max);
int push(struct Stack *s, char c);
char peek(struct Stack *s);
char pop(struct Stack *s);
int depth(struct Stack *s);
void print_stack(struct Stack *s);

#endif
