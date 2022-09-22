#include "s21_matrix.h"

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
    int res = SUCCESS;
    if (err_matrix(A) || err_matrix(B)) {
        res = FAILURE;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        res = FAILURE;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
                    res = FAILURE;
                    break;
                }
            }
        }
    }
    return res;
}
