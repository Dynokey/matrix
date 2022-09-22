#include "s21_matrix.h"

void fill_in_matrix(matrix_t* A, double* arr) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix[i][j] = arr[i * A->columns + j];
        }
    }
}
