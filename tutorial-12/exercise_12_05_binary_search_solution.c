
#include <stdio.h>
#include <stdlib.h>


int brute_force_search(int length, int array[length], int value){
    for (int i=0; i<length; i++) {
        if (array[i] == value) {
            return 1;
        }
    }

    // If the element has not been found
    // -> for-loop not aborted by "return 1"
    return 0;
}

int binary_search(int length, int array[length], int value){

    if (length == 0) {
        return 0;
    }

    int middle_index = length/2;

    if (array[middle_index] == value) {
        return 1;
    } else {
        int length_1 = middle_index;
        int length_2 = length - length_1 - 1;

        return (binary_search(length_1, array, value) +
        binary_search(length_2, array + length_1 + 1, value)) > 0;
    }
}

void print_array(int length, int array[length]){
    printf("\n[");
    for (int i=0; i<length-1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[length-1]);
}

int main(){

    int array[10] = {0, 1, 2, 2, 3, 4, 5, 8, 9, 17};

    print_array(10, array);

    printf("\nBrute-Force-Search: 6 in array -> %s", brute_force_search(10, array, 6) ? "true": "false");
    printf("\nBinary-Search: 6 in array -> %s\n", binary_search(10, array, 6) ? "true": "false");

    printf("\nBrute-Force-Search: 4 in array -> %s", brute_force_search(10, array, 4) ? "true": "false");
    printf("\nBinary-Search: 4 in array -> %s\n", binary_search(10, array, 4) ? "true": "false");

    printf("\nBrute-Force-Search: 16 in array -> %s", brute_force_search(10, array, 16) ? "true": "false");
    printf("\nBinary-Search: 16 in array -> %s\n", binary_search(10, array, 16) ? "true": "false");

    printf("\nBrute-Force-Search: 17 in array -> %s", brute_force_search(10, array, 17) ? "true": "false");
    printf("\nBinary-Search: 17 in array -> %s\n", binary_search(10, array, 17) ? "true": "false");

    printf("\nBrute-Force-Search: 0 in array -> %s", brute_force_search(10, array, 0) ? "true": "false");
    printf("\nBinary-Search: 0 in array -> %s\n", binary_search(10, array, 0) ? "true": "false");

    return 0;
}
