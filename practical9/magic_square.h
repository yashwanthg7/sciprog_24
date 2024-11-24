#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


// Checks if a matrix is a magic square
int isMagicSquare(int **square, const int n) {
    // Eliminate the case where 'n' is negative
    if (n < 0) {
        return 0;
    }

    // M is the magic constant
    int M = (n * (n * n + 1)) / 2;

    // Check that every row and column add up to M
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += square[i][j];
            col_sum += square[j][i];
        }
        if (row_sum != M || col_sum != M) { // Fixed typo from col_sume
            return 0; // Not a magic square
        }
    }

    // Check that main and secondary diagonals add up to M
    int main_diag_sum = 0;
    int sec_diag_sum = 0;
    for (int i = 0; i < n; i++) {
        main_diag_sum += square[i][i];
        sec_diag_sum += square[i][n - 1 - i];
    }
    if (main_diag_sum != M || sec_diag_sum != M) {
        return 0; // Not a magic square
    }

    return 1; // Matrix is a magic square
}

