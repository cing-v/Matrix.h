#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define MATRIX_ERR 1
#define CALC_ERR 2

#define BAD_SIZE(A) (A->rows < 1 || A->columns < 1)
#define NOT_SQUARE(A) (A->rows != A->columns)
#define SIZE_NOT_EQUAL(A, B) (A->rows != B->rows || A->columns != B->columns)
#define IS_ELEMENT_EQUAL(A, B) \
  (fabs(A->matrix[row][col] - B->matrix[row][col]) < 0.0000001)

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// -------- common functions ----------

void Print_Matrix(matrix_t *result);
double Algorithm_Gauss(matrix_t main);

void Fill_Matrix(matrix_t *result, double start, double step);
void Random_Fill_Matrix(matrix_t *result, double min, double max);
void Fill_Submatrix(matrix_t *main, matrix_t *tmp, int elem_row, int elem_col);

#endif
