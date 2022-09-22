#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

// START_TEST(create_1) {
//     matrix_t create_test_1;
//     int return_create_1 = s21_create_matrix(-1, -1, &create_test_1);
//     ck_assert_int_eq(return_create_1, 1);
// }
// END_TEST

// START_TEST(create_2) {
//     matrix_t create_test_2;
//     int return_create_2 = s21_create_matrix(34, -1, &create_test_2);
//     ck_assert_int_eq(return_create_2, 1);
// }
// END_TEST

// START_TEST(create_3) {
//     matrix_t create_test_3;
//     int return_create_3 = s21_create_matrix(0, 0, &create_test_3);
//     ck_assert_int_eq(return_create_3, 1);
// }
// END_TEST

START_TEST(create_4) {
    matrix_t create_test_4;
    int return_create_4 = s21_create_matrix(2, 2, &create_test_4);
    ck_assert_int_eq(return_create_4, 0);
    s21_remove_matrix(&create_test_4);
}
END_TEST

START_TEST(eq_1) {
    matrix_t eq_test_1;
    matrix_t eq_test_2;
    s21_create_matrix(2, 2, &eq_test_1);
    eq_test_1.matrix[0][0] = 1.12345678;
    s21_create_matrix(2, 2, &eq_test_2);
    eq_test_2.matrix[0][0] = 1.12345677;
    int return_eq_1 = s21_eq_matrix(&eq_test_1, &eq_test_2);
    ck_assert_int_eq(return_eq_1, SUCCESS);
    s21_remove_matrix(&eq_test_1);
    s21_remove_matrix(&eq_test_2);
}
END_TEST

START_TEST(eq_2) {
    matrix_t eq_test_2_1;
    matrix_t eq_test_2_2;
    s21_create_matrix(1, 1, &eq_test_2_1);
    eq_test_2_1.matrix[0][0] = 1.123456;
    s21_create_matrix(1, 1, &eq_test_2_2);
    eq_test_2_2.matrix[0][0] = 1.123457;
    int return_eq_2 = s21_eq_matrix(&eq_test_2_1, &eq_test_2_2);
    ck_assert_int_eq(return_eq_2, FAILURE);
    s21_remove_matrix(&eq_test_2_1);
    s21_remove_matrix(&eq_test_2_2);
}
END_TEST

START_TEST(eq_3) {
    matrix_t eq_test_3_1;
    matrix_t eq_test_3_2;
    s21_create_matrix(2, 1, &eq_test_3_1);
    eq_test_3_1.matrix[0][0] = 1.123;
    s21_create_matrix(1, 1, &eq_test_3_2);
    eq_test_3_2.matrix[0][0] = 1.123;
    int return_eq_3 = s21_eq_matrix(&eq_test_3_1, &eq_test_3_2);
    ck_assert_int_eq(return_eq_3, FAILURE);
    s21_remove_matrix(&eq_test_3_1);
    s21_remove_matrix(&eq_test_3_2);
}
END_TEST

START_TEST(eq_4) {
    matrix_t eq_test_4_1;
    matrix_t eq_test_4_2;
    s21_create_matrix(2, 1, &eq_test_4_1);
    int return_eq_4 = s21_eq_matrix(&eq_test_4_1, &eq_test_4_2);
    ck_assert_int_eq(return_eq_4, FAILURE);
    s21_remove_matrix(&eq_test_4_1);
}
END_TEST

