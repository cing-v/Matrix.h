#include "s21_test.h"

// 1×1 matrix determinant
START_TEST(s21_determinant_test_1) {
  matrix_t A = {0};
  double determinant = 0.0;

  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 23.0;

  ck_assert_int_eq(OK, s21_determinant(&A, &determinant));
  ck_assert_double_eq(23.0, determinant);

  s21_remove_matrix(&A);
}
END_TEST

// 2×2 matrix determinant
START_TEST(s21_determinant_test_2) {
  matrix_t A = {0};
  double determinant = 0.0;

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = -2.0, A.matrix[0][1] = 3.0;
  A.matrix[1][0] = -4.0, A.matrix[1][1] = 5.0;

  ck_assert_int_eq(OK, s21_determinant(&A, &determinant));
  ck_assert_double_eq(2.0, determinant);

  s21_remove_matrix(&A);
}
END_TEST

// 3×3 matrix determinant
START_TEST(s21_determinant_test_3) {
  matrix_t A = {0};
  double determinant = 0.0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 3.0, A.matrix[0][1] = 6.0, A.matrix[0][2] = 4.0;
  A.matrix[1][0] = -6.0, A.matrix[1][1] = 2.0, A.matrix[1][2] = 12.0;
  A.matrix[2][0] = 8.0, A.matrix[2][1] = -1.0, A.matrix[2][2] = 14.0;

  ck_assert_int_eq(OK, s21_determinant(&A, &determinant));
  ck_assert_double_eq(1160.0, determinant);

  s21_remove_matrix(&A);
}
END_TEST

// 4×4 matrix determinant
START_TEST(s21_determinant_test_4) {
  matrix_t A = {0};
  double determinant = 0.0;

  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = -1.0, A.matrix[0][1] = 1.0;
  A.matrix[0][2] = 2.0, A.matrix[0][3] = 0.0;

  A.matrix[1][0] = 0.0, A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 1.0, A.matrix[1][3] = -2.0;

  A.matrix[2][0] = 1.0, A.matrix[2][1] = -3.0;
  A.matrix[2][2] = -1.0, A.matrix[2][3] = 0.0;

  A.matrix[3][0] = 5.0, A.matrix[3][1] = 0.0;
  A.matrix[3][2] = 0.0, A.matrix[3][3] = 4.0;

  ck_assert_int_eq(OK, s21_determinant(&A, &determinant));
  ck_assert_double_eq(-74.0, determinant);

  s21_remove_matrix(&A);
}
END_TEST

// 5×5 matrix determinant
START_TEST(s21_determinant_test_5) {
  matrix_t A = {0};
  double determinant = 0.0;

  s21_create_matrix(5, 5, &A);

  Fill_Matrix(&A, 1.0, 2.0);

  ck_assert_int_eq(OK, s21_determinant(&A, &determinant));
  ck_assert_double_eq(0.0, determinant);

  s21_remove_matrix(&A);
}
END_TEST

// wrong matrix
START_TEST(s21_determinant_test_6) {
  matrix_t A = {0};
  double determinant = 0.0;

  // empty matrix
  ck_assert_int_eq(MATRIX_ERR, s21_determinant(&A, &determinant));

  s21_create_matrix(3, 6, &A);

  // non square matrix
  ck_assert_int_eq(CALC_ERR, s21_determinant(&A, &determinant));

  s21_remove_matrix(&A);
}
END_TEST

Suite* s21_determinant_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_determinant\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_determinant_core");
  tcase_add_test(tc_core, s21_determinant_test_1);
  tcase_add_test(tc_core, s21_determinant_test_2);
  tcase_add_test(tc_core, s21_determinant_test_3);
  tcase_add_test(tc_core, s21_determinant_test_4);
  tcase_add_test(tc_core, s21_determinant_test_5);
  tcase_add_test(tc_core, s21_determinant_test_6);

  suite_add_tcase(s, tc_core);

  return s;
}
