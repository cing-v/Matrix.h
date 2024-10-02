#include "s21_test.h"

// simple matrix
START_TEST(s21_create_test_1) {
  matrix_t main = {0};

  ck_assert_int_eq(OK, s21_create_matrix(1, 1, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(OK, s21_create_matrix(2, 2, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(OK, s21_create_matrix(3, 3, &main));
  s21_remove_matrix(&main);
}
END_TEST

// row matrix
START_TEST(s21_create_test_2) {
  matrix_t main = {0};

  ck_assert_int_eq(OK, s21_create_matrix(1, 3, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(OK, s21_create_matrix(1, 5, &main));
  s21_remove_matrix(&main);
}
END_TEST

// column matrix
START_TEST(s21_create_test_3) {
  matrix_t main = {0};

  ck_assert_int_eq(OK, s21_create_matrix(4, 1, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(OK, s21_create_matrix(7, 1, &main));
  s21_remove_matrix(&main);
}
END_TEST

// not square matrix
START_TEST(s21_create_test_4) {
  matrix_t main = {0};

  ck_assert_int_eq(OK, s21_create_matrix(2, 3, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(OK, s21_create_matrix(4, 2, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(OK, s21_create_matrix(3, 6, &main));
  s21_remove_matrix(&main);
}
END_TEST

// wrong matrix
START_TEST(s21_create_test_5) {
  matrix_t main = {0};

  ck_assert_int_eq(MATRIX_ERR, s21_create_matrix(0, 0, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(MATRIX_ERR, s21_create_matrix(0, 3, &main));
  s21_remove_matrix(&main);

  ck_assert_int_eq(MATRIX_ERR, s21_create_matrix(3, 0, &main));
  s21_remove_matrix(&main);
}
END_TEST

// null matrix
START_TEST(s21_create_test_6) {
  matrix_t* main = NULL;

  ck_assert_int_eq(MATRIX_ERR, s21_create_matrix(2, 2, main));
  s21_remove_matrix(main);
}
END_TEST

Suite* s21_create_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_create\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_create_core");
  tcase_add_test(tc_core, s21_create_test_1);
  tcase_add_test(tc_core, s21_create_test_2);
  tcase_add_test(tc_core, s21_create_test_3);
  tcase_add_test(tc_core, s21_create_test_4);
  tcase_add_test(tc_core, s21_create_test_5);
  tcase_add_test(tc_core, s21_create_test_6);

  suite_add_tcase(s, tc_core);

  return s;
}
