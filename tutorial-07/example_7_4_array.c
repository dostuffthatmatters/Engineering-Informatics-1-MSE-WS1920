/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 07
************************************************************************************/


#include <stdio.h>

int main() {
    int my_array[10] = {0,1,4,9};
    printf("\nAddress of the first element = %p", &(my_array[0]));
    printf("\nAddress of the first element = %p", my_array);

    printf("\n\nAddress of the second element = %p", &(my_array[1]));
    printf("\nAddress of the second element = %p", my_array + 1);
    return 0;
}
