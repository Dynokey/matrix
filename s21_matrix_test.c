#include "s21_matrix.h"

#include <check.h>

START_TEST(create_remove_matrix) {
    matrix_t a;
    // ck_assert_uint_eq(s21_create_matrix(0, 15, &a), 1);
    // s21_remove_matrix(&a);
    ck_assert_uint_eq(s21_create_matrix(15, 15, &a), 0);
    s21_remove_matrix(&a);
    ck_assert_uint_eq(s21_create_matrix(15, -4, &a), 1);
    s21_remove_matrix(&a);
    // ck_assert_uint_eq(s21_create_matrix(-7, 0, &a), 1);
    // s21_remove_matrix(&a);
    ck_assert_uint_eq(s21_create_matrix(7, 3, &a), 0);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(eq_matrix_1) {
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

START_TEST(eq_matrix_2) {
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

// START_TEST(sum_matrix) {
//     matrix_t a, b, result_1, result_2;
//     s21_create_matrix(2, 3, &a);
//     s21_create_matrix(2, 3, &b);
//     s21_create_matrix(2, 3, &result_1);
//     double r[2][3] = {{-11.43, 2, 8.444444}, {4, 9, 5.9999}};
//     double A[2][3] = {{1, 2, 3.4444444449687}, {4, 5, 6}};
//     double B[2][3] = {{-12.43, 0, 5}, {-3/7, 4, -0.0001}};
//     for (int k = 0; k < 2; k++) {
//         for (int g = 0; g < 3; g++) {
//             a.matrix[k][g] = A[k][g];
//             b.matrix[k][g] = B[k][g];
//             result_1.matrix[k][g] = r[k][g];
//         }
//     }
//     s21_sum_matrix(&a, &b, &result_2);
//     ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
//     s21_remove_matrix(&a);
//     s21_remove_matrix(&b);
//     s21_remove_matrix(&result_1);
//     s21_remove_matrix(&result_2);
// }
// END_TEST

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

START_TEST(sum_3) {
    matrix_t sum_test_2_1;
    s21_create_matrix(5, 3, &sum_test_2_1);
    matrix_t sum_test_2_2;
    s21_create_matrix(1, 1, &sum_test_2_2);
    matrix_t sum_result_2_1;
    matrix_t sum_result_2_2;
    s21_create_matrix(5, 3, &sum_result_2_2);
    // double arr_for_sum_2_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    // double arr_for_sum_2_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    // double arr_for_sum_2_3[] = {-2, -4, -6, -8, 0.5, -12, -14, -16, -18, -20, -22, -24, -0, -0, -0};
    // fill_in_matrix(&sum_test_2_1, arr_for_sum_2_1);
    // fill_in_matrix(&sum_test_2_2, arr_for_sum_2_2);
    // fill_in_matrix(&sum_result_2_2, arr_for_sum_2_3);
    int return_sum_2 = (s21_sum_matrix(&sum_test_2_1, &sum_test_2_2, &sum_result_2_1));
    ck_assert_int_eq(return_sum_2, 2);
    s21_remove_matrix(&sum_test_2_1);
    s21_remove_matrix(&sum_test_2_2);
    s21_remove_matrix(&sum_result_2_1);
    s21_remove_matrix(&sum_result_2_2);
}
END_TEST

START_TEST(sub_matrix) {
    matrix_t a, b, result_1, result_2;
    s21_create_matrix(2, 3, &a);
    s21_create_matrix(2, 3, &b);
    s21_create_matrix(2, 3, &result_1);
    double r[2][3] = {{13.83, -2.50505, -55}, {88, -556, -0.0059}};
    double A[2][3] = {{1.4, -2, 0}, {88, -123, -0.006}};
    double B[2][3] = {{-12.43, 0.50505, 55}, {-3/71, 433, -0.0001}};
    for (int k = 0; k < 2; k++) {
        for (int g = 0; g < 3; g++) {
            a.matrix[k][g] = A[k][g];
            b.matrix[k][g] = B[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    s21_sub_matrix(&a, &b, &result_2);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(sub_2) {
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

START_TEST(sub_3) {
    matrix_t sub_test_1_1;
    s21_create_matrix(5, 3, &sub_test_1_1);
    matrix_t sub_test_1_2;
    s21_create_matrix(1, 1, &sub_test_1_2);
    matrix_t sub_result_1_1;
    matrix_t sub_result_1_2;
    s21_create_matrix(5, 3, &sub_result_1_2);
    // double arr_for_sub_1_1[] = {-1, -2, -3, -4, 5.5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    // double arr_for_sub_1_2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -0, -0, -0};
    // double arr_for_sub_1_3[] = {-0, -0, -0, 0, 10.5, -0, 0, 0, 0, 0, 0, 0, -0, -0, -0};
    // fill_in_matrix(&sub_test_1_1, arr_for_sub_1_1);
    // fill_in_matrix(&sub_test_1_2, arr_for_sub_1_2);
    // fill_in_matrix(&sub_result_1_2, arr_for_sub_1_3);
    int return_sub_1 = s21_sub_matrix(&sub_test_1_1, &sub_test_1_2, &sub_result_1_1);
    ck_assert_int_eq(return_sub_1, 2);
    s21_remove_matrix(&sub_test_1_1);
    s21_remove_matrix(&sub_test_1_2);
    s21_remove_matrix(&sub_result_1_1);
    s21_remove_matrix(&sub_result_1_2);
}
END_TEST

// START_TEST(sub_sum_matrix) {
//     matrix_t a, b, r;
//     s21_create_matrix(3, 5, &a);
//     s21_create_matrix(5, 3, &b);
//     ck_assert_int_eq(s21_sub_matrix(&a, &b, &r), 2);
//     ck_assert_int_eq(s21_sum_matrix(&a, &b, &r), 2);
//     s21_remove_matrix(&a);
//     s21_remove_matrix(&b);
//     s21_remove_matrix(&r);

//     s21_create_matrix(0, 3, &a);
//     s21_create_matrix(0, 3, &b);
//     ck_assert_int_eq(s21_sub_matrix(&a, &b, &r), 1);
//     ck_assert_int_eq(s21_sum_matrix(&a, &b, &r), 1);
//     s21_remove_matrix(&a);
//     s21_remove_matrix(&b);
//     s21_remove_matrix(&r);

//     s21_create_matrix(0, 3, &a);
//     s21_create_matrix(2, 3, &b);
//     ck_assert_int_eq(s21_sub_matrix(&a, &b, &r), 1);
//     ck_assert_int_eq(s21_sum_matrix(&a, &b, &r), 1);
//     s21_remove_matrix(&a);
//     s21_remove_matrix(&b);
//     s21_remove_matrix(&r);
// }
// END_TEST

START_TEST(mult_num_matrix) {
    matrix_t a, result_1, result_2;
    double num = 10;
    s21_create_matrix(2, 3, &a);
    s21_create_matrix(2, 3, &result_1);
    double r[2][3] = {{14, -20, 0}, {880, -1230, -0.06}};
    double A[2][3] = {{1.4, -2, 0}, {88, -123, -0.006}};
    for (int k = 0; k < 2; k++) {
        for (int g = 0; g < 3; g++) {
            a.matrix[k][g] = A[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_mult_number(&a, num, &result_2);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(mult_matrix_1) {
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

START_TEST(mult_matrix_2) {
    matrix_t a, b, result_1, result_2;
    s21_create_matrix(1, 1, &a);
    s21_create_matrix(1, 4, &b);
    s21_create_matrix(1, 4, &result_1);
    double B[1][4] = {{123.4, -0.1, -3333, 0.1}};
    a.matrix[0][0] = 549;
    double r[1][4] = {{67746.6, -54.9, -1829817, 54.9}};
    for (int k = 0; k < 1; k++) {
        for (int g = 0; g < 4; g++) {
            b.matrix[k][g] = B[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_mult_matrix(&a, &b, &result_2);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(mult_matrix_3) {
    matrix_t a, b, result_1, result_2;
    s21_create_matrix(1, 1, &a);
    s21_create_matrix(1, 1, &b);
    s21_create_matrix(1, 1, &result_1);
    a.matrix[0][0] = 549;
    b.matrix[0][0] = 0.00012;
    result_1.matrix[0][0] = 0.06588;
    int k = s21_mult_matrix(&a, &b, &result_2);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(mults_error) {
    matrix_t a, b, result_1;
    s21_create_matrix(1, 2, &a);
    s21_create_matrix(4, 3, &b);
    int k = s21_mult_matrix(&a, &b, &result_1);
    ck_assert_int_eq(k, 2);
    k = s21_mult_matrix(&a, NULL, &result_1);
    ck_assert_int_eq(k, 1);
    k = s21_mult_number(NULL, 123, &result_1);
    ck_assert_int_eq(k, 1);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
}
END_TEST

START_TEST(transpose_matrix) {
    matrix_t a, result_1, result_2;
    s21_create_matrix(3, 4, &a);
    s21_create_matrix(4, 3, &result_1);
    double A[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
    double r[4][3] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
    for (int k = 0; k < 3; k++) {
        for (int g = 0; g < 4; g++) {
            a.matrix[k][g] = A[k][g];
        }
    }
    for (int k = 0; k < 4; k++) {
        for (int g = 0; g < 3; g++) {
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_transpose(&a, &result_2);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(transpose_error) {
    matrix_t a;
    int k = s21_transpose(NULL, &a);
    ck_assert_int_eq(k, 1);
}
END_TEST

START_TEST(calc_complements_1) {
    matrix_t a, result_1, result_2;
    s21_create_matrix(3, 3, &a);
    s21_create_matrix(3, 3, &result_1);
    double A[3][3] = {{1, 22, 333}, {-0.1, 5.5, 0}, {123, 9, 5.5}};
    double r[3][3] = {{30.25, 0.55, -677.4}, {2876, -40953.5, 2697}, {-1831.5, -33.3, 7.7}};
    for (int k = 0; k < 3; k++) {
        for (int g = 0; g < 3; g++) {
            a.matrix[k][g] = A[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_calc_complements(&a, &result_2);
    double det = 0;
    int d = s21_determinant(&a, &det);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(d, 0);
    ck_assert_double_eq_tol(det,  -4510637.0 / 20.0, 1e-6);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(calc_complements_2) {
    matrix_t a, result_1, result_2;
    s21_create_matrix(2, 2, &a);
    s21_create_matrix(2, 2, &result_1);
    double A[2][2] = {{1, 2}, {3, 4}};
    double r[2][2] = {{4, -3}, {-2, 1}};
    for (int k = 0; k < 2; k++) {
        for (int g = 0; g < 2; g++) {
            a.matrix[k][g] = A[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_calc_complements(&a, &result_2);
    double det = 0;
    int d = s21_determinant(&a, &det);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(d, 0);
    ck_assert_double_eq_tol(det,  -2, 1e-6);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(calc_complements_3) {
    matrix_t a, result_1, result_2;
    s21_create_matrix(4, 4, &a);
    s21_create_matrix(4, 4, &result_1);
    double A[4][4] = {{9, -2222, 0, 1000}, {6, 5, 467, 3}, {12, 23, 34, 45}, {-1, 2, 3, -4}};
    double r[4][4] = {{83642, 15, -936, -21605}, {-603162, 67561, -38696, 155549}, \
                    {3251694, -468107, -29896, -1069399}, {57039686, -5211783, -599352, -12093939}};
    for (int k = 0; k < 4; k++) {
        for (int g = 0; g < 4; g++) {
            a.matrix[k][g] = A[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_calc_complements(&a, &result_2);
    double det = 0;
    int d = s21_determinant(&a, &det);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(d, 0);
    ck_assert_double_eq_tol(det, -20885552.0, 1e-6);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(calc_complements_error) {
    matrix_t a;
    int k = s21_calc_complements(NULL, &a);
    ck_assert_int_eq(k, 1);
    matrix_t b;
    s21_create_matrix(2, 3, &b);
    k = s21_calc_complements(&b, &a);
    ck_assert_int_eq(k, 2);
    s21_remove_matrix(&b);
}
END_TEST

START_TEST(determinant) {
    matrix_t a;
    double result;
    s21_create_matrix(4, 4, &a);
    double A[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    for (int k = 0; k < 4; k++) {
        for (int g = 0; g < 4; g++) {
            a.matrix[k][g] = A[k][g];
        }
    }
    int d = s21_determinant(&a, &result);
    ck_assert_int_eq(d, 0);
    ck_assert_double_eq_tol(result, 0, 1e-6);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_error) {
    matrix_t a;
    double result;
    int k = s21_determinant(NULL, &result);
    ck_assert_int_eq(k, 1);
    s21_create_matrix(4, 3, &a);
    k = s21_determinant(&a, NULL);
    ck_assert_int_eq(k, 1);
    k = s21_determinant(&a, &result);
    ck_assert_int_eq(k, 2);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_1) {
    matrix_t a, result_1, result_2;
    s21_create_matrix(2, 2, &a);
    s21_create_matrix(2, 2, &result_1);
    double A[2][2] = {{100, -54.45}, {411, 0}};
    double r[2][2] = {{0, 1.0 / 411.0}, {-20.0 / 1089.0, 2000.0 / 447579.0}};
    for (int k = 0; k < 2; k++) {
        for (int g = 0; g < 2; g++) {
            a.matrix[k][g] = A[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_inverse_matrix(&a, &result_2);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(inverse_2) {
    matrix_t a, result_1, result_2;
    double l = 11121;
    s21_create_matrix(3, 3, &a);
    s21_create_matrix(3, 3, &result_1);
    double A[3][3] = {{1, 2, 3}, {4, 5, 6}, {1234, 5678, -999}};
    double r[3][3] = {{-13021.0 / l, 6344.0 / l, -1.0 / l}, {3800.0 / l, -1567 / l, 2.0 / l}, \
                    {1838.0 / 3707.0, -1070.0 / l, -1.0 / l}};
    for (int k = 0; k < 3; k++) {
        for (int g = 0; g < 3; g++) {
            a.matrix[k][g] = A[k][g];
            result_1.matrix[k][g] = r[k][g];
        }
    }
    int k = s21_inverse_matrix(&a, &result_2);
    ck_assert_int_eq(k, 0);
    ck_assert_int_eq(s21_eq_matrix(&result_1, &result_2), SUCCESS);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result_1);
    s21_remove_matrix(&result_2);
}
END_TEST

START_TEST(inverse_error) {
    matrix_t a, result;
    s21_create_matrix(3, 3, &a);
    double A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int k = 0; k < 3; k++) {
        for (int g = 0; g < 3; g++) {
            a.matrix[k][g] = A[k][g];
        }
    }
    int k = s21_inverse_matrix(&a, &result);
    ck_assert_int_eq(k, 2);
    k = s21_inverse_matrix(NULL, &result);
    ck_assert_int_eq(k, 1);
    k = s21_inverse_matrix(&a, NULL);
    ck_assert_int_eq(k, 1);
    s21_remove_matrix(&a);
}
END_TEST

Suite *s21_matrix_suite(void) {
    Suite *suite;

    suite = suite_create("s21_matrix");
    TCase *tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, create_remove_matrix);
    tcase_add_test(tcase_core, eq_matrix_1);
    tcase_add_test(tcase_core, eq_matrix_2);
    // // tcase_add_test(tcase_core, sum_matrix);
    tcase_add_test(tcase_core, sum_1);
    tcase_add_test(tcase_core, sum_2);
    tcase_add_test(tcase_core, sum_3);
    tcase_add_test(tcase_core, sub_2);
    tcase_add_test(tcase_core, sub_3);
    tcase_add_test(tcase_core, sub_matrix);
    // // tcase_add_test(tcase_core, sub_sum_matrix);
    tcase_add_test(tcase_core, mult_num_matrix);
    tcase_add_test(tcase_core, mult_matrix_1);
    tcase_add_test(tcase_core, mult_matrix_2);
    tcase_add_test(tcase_core, mult_matrix_3);
    // tcase_add_test(tcase_core, mults_error);
    tcase_add_test(tcase_core, transpose_matrix);
    tcase_add_test(tcase_core, transpose_error);
    tcase_add_test(tcase_core, calc_complements_1);
    tcase_add_test(tcase_core, calc_complements_2);
    tcase_add_test(tcase_core, calc_complements_3);
    tcase_add_test(tcase_core, calc_complements_error);
    tcase_add_test(tcase_core, determinant);
    tcase_add_test(tcase_core, determinant_error);
    tcase_add_test(tcase_core, inverse_1);
    tcase_add_test(tcase_core, inverse_2);
    tcase_add_test(tcase_core, inverse_error);

    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main(void) {
    Suite *suite = s21_matrix_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_VERBOSE);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
