#include <stdlib.h>

#include "string_operations.h"


/**
 * This method returns a copy of the given string.
 * The string is therefore duplicated inside memory
 *
 * @param string - Source String
 * @return Pointer to the first char of the next string.
 */
char *deepcopy_string(char *string) {
    char *copy = calloc(sizeof(char), STRING_LENGTH);
    for (int i=0; i<STRING_LENGTH && string[i] != '\0'; i++) {
        copy[i] = string[i];
    }
    return copy;
}


/**
 * This method takes in a string and returns a new string
 * only containing a slice of the old string.
 *
 * @param string - source string
 * @param from_index - start index of slice
 * @param to_index - end index of slice
 * @return pointer to new char array
 */
char *slice_string(char *string, int from_index, int to_index) {
    char *slice = calloc(sizeof(char), STRING_LENGTH);
    for (int i=from_index, slice_index=0; i<=to_index && string[i] != '\0'; i++, slice_index++) {
        slice[slice_index] = string[i];
    }
    return slice;
}


/**
 * This method replaces every appearance of a character inside
 * a string with some other character.
 *
 * IMPORTANT: The actual memory of the given string gets manipulated.
 */
void replace(char *equation, char old, char new) {
    for (int i=0; i<100; i++) {
        if (equation[i] == old) {
            equation[i] = new;
        }
    }
}


/**
 * This method swaps every appearance of two character inside
 * a string. E.g. ('+' <-> '-') After the swap every '-' is now
 * a '+' and every '+' is now a minus.
 *
 * IMPORTANT: The actual memory of the given string gets manipulated.
 */
void swap(char *string, char char_1, char char_2) {

    char *copy = calloc(sizeof(char), STRING_LENGTH);

    for (int i=0; i<STRING_LENGTH && string[i] != '\n'; i++) {
        if (string[i] == char_1) {
            copy[i] = char_2;
        } else {
            copy[i] = string[i];
        }
    }

    for (int i=0; i<STRING_LENGTH && copy[i] != '\n'; i++) {
        string[i] = copy[i];
    }

    free(copy);
}


/**
 * This function return the index of the first appearance
 * of a give character in a given string. Returns -1 if
 * the string does not contain the character.
 *
 * @param character - character to loog for
 * @param string - string to investigate
 * @return Index of the first appearance or -1 if nothing is found
 */
int char_in_string(char character, char *string) {
    for (int i=0; i<STRING_LENGTH; i++) {
        if (string[i] == '\0') {
            return -1;
        } else if (string[i] == character) {
            return i;
        }
    }
    return -1;
}


/**
 * This function return the index of the first appearance
 * of ANY character inside the given array of characters.
 * in a given string. Returns -1 if the string does not
 * contain the character.
 *
 * @param characters - possible characters
 * @param char_count - number of possible characters
 * @param string - string to investigate
 * @return Index of the first appearance or -1 if nothing is found
 */
int chars_in_string(char *characters, int char_count, char *string) {
    for (int i=0; i<100; i++) {
        if (string[i] == '\0') {
            return -1;
        } else {
            for (int j=0; j<char_count; j++) {
                if (string[i] == characters[j]) {
                    return i;
                }
            }
        }
    }
    return -1;
}

