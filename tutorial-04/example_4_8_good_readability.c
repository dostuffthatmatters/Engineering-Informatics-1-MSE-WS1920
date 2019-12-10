#include <stdio.h>

/**
 * This function calculates the checksum from a given number
 *
 * @param number - The number from which the checksum shall be calculated
 * @return checksum of that number
 */
int calculate_cecksum (int number) {
    // The checksum will be iteratively added to 'result'
    int result = 0;

    // Iterating over every decimal place -> Adding
    // every single digit to the result variable
    while (number > 0) {
        // 'remainder' is now equal to the digit at
        // the 0th decimal place:
        // number = 1243 -> remainder = 3;
        int remainder = (number % 10);

        // Adding that digit to the checksum
        result += remainder;

        // Now ignoring the last digit and shift the
        // number by one decimal place to the right

        // 1) number = 1243
        number -= remainder;
        // 2) number = 1240
        number /= 10;
        // 3) number = 124
    }
    return result;
}

int main () {
    int number = 469;

    // Getting the checksum for that number
    int checksum = calculate_cecksum(number);

    printf("%d\n", checksum);
    return 0;
}