#include "s21_matrix.h"

int err_matrix(matrix_t *A) {
    int res = 0;
    if (A == NULL || A->rows < 1 || A->columns < 1) res = 1;
    return res;
}