START_TEST(sum_1) {
    matrix_t sum_test_1_1;
    s21_create_matrix(5, 3, &sum_test_1_1);
    matrix_t sum_test_1_2;
    s21_create_matrix(5, 3, &sum_test_1_2);
    matrix_t sum_result_1_1;
    matrix_t sum_result_1_2;
    s21_create_matrix(5, 3, &sum_result_1_2);
    double arr_for_sum_1_1[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_for_sum_1_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_for_sum_1_3[] = {-2, -4, -6, -8, -10, -12, -14, -16, -18, -20, -22, -24, -0, -0, -0};
    fill_in_matrix(&sum_test_1_1, arr_for_sum_1_1);
    fill_in_matrix(&sum_test_1_2, arr_for_sum_1_2);
    fill_in_matrix(&sum_result_1_2, arr_for_sum_1_3);
    s21_sum_matrix(&sum_test_1_1, &sum_test_1_2, &sum_result_1_1);
    int return_sum_1 = s21_eq_matrix(&sum_result_1_1, &sum_result_1_2);
    ck_assert_int_eq(return_sum_1, SUCCESS);
    s21_remove_matrix(&sum_test_1_1);
    s21_remove_matrix(&sum_test_1_2);
    s21_remove_matrix(&sum_result_1_1);
    s21_remove_matrix(&sum_result_1_2);
}
END_TEST

START_TEST(sum_2) {
    matrix_t sum_test_2_1;
    s21_create_matrix(5, 3, &sum_test_2_1);
    matrix_t sum_test_2_2;
    s21_create_matrix(5, 3, &sum_test_2_2);
    matrix_t sum_result_2_1;
    matrix_t sum_result_2_2;
    s21_create_matrix(5, 3, &sum_result_2_2);
    double arr_for_sum_2_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_for_sum_2_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_for_sum_2_3[] = {-2, -4, -6, -8, 0.5, -12, -14, -16, -18, -20, -22, -24, -0, -0, -0};
    fill_in_matrix(&sum_test_2_1, arr_for_sum_2_1);
    fill_in_matrix(&sum_test_2_2, arr_for_sum_2_2);
    fill_in_matrix(&sum_result_2_2, arr_for_sum_2_3);
    int return_sum_2 = (s21_sum_matrix(&sum_test_2_1, &sum_test_2_2, &sum_result_2_1) == 0 &&
                        s21_eq_matrix(&sum_result_2_1, &sum_result_2_2));
    ck_assert_int_eq(return_sum_2, 1);
    s21_remove_matrix(&sum_test_2_1);
    s21_remove_matrix(&sum_test_2_2);
    s21_remove_matrix(&sum_result_2_1);
    s21_remove_matrix(&sum_result_2_2);
}
END_TEST

START_TEST(sub_1) {
    matrix_t sub_test_1_1;
    s21_create_matrix(5, 3, &sub_test_1_1);
    matrix_t sub_test_1_2;
    s21_create_matrix(5, 3, &sub_test_1_2);
    matrix_t sub_result_1_1;
    matrix_t sub_result_1_2;
    s21_create_matrix(5, 3, &sub_result_1_2);
    double arr_for_sub_1_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_for_sub_1_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_for_sub_1_3[] = {-0, -0, -0, 0, 10.5, -0, 0, 0, 0, 0, 0, 0, -0, -0, -0};
    fill_in_matrix(&sub_test_1_1, arr_for_sub_1_1);
    fill_in_matrix(&sub_test_1_2, arr_for_sub_1_2);
    fill_in_matrix(&sub_result_1_2, arr_for_sub_1_3);
    s21_sub_matrix(&sub_test_1_1, &sub_test_1_2, &sub_result_1_1);
    int return_sub_1 = s21_eq_matrix(&sub_result_1_1, &sub_result_1_2);
    ck_assert_int_eq(return_sub_1, SUCCESS);
    s21_remove_matrix(&sub_test_1_1);
    s21_remove_matrix(&sub_test_1_2);
    s21_remove_matrix(&sub_result_1_1);
    s21_remove_matrix(&sub_result_1_2);
}
END_TEST

START_TEST(muln_1) {
    matrix_t muln_test_1_1;
    s21_create_matrix(5, 3, &muln_test_1_1);
    double number = 2.0;
    matrix_t res_muln_1_1;
    matrix_t res_muln_1_2;
    s21_create_matrix(5, 3, &res_muln_1_2);
    double arr_for_mull_1_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};

    double arr_for_mull_1_3[] = {-2, -4, -6, -8, 11, -12, -14, -16, -18, -20, -22, -24, -0, -0, -0};
    fill_in_matrix(&muln_test_1_1, arr_for_mull_1_1);
    fill_in_matrix(&res_muln_1_2, arr_for_mull_1_3);
    int ret_muln_1 = (s21_mult_number(&muln_test_1_1, number, &res_muln_1_1) == 0 &&
                      s21_eq_matrix(&res_muln_1_1, &res_muln_1_2) == 1);
    ck_assert_int_eq(ret_muln_1, 1);
    s21_remove_matrix(&muln_test_1_1);
    s21_remove_matrix(&res_muln_1_1);
    s21_remove_matrix(&res_muln_1_2);
}
END_TEST

