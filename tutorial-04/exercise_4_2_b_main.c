#include <stdio.h>
#include "exercise_4_2_b_prime.c"

int main() {
    for (int i=0; i<100; i++) {
        int prime = is_prime(i);
        switch (prime) {
            case 1:
                printf("%d is a prime.\n", i);
                break;
            default:
                printf("%d is a not prime.\n", i);
                break;
        }

    }
    return 0;
}
