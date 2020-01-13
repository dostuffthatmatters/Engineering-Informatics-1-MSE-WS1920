/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 05
************************************************************************************/


#include <stdio.h>

/**
 * This function determines whether a given string is a palindrome or not
 *
 * @param string - char array
 * @param max_length - length of the memory block of the char array
 *
 * @return 1 (if the string is a palindrome) or 0 (otherwise)
 */

/**
 * This function determines the largest element inside the int array
 *
 * @param array - int array
 * @param length - length of the memory block of the int array
 *
 * @return The largest element inside the int array
 */
int largest_element(int *array, int length) {

    int largest_element = 0;

    for (int i=0; i<length; i++) {
        if (array[i] > largest_element) {
            largest_element = array[i];
        }
        printf("Index: %d, Largest Element: %d\n", i, largest_element);
    }

    return largest_element;
}



















int main() {

    int a[10] = {1, 2, 3, 50, 2, 60};

    printf("The largest number in a is %d.", largest_element(a, 10));
    return 0;
}
