#include <stdio.h>

int main() {

    for (int i=0; i<10; i++) {
        printf("i is now %d\n", i);
    }

    printf("Outside: i is now %d\n", i);

    return 0;
}