#include <stdio.h>

// You can simply reuse this function
void my_flush(void) {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main() {

    char input[16] = {'\0'};

    printf("\nPlease enter a string: ");
    scanf("%15s", input);
    my_flush();

    char first_character = input[0];

    printf("The first character is \"%c\".\n", first_character);
}
