#include "s21_matrix.h"

void determinant_2(matrix_t *A, double *result) {
    *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
}
