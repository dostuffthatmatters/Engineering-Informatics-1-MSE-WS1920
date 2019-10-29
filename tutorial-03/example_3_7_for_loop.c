#include <stdio.h>

int main() {

    int prime_numbers_found = 0;
    int upper_limit = 100;

    for (int dividend=2; dividend<upper_limit; dividend++) {
        char is_prime = 1;  // true

        for (int divisor=2; divisor<dividend; divisor++) {
            if (dividend % divisor == 0) {
                is_prime = 0;  // Even divisor found -> is_prime = false
            }
        }

        if (is_prime) {
            // Only execute of the dividend is a prime
            prime_numbers_found++;
            printf("\n%d", dividend);
        }
    }

    printf("\n\nThere are %d prime numbers smaller than %d.\n\n", prime_numbers_found, upper_limit);

    return 0;
}
