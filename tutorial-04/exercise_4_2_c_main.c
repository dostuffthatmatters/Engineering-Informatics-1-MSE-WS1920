/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 04
************************************************************************************/


#include <stdio.h>
#include "exercise_4_2_c_binary.c"

int main() {
    char my_string_a[10] = "100111101";
    char my_string_b[10] = "1001a111b";

    int binary_a = is_binary(my_string_a, 10);
    int binary_b = is_binary(my_string_b, 10);

    if (binary_a) {
        printf("String A is binary.\n");
    } else {
        printf("String A is not binary.\n");
    }

    if (binary_b) {
        printf("String B is binary.\n");
    } else {
        printf("String B is not binary.\n");
    }

    return 0;
}
