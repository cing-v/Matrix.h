#include "s21_test.h"

// mult 1×1 matrices
START_TEST(s21_mult_number_test_1) {
  matrix_t A = {0};
  matrix_t result = {0};
  double multiplier = 7.0;

  s21_create_matrix(1, 1, &A);
  Fill_Matrix(&A, 7.0, 1.0);

  s21_mult_number(&A, multiplier, &result);
  ck_assert_double_eq(49.0, result.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// mult square matrices
START_TEST(s21_mult_number_test_2) {
  matrix_t A = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  double multiplier = 6.0;

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &check);

  Fill_Matrix(&A, 2.0, 1.0);
  Fill_Matrix(&check, 12.00, 6.0);

  s21_mult_number(&A, multiplier, &result);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// mult non square matrices
START_TEST(s21_mult_number_test_3) {
  matrix_t A = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  double multiplier = -3.0;

  s21_create_matrix(3, 5, &A);
  s21_create_matrix(3, 5, &check);

  Fill_Matrix(&A, 0.0, -0.5);
  Fill_Matrix(&check, 0.00, 1.5);

  s21_mult_number(&A, multiplier, &result);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// wrong matrix
START_TEST(s21_mult_number_test_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  double multiplier = 7.0;

  // empty matrices
  ck_assert_int_eq(MATRIX_ERR, s21_mult_number(&A, multiplier, &result));
}
END_TEST

Suite* s21_mult_number_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_mult_number\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_mult_number_core");
  tcase_add_test(tc_core, s21_mult_number_test_1);
  tcase_add_test(tc_core, s21_mult_number_test_2);
  tcase_add_test(tc_core, s21_mult_number_test_3);
  tcase_add_test(tc_core, s21_mult_number_test_4);

  suite_add_tcase(s, tc_core);

  return s;
}
