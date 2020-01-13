/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 04
************************************************************************************/


#include <stdio.h>

int main() {

    int my_array[10];

    for (int i=0; i<10; i++) {
        my_array[i] = i+1;  // Initializing each element
        printf("\nIndex %d -> Value %d", i, my_array[i]);  // Printing each element
    }

    return 0;
}
