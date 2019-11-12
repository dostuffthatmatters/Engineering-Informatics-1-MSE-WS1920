#include <stdio.h>
#include <math.h>

/**
 * This function calculates the checksum from a given number
 *
 * @param number - The number from which the checksum shall be calculated
 * @return checksum of that number
 */
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

int main () {
    int number = 9;
    int checksum = get_cecksum(number);
    printf("%d\n", checksum);
    return 0;
}