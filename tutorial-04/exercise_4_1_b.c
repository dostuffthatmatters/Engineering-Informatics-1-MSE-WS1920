/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 04
************************************************************************************/


#include <stdio.h>
#include <math.h>

int main() {

    int my_array[10];

    for (int i=0; i<10; i++) {
        my_array[i] = pow(i+1, 2);  // Initializing each element
        // my_array[i] = (i+1) * (i+1); -> Basically does the same
        printf("\nIndex %d -> Value %d", i, my_array[i]);  // Printing each element
    }

    return 0;
}
