#include <stdio.h>
#include "hidden_matrix_functions_moritz_makowski.c"

int main() {

    // Independent Solution from Wolfram Alpha:
    // https://www.wolframalpha.com/input/?i=determinant+of+%7B%7B-7%2C2%2C3%2C4%2C5%2C6%2C7%2C0%7D%2C%7B2%2C2%2C3%2C4%2C5%2C6%2C7%2C1%7D%2C%7B3%2C2%2C3%2C43%2C5%2C6%2C7%2C2%7D%2C%7B4%2C2%2C-3%2C1%2C5%2C6%2C7%2C3%7D%2C%7B5%2C2%2C3%2C4%2C1%2C-6%2C7%2C4%7D%2C%7B6%2C2%2C3%2C4%2C4%2C6%2C7%2C9%7D%2C%7B7%2C2%2C3%2C4%2C5%2C6%2C-3%2C6%7D%2C%7B8%2C2%2C3%2C4%2C5%2C6%2C-9%2C7%7D%7D

    struct Tensor my_8x8_matrix = {.M.A8 = {
            {-7, 2, 3,  4,  5, 6,  7,  0},
            {2,  2, 3,  4,  5, 6,  7,  1},
            {3,  2, 3,  43, 5, 6,  7,  2},
            {4,  2, -3, 1,  5, 6,  7,  3},
            {5,  2, 3,  4,  1, -6, 7,  4},
            {6,  2, 3,  4,  4, 6,  7,  9},
            {7,  2, 3,  4,  5, 6,  -3, 6},
            {8,  2, 3,  4,  5, 6,  -9, 7}
    }, .dim=8};

    int my_8x8_determinant = determinant(my_8x8_matrix);

    printf("Determinant: %d", my_8x8_determinant);

    return 0;
}
