#include "s21_matrix.h"

// int main(){
//     double result = 0.0;
//     matrix_t new;
//     matrix_t* p_new = &new;
//     double arr[] = {1,2,3,4,-5,6,7,9,8};
//     s21_create_matrix(3, 3, &new);
//     fill_in_matrix(&new, arr);
//     show_matrix(&new);
//     determinant_3(p_new, &result);
//     printf("result %f", result);
//     return 0;
// }
void determinant_3(matrix_t *A, double *result) {
    *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
              A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
              A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1] -
              A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
              A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1] -
              A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2];
}
