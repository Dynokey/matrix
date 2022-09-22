#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_
// #include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

/*!
    \brief Структура матрицы согласно задания
*/
typedef struct matrix_struct {
    double **matrix;  ///< Область выделенной памяти
    int rows;         ///< Количество строк
    int columns;      ///< Количество столбцов
} matrix_t;

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result);
// Очистка матриц
void s21_remove_matrix(matrix_t *A);
// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);
// Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
// Умножение матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Транспонирование матриц
int s21_transpose(matrix_t *A, matrix_t *result);
// Определитель матрицы
int s21_determinant(matrix_t *A, double *result);
// Матрица алгребраический дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);
//
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции:
// Заполнение матрицы
void fill_in_matrix(matrix_t *A, double *arr);
// Просмотр матрицы
void show_matrix(matrix_t *A);
// Возвращает матрицу matrix без row-ой строки и col-того столбца
void get_minor(matrix_t *A, int row, int col, matrix_t *result);

void determinant_1(matrix_t *A, double *result);
void determinant_2(matrix_t *A, double *result);
void determinant_3(matrix_t *A, double *result);
void determinant_n(matrix_t *A, double *result);

/*!
Проверка матриц на корректность данных
\param[in] *A Исходная область памяти для проверки
\return 0 если проверка прошла удачно, иначе возвращает 1
*/
int err_matrix(matrix_t *A);
#endif  // SRC_S21_MATRIX_H_
