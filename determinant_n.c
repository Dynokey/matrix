#include "s21_matrix.h"

void determinant_n(matrix_t *A, double *result) {
    *result = 0;
    int sing = 1;
    for (int j = 0; j < A->rows; j++) {
        double result_tmp = 0.0;
        matrix_t tmp;
        s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
        // Удалить из матрицы i-ю строку и j-ый столбец результат в tmp
        get_minor(A, 0, j, &tmp);
        s21_determinant(&tmp, &result_tmp);
        s21_remove_matrix(&tmp);
        result_tmp = result_tmp * sing * A->matrix[0][j];
        *result += result_tmp;
        sing = -sing;
    }
}
