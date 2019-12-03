#include <stdio.h>

void print_array(int length, char array[length]) {
    for (int i=0; i<length; i++) {
        printf("\nIndex %d -> Address %p - Value %d", i, &(array[i]), array[i]);
    }
}

int main() {
    char my_array[10] = {0,1,4,9,16,25,36,49,64,81};
    print_array(10, my_array);
    return 0;
}
