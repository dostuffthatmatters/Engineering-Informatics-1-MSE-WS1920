#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 0;
    int b = 1;

    if (!(a && b)) {
        printf("\n1: True");
    } else {
        printf("\n1: False");
    }

    if ((!a && b) || (a && !b)) {
        printf("\n2: True");
    } else {
        printf("\n2: False");
    }
}
