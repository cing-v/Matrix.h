#include "s21_test.h"

// mult 1×1 matrices
START_TEST(s21_mult_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &check);

  Fill_Matrix(&A, 16.0, 1.0);
  Fill_Matrix(&B, 32.1, 1.0);
  Fill_Matrix(&check, 513.6, 1.0);

  s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// mult square matrices
START_TEST(s21_mult_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  Fill_Matrix(&A, 2.5, 1.5);
  Fill_Matrix(&B, 3.0, 1.0);

  s21_mult_matrix(&A, &B, &result);

  double check[3][3] = {
      {81.0, 93.0, 105.0}, {162.0, 187.5, 213.0}, {243.0, 282.0, 321.0}};

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// mult non square matrices
START_TEST(s21_mult_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;

  B.matrix[0][0] = 1, B.matrix[0][1] = -1, B.matrix[0][2] = 1;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;

  s21_mult_matrix(&A, &B, &result);

  double check[3][3] = {
      {9.0, 11.0, 17.0}, {12.0, 13.0, 22.0}, {15.0, 15.0, 27.0}};

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  // -------------------------

  s21_create_matrix(2, 4, &A);
  s21_create_matrix(4, 3, &B);

  Fill_Matrix(&A, 2.0, 2.0);
  Fill_Matrix(&B, -1.0, -1.0);

  s21_mult_matrix(&A, &B, &result);

  double check1[2][3] = {
      {-140.0, -160.0, -180.0},
      {-316.0, -368.0, -420.0},
  };

  for (int row = 0; row < result.rows; row++) {
    for (int col = 0; col < result.columns; col++) {
      ck_assert_double_eq(result.matrix[row][col], check1[row][col]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// wrong matrix
START_TEST(s21_mult_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  // empty matrices
  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &result));

  // non equal matrices
  s21_create_matrix(3, 6, &A);
  s21_create_matrix(5, 5, &B);

  ck_assert_int_eq(CALC_ERR, s21_mult_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_mult_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_mult\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_mult_core");
  tcase_add_test(tc_core, s21_mult_test_1);
  tcase_add_test(tc_core, s21_mult_test_2);
  tcase_add_test(tc_core, s21_mult_test_3);
  tcase_add_test(tc_core, s21_mult_test_4);

  suite_add_tcase(s, tc_core);

  return s;
}