START_TEST(mul_1) {
    matrix_t mul_test_1_1;
    s21_create_matrix(5, 3, &mul_test_1_1);
    matrix_t mul_test_1_2;
    s21_create_matrix(3, 6, &mul_test_1_2);
    matrix_t res_mul_1_1;
    matrix_t res_mul_1_2;
    s21_create_matrix(5, 6, &res_mul_1_2);
    double arr_mul_1_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_mul_1_2[] = {-1, -2, -3, 4.5, 4.6, 4.7, -4, -5, -6, 6.7, 6.8, 6.9, -7, -8, -9, 1.1, 1.2, 1.3};
    double arr_mul_1_3[] = {30,   36,     42,     -21.2,  -21.8, -22.4, 24,    28.5,  33,  12.25,
                            11.8, 11.35,  102,    126,    150,   -95,   -97.4, -99.8, 138, 171,
                            204,  -131.9, -135.2, -138.5, 0,     0,     0,     0,     0,   0};
    fill_in_matrix(&mul_test_1_1, arr_mul_1_1);
    fill_in_matrix(&mul_test_1_2, arr_mul_1_2);
    fill_in_matrix(&res_mul_1_2, arr_mul_1_3);
    int ret_mul_1 = (s21_mult_matrix(&mul_test_1_1, &mul_test_1_2, &res_mul_1_1) == 0 &&
                     s21_eq_matrix(&res_mul_1_1, &res_mul_1_2) == 1);
    ck_assert_int_eq(ret_mul_1, 1);
    s21_remove_matrix(&mul_test_1_1);
    s21_remove_matrix(&mul_test_1_2);
    s21_remove_matrix(&res_mul_1_1);
    s21_remove_matrix(&res_mul_1_2);
}
END_TEST

START_TEST(mul_2) {
    matrix_t mul_test_4_1;
    s21_create_matrix(1, 3, &mul_test_4_1);
    matrix_t mul_test_4_2;
    s21_create_matrix(2, 1, &mul_test_4_2);
    matrix_t res_mul_4_1;
    matrix_t res_mul_4_2;
    s21_create_matrix(1, 1, &res_mul_4_2);
    double arr_mul_4_1[] = {-1, -2, -3};
    double arr_mul_4_2[] = {4, 5};
    double arr_mul_4_3[] = {-32};
    fill_in_matrix(&mul_test_4_1, arr_mul_4_1);
    fill_in_matrix(&mul_test_4_2, arr_mul_4_2);
    fill_in_matrix(&res_mul_4_2, arr_mul_4_3);
    int ret_mul_4 = (s21_mult_matrix(&mul_test_4_1, &mul_test_4_2, &res_mul_4_1) == 2);
    ck_assert_int_eq(ret_mul_4, 1);
    s21_remove_matrix(&mul_test_4_1);
    s21_remove_matrix(&mul_test_4_2);
    s21_remove_matrix(&res_mul_4_1);
    s21_remove_matrix(&res_mul_4_2);
}
END_TEST

START_TEST(transpose_1) {
    matrix_t transpose_test_1_1;
    s21_create_matrix(5, 3, &transpose_test_1_1);
    matrix_t res_transpose_1_1;
    matrix_t res_transpose_1_2;
    s21_create_matrix(3, 5, &res_transpose_1_2);
    double arr_transpose_1_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_transpose_1_3[] = {-1, -4, -7, -10, 0, -2, 5.5, -8, -11, -0, -3, -6, -9, -12, 0};
    fill_in_matrix(&transpose_test_1_1, arr_transpose_1_1);
    fill_in_matrix(&res_transpose_1_2, arr_transpose_1_3);
    int ret_transpose_1 = (s21_transpose(&transpose_test_1_1, &res_transpose_1_1) == 0 &&
                           s21_eq_matrix(&res_transpose_1_1, &res_transpose_1_2) == 1);
    ck_assert_int_eq(ret_transpose_1, 1);
    s21_remove_matrix(&transpose_test_1_1);
    s21_remove_matrix(&res_transpose_1_1);
    s21_remove_matrix(&res_transpose_1_2);
}
END_TEST

