#include "s21_test.h"

// sub 1×1 matrices
START_TEST(s21_sub_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &check);

  Fill_Matrix(&A, 16.78, 1.0);
  Fill_Matrix(&B, 3.21, 1.0);
  Fill_Matrix(&check, 13.57, 1.0);

  s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// sub square matrices
START_TEST(s21_sub_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);

  Fill_Matrix(&A, 23.12, 3.0);
  Fill_Matrix(&B, 12.11, 3.0);
  Fill_Matrix(&check, 11.01, 0.0);

  s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// sub non square matrices
START_TEST(s21_sub_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(5, 3, &A);
  s21_create_matrix(5, 3, &B);
  s21_create_matrix(5, 3, &check);

  Fill_Matrix(&A, -2.07, 5.0);
  Fill_Matrix(&B, -17.07, 5.0);
  Fill_Matrix(&check, 15.00, 0.0);

  s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// wrong matrix
START_TEST(s21_sub_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  // empty matrices
  ck_assert_int_eq(MATRIX_ERR, s21_sub_matrix(&A, &B, &result));

  // non equal matrices
  s21_create_matrix(3, 6, &A);
  s21_create_matrix(5, 5, &B);

  ck_assert_int_eq(CALC_ERR, s21_sub_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_sub_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_sub\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_sub_core");
  tcase_add_test(tc_core, s21_sub_test_1);
  tcase_add_test(tc_core, s21_sub_test_2);
  tcase_add_test(tc_core, s21_sub_test_3);
  tcase_add_test(tc_core, s21_sub_test_4);

  suite_add_tcase(s, tc_core);

  return s;
}
