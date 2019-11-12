#include <stdio.h>

char is_perfect(int number){
    int sum = 0;
    for (int divisor=1; divisor<number; divisor++) {
        if (number % divisor == 0) {
            sum += divisor;
        }
    }
    return (sum == number);
}

int main() {

    int rounds = 6;

    printf("The first %d Perfect-Numbers are:\n", rounds);

    int n = 1;
    for (int round = 1; round <= rounds;){
        if (is_perfect(n)) {
            printf("%d\n", n);
            round++;
        }
        if (n % 10000 == 0) {
            printf("\nNumber %d\n\n", n);
        }
        n++;
    }

    return 0;
}
