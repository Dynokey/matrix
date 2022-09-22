#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int res = 0;
    if (err_matrix(A) || result == NULL) {
        res = 1;
    } else if (A->rows != A->columns) {
        res = 2;
    } else {
        if (A->rows == 1)
            determinant_1(A, result);
        else if (A->rows == 2)
            determinant_2(A, result);
        else if (A->rows == 3)
            determinant_3(A, result);
        else
            determinant_n(A, result);
    }
    return res;
}
