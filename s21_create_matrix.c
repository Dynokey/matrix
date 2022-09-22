#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
    int res = 0;
    result->matrix = (double**)calloc(rows, sizeof(double*));
    if (rows < 1 || columns < 1) {
        res = 1;
    } else if (result->matrix == NULL) {
        res = 1;
    } else {
        result->rows = rows;
        result->columns = columns;
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = ((double*)calloc(columns, sizeof(double*)));
            // if (result->matrix[i] == NULL) {
            //     res = 1;
            //     break;
            // }
        }
    }
    return res;
}