START_TEST(transpose_2) {
    matrix_t transpose_test_2_1;
    s21_create_matrix(5, 3, &transpose_test_2_1);
    matrix_t res_transpose_2_1;
    matrix_t res_transpose_2_2;
    s21_create_matrix(2, 5, &res_transpose_2_2);
    double arr_transpose_2_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    double arr_transpose_2_3[] = {-1, -4, -7, -10, 0, -2, 5.5, -8, -11, -0, -3, -6, -9, -12, 0};
    fill_in_matrix(&transpose_test_2_1, arr_transpose_2_1);
    fill_in_matrix(&res_transpose_2_2, arr_transpose_2_3);
    int ret_transpose_2 = (s21_transpose(&transpose_test_2_1, &res_transpose_2_1) == 0);
    ck_assert_int_eq(ret_transpose_2, 1);
    s21_remove_matrix(&transpose_test_2_1);
    s21_remove_matrix(&res_transpose_2_1);
    s21_remove_matrix(&res_transpose_2_2);
}
END_TEST

START_TEST(det_1) {
    matrix_t det_test_1_1;
    s21_create_matrix(3, 3, &det_test_1_1);
    double result_det_1_1 = 0;
    double result_det_1_2 = -126;
    double arr_det_1_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9};
    fill_in_matrix(&det_test_1_1, arr_det_1_1);
    int ret_det_1 = (s21_determinant(&det_test_1_1, &result_det_1_1) == 0 &&
                     fabs(result_det_1_1 - result_det_1_2) < 0.0000001);
    ck_assert_int_eq(ret_det_1, 1);
    s21_remove_matrix(&det_test_1_1);
}
END_TEST

START_TEST(det_2) {
    matrix_t det_test_2_1;
    s21_create_matrix(4, 3, &det_test_2_1);
    double result_det_2_1 = 3;
    double arr_det_2_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2};
    fill_in_matrix(&det_test_2_1, arr_det_2_1);
    int ret_det_2 = s21_determinant(&det_test_2_1, &result_det_2_1);
    ck_assert_int_eq(ret_det_2, 1);
    s21_remove_matrix(&det_test_2_1);
}
END_TEST

START_TEST(det_3) {
    matrix_t det_test_3_1;
    s21_create_matrix(4, 4, &det_test_3_1);
    double result_det_3_1 = 0;
    double result_det_3_2 = -432.0;
    double arr_det_3_1[] = {1, 2, 3, 4, -5, 6, 7, -8, 9, 1, 2, 3, 4, 5, 6, 7};
    fill_in_matrix(&det_test_3_1, arr_det_3_1);
    int ret_det_3_1 = s21_determinant(&det_test_3_1, &result_det_3_1) == 0;
    int ret_det_3_2 = (fabs(result_det_3_1 - result_det_3_2) < EPS);
    ck_assert_int_eq(ret_det_3_1, 1);
    ck_assert_int_eq(ret_det_3_2, 1);
    s21_remove_matrix(&det_test_3_1);
}
END_TEST

START_TEST(det_4) {
    matrix_t det_test_4_1;
    s21_create_matrix(1, 1, &det_test_4_1);
    double result_det_4_1 = 0;
    double result_det_4_2 = 1;
    double arr_det_4_1[] = {1};
    fill_in_matrix(&det_test_4_1, arr_det_4_1);
    int ret_det_4_1 = s21_determinant(&det_test_4_1, &result_det_4_1);
    int ret_det_4_2 = (fabs(result_det_4_1 - result_det_4_2) < EPS);
    ck_assert_int_eq(ret_det_4_1, 0);
    ck_assert_int_eq(ret_det_4_2, 1);
    s21_remove_matrix(&det_test_4_1);
}
END_TEST

START_TEST(det_5) {
    matrix_t det_test_5_1;
    s21_create_matrix(2, 2, &det_test_5_1);
    double result_det_5_1 = 0;
    double result_det_5_2 = -13;
    double arr_det_5_1[] = {1, 2, 4, -5};
    fill_in_matrix(&det_test_5_1, arr_det_5_1);
    int ret_det_5_1 = s21_determinant(&det_test_5_1, &result_det_5_1);
    int ret_det_5_2 = (fabs(result_det_5_1 - result_det_5_2) < EPS);
    ck_assert_int_eq(ret_det_5_1, 0);
    ck_assert_int_eq(ret_det_5_2, 1);
    s21_remove_matrix(&det_test_5_1);
}
END_TEST

