#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int my_random = rand() % 42;
    printf("%d\n", my_random);
}
