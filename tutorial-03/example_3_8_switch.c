/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 03
************************************************************************************/


#include <stdio.h>

int main() {

    int a=2;

    printf("\n");

    switch(a) {
        default:
            printf("a is something\n");
            break;
        case 1:
            printf("a is one\n");
            break;
        case 2:
            printf("a is two\n");
            break;
        case 3:
            printf("a is three\n");
            break;
    }

    printf("\n");

    return 0;
}
