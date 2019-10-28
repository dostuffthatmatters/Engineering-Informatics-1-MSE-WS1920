
#include <stdio.h>

int main() {
    unsigned char a = 254;
    unsigned char b = 1;
    unsigned char c = 2;
    unsigned char d = 3;
    unsigned char e = 4;

    unsigned char ab = a + b;
    unsigned char ac = a + c;
    unsigned char ad = a + d;
    unsigned char ae = a + e;

    printf("\n%d", ab);
    printf("\n%d", ac);
    printf("\n%d", ad);
    printf("\n%d\n", ae);

    return 0;
}