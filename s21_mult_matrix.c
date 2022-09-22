#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = 0;
    if (err_matrix(A) || err_matrix(B) || result == NULL) {
        res = 1;
    } else if (s21_create_matrix(A->rows, B->columns, result)) {
        res = 1;
    } else if (A->columns != B->rows) {
        res = 2;
    } else {
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                result->matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                for (int h = 0; h < A->columns; h++) {
                    result->matrix[i][j] += A->matrix[i][h] * B->matrix[h][j];
                }
            }
        }
    }
    return res;
}
