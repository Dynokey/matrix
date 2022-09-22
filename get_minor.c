#include "s21_matrix.h"

// int main() {
//     int a = 3;
//     int b = 3;
//     double arr[] = {1, 2, 3, 4, -5, 6, 7, -8, 9};
//     matrix_t name, result;
//     s21_create_matrix(a, b, &name);
//     s21_create_matrix(a - 1, b - 1, &result);
//     fill_in_matrix(&name, arr);
//     minor(&name, a, 0, 0, &result);
//     show_matrix(&name);
//     show_matrix(&result);

//     return 0;
// }

void get_minor(matrix_t *name, int row, int col, matrix_t *result) {
    int offsetRow = 0;  // Смещение индекса строки в матрице
    int offsetCol = 0;  // Смещение индекса столбца в матрице
    for (int i = 0; i < name->rows - 1; i++) {
        // Пропустить row-ую строку
        if (i == row) {
            offsetRow = 1;  // Как только встретили строку, которую надо пропустить, делаем смещение для
                            // исходной матрицы
        }
        offsetCol = 0;  // Обнулить смещение столбца
        for (int j = 0; j < name->rows - 1; j++) {
            // Пропустить col-ый столбец
            if (j == col) {
                offsetCol = 1;  // Встретили нужный столбец, проускаем его смещением
            }
            result->matrix[i][j] = name->matrix[i + offsetRow][j + offsetCol];
        }
    }
}
