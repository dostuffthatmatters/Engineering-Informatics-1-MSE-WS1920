/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 07
************************************************************************************/


#include <stdio.h>

void add_10(int value) {
    value += 10;
}

int main() {
    int my_value = 10;
    add_10(my_value);
    printf("My value is %d\n", my_value);

    return 0;
}