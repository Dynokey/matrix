#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int res = 0;
    if (err_matrix(A) || result == NULL) {
        res = 1;
    } else if (s21_create_matrix(A->rows, A->columns, result)) {
        res = 1;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * number;
            }
        }
    }
    return res;
}
