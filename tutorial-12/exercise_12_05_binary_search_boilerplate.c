
#include <stdio.h>
#include <stdlib.h>


int brute_force_search(int length, int array[length], int value){
    return 0;
}

int binary_search_iterative(int length, int array[length], int value){
    

    return 0;
}

int binary_search_recursive(int length, int array[length], int value){
    if (length == 0) {
        return 0;
    } else {
        int mid_index = length/2;

        if (array[mid_index] == value) {
            return 1;
        } else if (array[mid_index] > value){
            return binary_search_recursive(mid_index, array, value);
        } else {
            return binary_search_recursive(length - mid_index - 1, array + mid_index + 1, value);
        }
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
    printf("\nBinary-Search: 6 in array -> %s\n", binary_search_recursive(10, array, 6) ? "true": "false");

    printf("\nBrute-Force-Search: 4 in array -> %s", brute_force_search(10, array, 4) ? "true": "false");
    printf("\nBinary-Search: 4 in array -> %s\n", binary_search_recursive(10, array, 4) ? "true": "false");

    printf("\nBrute-Force-Search: 16 in array -> %s", brute_force_search(10, array, 16) ? "true": "false");
    printf("\nBinary-Search: 16 in array -> %s\n", binary_search_recursive(10, array, 16) ? "true": "false");

    printf("\nBrute-Force-Search: 17 in array -> %s", brute_force_search(10, array, 17) ? "true": "false");
    printf("\nBinary-Search: 17 in array -> %s\n", binary_search_recursive(10, array, 17) ? "true": "false");

    printf("\nBrute-Force-Search: 2 in array -> %s", brute_force_search(10, array, 2) ? "true": "false");
    printf("\nBinary-Search: 2 in array -> %s\n", binary_search_recursive(10, array, 2) ? "true": "false");

    return 0;
}
