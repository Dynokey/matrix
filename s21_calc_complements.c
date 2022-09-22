#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int res = 0;
    if (err_matrix(A) || result == NULL) {
        res = 1;
    } else if (A->rows != A->columns || A->rows == 1) {
        res = 2;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        int sign = 1;
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                double temp;
                matrix_t compl;
                s21_create_matrix(A->rows - 1, A->columns - 1, &compl);
                get_minor(A, i, j, &compl);
                s21_determinant(&compl, &temp);
                s21_remove_matrix(&compl);
                result->matrix[i][j] = temp * sign;
                sign = sign * -1;
            }
            if (A->rows % 2 == 0) {
                sign = sign * -1;
            }
        }
    }
    return res;
}
