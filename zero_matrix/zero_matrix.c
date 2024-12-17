/*
    Write an algorithm such that if an element in an `M x N` matrix is `0`, its entire row and column are set to `0`.
*/

#include <stdio.h>
#include <stdlib.h>

#define true    (1 == 1)
#define false   !true

void nullify_row(int **matrix, int row, int num_cols) {
    int i = 0;

    for (i = 0; i < num_cols; i++) {
        matrix[row][i] = 0;
    }
}

void nullify_column(int **matrix, int column, int num_rows) {
    int i = 0;

    for (i = 0; i < num_rows; i++) {
        matrix[i][column] = 0;
    }
}

void zero_matrix(int **matrix, int rows, int cols) {
    int m = 0;
    int n = 0;
    int first_row_has_zero = false;
    int first_col_has_zero = false;

    for (m = 0; m < rows; m++) {
        if (matrix[m][0] == 0) {
            first_col_has_zero = true;
            break;
        }
    }

    for (n = 0; n < cols; n++) {
        if (matrix[0][n] == 0) {
            first_row_has_zero = 0;
            break;
        }
    }

    for (m = 1; m < rows; m++) {
        for (n = 1; n < cols; n++) {
            if (matrix[m][n] == 0) {
                matrix[0][n] = 0;
                matrix[m][0] = 0;
            }
        }
    }

    for (m = 1; m < rows; m++) {
        if (matrix[m][0] == 0) {
            nullify_row(matrix, m, cols);
        }
    }

    for (n = 1; n < cols; n++) {
        if (matrix[0][n] == 0) {
            nullify_column(matrix, n, rows);
        }
    }

    if (first_row_has_zero) {
        nullify_row(matrix, 0, cols);
    }

    if (first_col_has_zero) {
        nullify_column(matrix, 0, rows);
    }
}

int main(int argc, char **argv) {
    int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int m = 0;
    int n = 0;
    int value = 1;

    // matrix = malloc(4 * sizeof(int*));

    // for (m = 0; m < 4; m++) {
    //     matrix[m] = malloc(4 * sizeof(int));
    // }

    // for (m = 0; matrix[m] != NULL; m++) {
    //     for (n = 0; matrix[m][n] != NULL; n++) {
    //         matrix[m][n] = value;
    //         value++;
    //     }
    // }

    // matrix[1][2] = 0;

    for (m = 0; m < 4; m++) {
        for (n = 0; n < 4; n++) {
            printf("%d\t", matrix[m][n]);
        }
        
        printf("\n");
    }

    printf("---------------\n");

    zero_matrix(matrix, 4, 4);

    for (m = 0; m < 4; m++) {
        for (n = 0; n < 4; n++) {
            printf("%d\t", matrix[m][n]);
        }
        
        printf("\n");
    }
}