START_TEST(com_1) {
matrix_t com_test_1_1;
s21_create_matrix(3, 3, &com_test_1_1);
matrix_t res_com_1_1;
matrix_t res_com_1_2;
s21_create_matrix(3, 3, &res_com_1_2);
double arr_com_1_1[] = {
    1, 2, 3,
    0, 4, 2,
    5, 2, 1};
double arr_com_1_3[] = {
    0, 10, -20,
    4, -14, 8,
    -8, -2, 4};
fill_in_matrix(&com_test_1_1, arr_com_1_1);
fill_in_matrix(&res_com_1_2, arr_com_1_3);
int ret_com_1 = (s21_calc_complements(&com_test_1_1, &res_com_1_1) == 0
                    && s21_eq_matrix(&res_com_1_1, &res_com_1_2) == 1);
ck_assert_int_eq(ret_com_1, 1);
s21_remove_matrix(&com_test_1_1);
s21_remove_matrix(&res_com_1_1);
s21_remove_matrix(&res_com_1_2);}
END_TEST

START_TEST(com_2) {
matrix_t com_test_2_1;
s21_create_matrix(1, 1, &com_test_2_1);
matrix_t res_com_2_1;
matrix_t res_com_2_2;
s21_create_matrix(1, 1, &res_com_2_2);
double arr_com_2_1[] = {
    1};
double arr_com_2_3[] = {
    1};
fill_in_matrix(&com_test_2_1, arr_com_2_1);
fill_in_matrix(&res_com_2_2, arr_com_2_3);
int ret_com_2 = (s21_calc_complements(&com_test_2_1, &res_com_2_1) == 1);
ck_assert_int_eq(ret_com_2, 1);
s21_remove_matrix(&com_test_2_1);
s21_remove_matrix(&res_com_2_2);}
END_TEST

START_TEST(inv_1) {
matrix_t mat_inv_1_1;
s21_create_matrix(3, 3, &mat_inv_1_1);
matrix_t res_inv_1_1;
matrix_t res_inv_1_2;
s21_create_matrix(3, 3, &res_inv_1_2);
double arr_inv_1_1[] = {
    2, 5, 7,
    6, 3, 4,
    5, -2, -3};
double arr_inv_1_3[] = {
    1, -1, 1,
    -38, 41, -34,
    27, -29, 24};
fill_in_matrix(&mat_inv_1_1, arr_inv_1_1);
fill_in_matrix(&res_inv_1_2, arr_inv_1_3);
int ret_inv_1 = (s21_inverse_matrix(&mat_inv_1_1, &res_inv_1_1) == 0
                    && s21_eq_matrix(&res_inv_1_1, &res_inv_1_2) == 1);
ck_assert_int_eq(ret_inv_1, 1);
s21_remove_matrix(&mat_inv_1_1);
s21_remove_matrix(&res_inv_1_1);
s21_remove_matrix(&res_inv_1_2);}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;
    suite_add_tcase(s1, tc1_1);
    // tcase_add_test(tc1_1, create_1);
    // tcase_add_test(tc1_1, create_2);
    // tcase_add_test(tc1_1, create_3);
    tcase_add_test(tc1_1, create_4);
    tcase_add_test(tc1_1, eq_1);
    tcase_add_test(tc1_1, eq_2);
    tcase_add_test(tc1_1, eq_3);
    tcase_add_test(tc1_1, eq_4);
    tcase_add_test(tc1_1, sum_1);
    tcase_add_test(tc1_1, sum_2);
    tcase_add_test(tc1_1, sub_1);
    tcase_add_test(tc1_1, muln_1);
    tcase_add_test(tc1_1, mul_1);
    tcase_add_test(tc1_1, mul_2);
    tcase_add_test(tc1_1, transpose_1);
    tcase_add_test(tc1_1, transpose_2);
    tcase_add_test(tc1_1, det_1);
    // tcase_add_test(tc1_1, det_2);
    tcase_add_test(tc1_1, det_3);
    tcase_add_test(tc1_1, det_4);
    tcase_add_test(tc1_1, det_5);
    tcase_add_test(tc1_1, com_1);
    // tcase_add_test(tc1_1, com_2);
    tcase_add_test(tc1_1, inv_1);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
