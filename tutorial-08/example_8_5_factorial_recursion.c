#include <stdio.h>

int factorial(int);

int main() {
    int n, f;
    printf("Enter the number whose factorial you want to calculate?");
    scanf("%d", &n);
    f = factorial(n);
    printf("factorial = %d", f);

}

/**
 * Calculates the factorial of n (=n!) -> factorial(6)=6*5*4*3*2*1
 * @param n - Any number larger than 0 (included)
 * @return (n)*(n-1)*(n-2)*...*(1)
 */
int factorial(int n) {
    if (0 <= n && n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}  