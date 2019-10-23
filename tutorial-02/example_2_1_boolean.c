#include <stdio.h>
#include <stdbool.h>

int main() {
    bool a = true;
    bool b = false;
    bool c = true;

    // This however is just a wrapper for the integer values
    // 0 and 1, so it can be printed as 0 and 1 respectively
    printf("\n%d", a && b);
    printf("\n%d", a && c);

    printf("\n");

    // If you want to get extra fancy
    printf("\n%s", a && b ? "true" : "false");
    printf("\n%s", a && c ? "true" : "false");

    printf("\n");
}
