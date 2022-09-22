#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = 0;
    if (err_matrix(A) || err_matrix(B)) {
        res = 1;
    } else if (s21_create_matrix(A->rows, A->columns, result)) {
        res = 1;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        res = 2;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return res;
}
