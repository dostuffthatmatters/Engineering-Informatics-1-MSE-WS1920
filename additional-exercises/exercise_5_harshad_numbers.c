#include <stdio.h>

int get_cecksum (int number) {
    int result = 0;

    // Iterating over every decimal place -> Adding
    // every single digit to the result variable
    while (number > 0) {
        int remainder = (number % 10);
        result += remainder;

        number -= remainder;
        number /= 10;
    }
    return result;
}

char is_harshad(int n){
    return ((n % get_cecksum(n)) == 0);
}

int main() {

    int rounds = 250;

    printf("The first %d Harshad-Numbers are:\n", rounds);

    int n = 1;
    for (int round = 1; round <= rounds;){
        if (is_harshad(n)) {
            printf("%d\n", n);
            round++;
        }
        n++;
    }

    return 0;
}
