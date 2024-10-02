#include "s21_test.h"

// 1×1 matrix inverse
START_TEST(s21_inverse_test_1) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 4.0;

  s21_inverse_matrix(&A, &result);

  ck_assert_double_eq(0.25, result.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// 2×2 matrix inverse
START_TEST(s21_inverse_test_2) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(2, 2, &A);

  Fill_Matrix(&A, 1.0, 1.0);

  double check[2][2] = {{-2.0, 1.0}, {1.5, -0.5}};

  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// 3×3 matrix inverse
START_TEST(s21_inverse_test_3) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2.0, A.matrix[0][1] = 5.0, A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0, A.matrix[1][1] = 3.0, A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0, A.matrix[2][1] = -2.0, A.matrix[2][2] = -3.0;

  double check[3][3] = {
      {1.0, -1.0, 1.0}, {-38.0, 41.0, -34.0}, {27.0, -29.0, 24.0}};

  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// null determinant
START_TEST(s21_inverse_test_4) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  Fill_Matrix(&A, 1.0, 1.0);

  ck_assert_int_eq(CALC_ERR, s21_inverse_matrix(&A, &result));

  s21_remove_matrix(&A);
}
END_TEST

// wrong matrix
START_TEST(s21_inverse_test_5) {
  matrix_t A = {0};
  matrix_t result = {0};

  // empty matrices
  ck_assert_int_eq(MATRIX_ERR, s21_inverse_matrix(&A, &result));

  s21_create_matrix(3, 6, &A);

  // non square matrix
  ck_assert_int_eq(CALC_ERR, s21_inverse_matrix(&A, &result));

  s21_remove_matrix(&A);
}
END_TEST

Suite* s21_inverse_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_inverse\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_inverse_core");
  tcase_add_test(tc_core, s21_inverse_test_1);
  tcase_add_test(tc_core, s21_inverse_test_2);
  tcase_add_test(tc_core, s21_inverse_test_3);
  tcase_add_test(tc_core, s21_inverse_test_4);
  tcase_add_test(tc_core, s21_inverse_test_5);
  suite_add_tcase(s, tc_core);

  return s;
}
