#include "s21_test.h"

// sum 1×1 matrices
START_TEST(s21_sum_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &check);

  Fill_Matrix(&A, 3.25, 1.0);
  Fill_Matrix(&B, 7.75, 1.0);
  Fill_Matrix(&check, 11.00, 1.0);

  s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// sum square matrices
START_TEST(s21_sum_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);

  Fill_Matrix(&A, 5.12, 2.0);
  Fill_Matrix(&B, 4.88, 2.0);
  Fill_Matrix(&check, 10.00, 4.0);

  s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// sum square matrices
START_TEST(s21_sum_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &check);

  Fill_Matrix(&A, 12.08, 2.0);
  Fill_Matrix(&B, -5.05, 2.0);
  Fill_Matrix(&check, 7.03, 4.0);

  s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// wrong matrix
START_TEST(s21_sum_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  // empty matrices
  ck_assert_int_eq(MATRIX_ERR, s21_sum_matrix(&A, &B, &result));

  // non equal matrices
  s21_create_matrix(3, 6, &A);
  s21_create_matrix(5, 5, &B);

  ck_assert_int_eq(CALC_ERR, s21_sum_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_sum_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_sum\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_sum_core");
  tcase_add_test(tc_core, s21_sum_test_1);
  tcase_add_test(tc_core, s21_sum_test_2);
  tcase_add_test(tc_core, s21_sum_test_3);
  tcase_add_test(tc_core, s21_sum_test_4);

  suite_add_tcase(s, tc_core);

  return s;
}
