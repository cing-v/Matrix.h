#include "s21_test.h"

// transpose 1×1 matrix
START_TEST(s21_transpose_test_1) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(1, 1, &A);
  Fill_Matrix(&A, 23.0, 1.0);

  s21_transpose(&A, &result);
  ck_assert_double_eq(23.0, result.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// transpose square matrix
START_TEST(s21_transpose_test_2) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  Fill_Matrix(&A, 1.5, 1.5);

  s21_transpose(&A, &result);

  double check[3][3] = {{1.5, 6.0, 10.5}, {3.0, 7.5, 12.0}, {4.5, 9.0, 13.5}};

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// transpose non square matrix
START_TEST(s21_transpose_test_3) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(2, 3, &A);
  Fill_Matrix(&A, 3, 2);

  s21_transpose(&A, &result);

  double check[3][2] = {{3.0, 9.0}, {5.0, 11.0}, {7.0, 13.0}};

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// wrong matrix
START_TEST(s21_transpose_test_4) {
  matrix_t A = {0};
  matrix_t result = {0};

  // empty matrices
  ck_assert_int_eq(MATRIX_ERR, s21_transpose(&A, &result));
}
END_TEST

Suite* s21_transpose_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_transpose\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_transpose_core");
  tcase_add_test(tc_core, s21_transpose_test_1);
  tcase_add_test(tc_core, s21_transpose_test_2);
  tcase_add_test(tc_core, s21_transpose_test_3);
  tcase_add_test(tc_core, s21_transpose_test_4);

  suite_add_tcase(s, tc_core);

  return s;
}
