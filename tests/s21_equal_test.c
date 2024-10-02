#include "s21_test.h"

matrix_t A = {0};
matrix_t B = {0};

// equal 1×1 matrices
START_TEST(s21_equal_test_1) {
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  Fill_Matrix(&A, 5.0, 1.0);
  Fill_Matrix(&B, 5.0, 1.0);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// equal square matrices
START_TEST(s21_equal_test_2) {
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  Fill_Matrix(&A, 1.0, 2.0);
  Fill_Matrix(&B, 1.0, 2.0);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  // -------------------------
  s21_create_matrix(7, 7, &A);
  s21_create_matrix(7, 7, &B);

  Fill_Matrix(&A, -7.0, -2.5);
  Fill_Matrix(&B, -7.0, -2.5);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// equal row matrix
START_TEST(s21_equal_test_3) {
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 3, &B);

  Fill_Matrix(&A, -12.75, 1.5);
  Fill_Matrix(&B, -12.75, 1.5);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  // -------------------------
  s21_create_matrix(1, 9, &A);
  s21_create_matrix(1, 9, &B);

  Fill_Matrix(&A, 2.75, -5.25);
  Fill_Matrix(&B, 2.75, -5.25);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// equal column matrix
START_TEST(s21_equal_test_4) {
  s21_create_matrix(4, 1, &A);
  s21_create_matrix(4, 1, &B);

  Fill_Matrix(&A, 3.70, 1.1);
  Fill_Matrix(&B, 3.70, 1.1);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  // -------------------------
  s21_create_matrix(7, 1, &A);
  s21_create_matrix(7, 1, &B);

  Fill_Matrix(&A, -9.75, -4.25);
  Fill_Matrix(&B, -9.75, -4.25);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// not equal 1×1 matrices
START_TEST(s21_equal_test_5) {
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 7;

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// not equal square matrices
START_TEST(s21_equal_test_6) {
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  Fill_Matrix(&A, -2.75, 3.05);
  Fill_Matrix(&B, 7.88, -2.12);

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  // -------------------------
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);

  Fill_Matrix(&A, 6.33, 1.02);
  Fill_Matrix(&B, 1.38, -7.12);

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// wrong matrix
START_TEST(s21_equal_test_7) {
  matrix_t C = {0};
  matrix_t D = {0};

  // empty matrices
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&C, &D));

  // non equal matrices
  s21_create_matrix(2, 5, &C);
  s21_create_matrix(1, 3, &D);

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&C, &D));

  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

Suite* s21_equal_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_equal\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_equal_core");
  tcase_add_test(tc_core, s21_equal_test_1);
  tcase_add_test(tc_core, s21_equal_test_2);
  tcase_add_test(tc_core, s21_equal_test_3);
  tcase_add_test(tc_core, s21_equal_test_4);
  tcase_add_test(tc_core, s21_equal_test_5);
  tcase_add_test(tc_core, s21_equal_test_6);
  tcase_add_test(tc_core, s21_equal_test_7);

  suite_add_tcase(s, tc_core);

  return s;
}
