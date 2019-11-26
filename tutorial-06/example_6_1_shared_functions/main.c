
#include "print_matrices.h"

int main() {
    int my_matrix[5][5] = {
            {12, -23, 40, 45},
            {33, 4, 0, 45},
            {12}
    };

    print_int_matrix(5, 5, my_matrix);

    return 0;
}