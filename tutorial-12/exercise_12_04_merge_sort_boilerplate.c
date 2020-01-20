
#include <stdio.h>

void merge_sort(int length, int array[length]){

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
