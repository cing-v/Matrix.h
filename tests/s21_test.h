#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>

#include "../s21_matrix.h"

#define TRUE 1
#define FALSE 0

Suite* s21_create_suite(void);
Suite* s21_equal_suite(void);
Suite* s21_sum_suite(void);
Suite* s21_sub_suite(void);
Suite* s21_mult_suite(void);
Suite* s21_mult_number_suite(void);
Suite* s21_transpose_suite(void);
Suite* s21_determinant_suite(void);
Suite* s21_calc_complements_suite(void);
Suite* s21_inverse_suite(void);

#endif