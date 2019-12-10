#include <stdio.h>

int main() {
    int n, f;
    printf("Enter the number whose factorial you want to calculate?");
    scanf("%d", &n);

    if (0 <= n && n <= 1) {
        f = n;
    } else {
        f = 1;
        for (int i=2; i<=n; i++) {
            f *= i;
        }
    }

    printf("factorial = %d", f);

}
