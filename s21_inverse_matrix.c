#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int res = 0;
    double det = 0;
    if (err_matrix(A) || result == NULL) {
        res = 1;
    } else if (s21_determinant(A, &det) != 0 || fabs(det - 0) < EPS) {
        res = 2;
    } else if (A->rows != A->columns) {
        res = 2;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        if (A->columns == 1) {
            result->matrix[0][0] = 1.0 / det;
        } else {
            matrix_t complements;
            s21_calc_complements(A, &complements);
            matrix_t transpose;
            s21_transpose(&complements, &transpose);
            for (int i = 0; i < transpose.rows; i++) {
                for (int j = 0; j < transpose.columns; j++) {
                    result->matrix[i][j] = transpose.matrix[i][j] / det;
                }
            }
            s21_remove_matrix(&complements);
            s21_remove_matrix(&transpose);
        }
    }
    return res;
}
