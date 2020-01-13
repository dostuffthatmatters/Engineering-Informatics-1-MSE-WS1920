/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 07
************************************************************************************/


#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    char d = 10;
    char e = 20;
    char f = 30;

    int *pointer_a = &a;
    int *pointer_b = &b;
    int *pointer_c = &c;

    char *pointer_d = &d;
    char *pointer_e = &e;
    char *pointer_f = &f;

    printf("\nThe address of a is %p", pointer_a);
    printf("\nThe address of b is %p", pointer_b);
    printf("\nThe address of c is %p", pointer_c);

    printf("\nThe address of d is %p", pointer_d);
    printf("\nThe address of e is %p", pointer_e);
    printf("\nThe address of f is %p", pointer_f);

    return 0;
}
