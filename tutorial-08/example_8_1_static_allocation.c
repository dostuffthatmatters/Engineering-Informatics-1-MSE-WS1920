#include <stdio.h>
#include <stdlib.h>

int main() {

    char input_array[8] = {0};

    printf("Enter a number: ");
    scanf("%7s", input_array);

    int input_number = atoi(input_array);
    printf("You've entered: %d (\"%s\").\n\n", input_number, input_array);

    int my_array[input_number] = {0};

    return 0;
}