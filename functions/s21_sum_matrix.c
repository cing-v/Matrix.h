#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = OK;

  // checking matrices
  if (!result || !A || !B || BAD_SIZE(A) || BAD_SIZE(B)) {
    output = MATRIX_ERR;
  }

  // checking rows and columns of matrices
  if (SIZE_NOT_EQUAL(A, B)) {
    output = CALC_ERR;
  }

  // create result matrix
  if (!output) {
    output = s21_create_matrix(A->rows, A->columns, result);
  }

  if (!output) {
    // perform matrix addition
    for (int row = 0; row < result->rows; row++) {
      for (int col = 0; col < result->columns; col++) {
        result->matrix[row][col] = A->matrix[row][col] + B->matrix[row][col];
      }
    }
  }

  return output;
}