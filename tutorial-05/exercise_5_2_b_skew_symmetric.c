/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 05
************************************************************************************/


/**
 * This function determines whether a given matrix is symmetric or not
 *
 * @param rows - Number of rows of the passed matrix
 * @param columns - Number of columns of the passed matrix
 * @param matrix - Matrix with size (rows x columns)
 * 
 * @return 1 (if the given matrix is symmetric) or 0 (otherwise)
 */
char is_skew_symmetric(char rows, char columns, int matrix[rows][columns]) {
    if (rows != columns) {
        // Matrices that do not have the same number
        // of rows and columns can't be diagonal
        return 0;
    }

    for (char row=0; row<rows; row++) {
        for (char column=0; column<=row; column++) {

            if (row == column) {
                // In theory it should also work without this row==column if-clause
                // because 0==-0. But on different CPU's you never know ...
                if (matrix[row][column] != 0) {
                    return 0;
                }
            } else if (matrix[row][column] != - matrix[column][row]) {
                // Non-Zero element somewhere else than on the diagonal
                return 0;
            }
        }
    }

    // Return test cases only if all elements
    // besides the ones on the diagonal are zero
    return 1;
}
