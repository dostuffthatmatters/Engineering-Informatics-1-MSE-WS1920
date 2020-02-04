#include <stdio.h>
#include <math.h>

void print_uint_as_binary(unsigned short n) {
    // number of bits of an unsigned integer
    // (Not always the same)
    short bit_count = 8 * (short)sizeof(n);

    for (int i=bit_count-1; i>=0; i--) {
        // Extra variable because of reuse
        unsigned int power_of_2 = pow(2, i);

        // print binary digit
        if (n >= power_of_2) {
            printf("1");
        } else {
            printf("0");
        }

        // Dot between every 4-bit block of bits
        if ((i) % 4 == 0 && i > 0) {
            // printf(".");
        }

        // Decrement n for next binary digit
        n = n % power_of_2;
    }

    printf("\n");
}

int main() {

    unsigned short a = 43;
    unsigned short b = 3678;

    printf("\na:  %d", a);
    printf("\na:  "); print_uint_as_binary(a);
    printf("\nb:  %d", b);
    printf("\nb:  "); print_uint_as_binary(b);
    printf("\n");

    // -------------------------------------------

    a = a << 3; // a *= 2^3
    printf("<<: "); print_uint_as_binary(a);

    a = a >> 2; // a /= 2^2
    printf(">>: "); print_uint_as_binary(a);

    a = ~a;
    printf("~:  "); print_uint_as_binary(a);

    // -------------------------------------------

    printf("\n");
    printf("a:  "); print_uint_as_binary(a);
    printf("b:  "); print_uint_as_binary(b);

    printf("\n");
    printf("&:  "); print_uint_as_binary(a & b);
    printf("|:  "); print_uint_as_binary(a | b);
    printf("^:  "); print_uint_as_binary(a ^ b);

    return 0;
}
