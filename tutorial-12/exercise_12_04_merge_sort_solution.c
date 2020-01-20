
#include <stdio.h>
#include <stdlib.h>

int *merge_lists(int length_1, int array_1[length_1], int length_2, int array_2[length_2]);


void merge_sort(int length, int array[length]){
    if (length > 1) {
        // Determining the length of the two new sub-arrays
        int length_1 = (length/2);
        int length_2 = (length - length_1);

        // Recursive Call
        merge_sort(length_1, array);
        merge_sort(length_2, array + length_1);

        // Merge the two separately merge-sorted lists back together
        int *new_array = merge_lists(length_1, array, length_2, array + length_1);

        // Copying over new arrays contents
        for (int i=0; i<length; i++) {
            array[i] = new_array[i];
        }

        // Freeing the intermediate memory
        free(new_array);
    }
}

/**
 * Returns a pointer to the newly created merged list which
 * has the combined length of length_1 and length_2.
 *
 * @param length_1
 * @param array_1
 * @param length_2
 * @param array_2
 *
 * @return Pointer to the first element of the new int array
 */
int *merge_lists(int length_1, int array_1[length_1], int length_2, int array_2[length_2]){

    // We are going to need a new memory space for the new list.
    int *new_array = calloc(sizeof(int), length_1 + length_2);

    /*
     * We definitely could do merge sort without any extra memory
     * space for the intermediate arrays, BUT we'd have to shift
     * the whole array content around all the time. We'd save a
     * little bit of memory but the processing time would increase
     * a lot! (Depending on how long it takes to dynamically allo-
     * cate memory)
     */

    // This is a double loop over both lists merged into the syntax of
    // one loop - don't quite know if its more elegant or less readable
    for (int counter_1=0, counter_2=0; counter_1<length_1 || counter_2<length_2;){

        if (counter_1 >= length_1) {
            // List 1 is already empty -> list 2 must not be empty
            new_array[counter_1 + counter_2] = array_2[counter_2];
            counter_2++;
        } else if (counter_2 >= length_2) {
            // List 2 is already empty -> list 1 must not be empty
            new_array[counter_1 + counter_2] = array_1[counter_1];
            counter_1++;
        } else {
            // Neither of the two lists is empty -> comparison of which comes next
            if (array_1[counter_1] < array_2[counter_2]){
                new_array[counter_1 + counter_2] = array_1[counter_1];
                counter_1++;
            } else {
                new_array[counter_1 + counter_2] = array_2[counter_2];
                counter_2++;
            }
        }
    }

    return new_array;
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
    merge_sort(10, array);
    print_array(10, array);

    return 0;
}
