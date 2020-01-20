
#include <stdio.h>

void bubble_sort(int length, int array[length]){
    int swaps = 0;
    do {
        // Resetting swap counter
        swaps = 0;

        // Looping over all pairs of elements
        for (int i=0; i<length-1; i++){
            if (array[i] > array[i+1]) {
                // Swapping elements
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;

                // Increasing swap counter
                swaps++;
            }
        }
    } while (swaps > 0);

}

void print_array(int length, int array[length]){
    printf("\n[");
    for (int i=0; i<length-1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[length-1]);
}

int main(){

    int array[10] = {3, 17, 9, 0, 2, 5, 1, 4, 2, 8};

    print_array(10, array);
    bubble_sort(10, array);
    print_array(10, array);

    return 0;
}
