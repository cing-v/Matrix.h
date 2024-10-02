#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = OK;

  // checking matrices
  if (!result || !A || !B || BAD_SIZE(A) || BAD_SIZE(B)) {
    output = MATRIX_ERR;
  }

  // checking rows and columns of matrices
  if (A->columns != B->rows) {
    output = CALC_ERR;
  }

  // create result matrix
  if (!output) {
    output = s21_create_matrix(A->rows, B->columns, result);
  }

  if (!output) {
    // result matrix element-by-element calculate cycle
    for (int row = 0; row < result->rows; row++) {
      for (int col = 0; col < result->columns; col++) {
        // countig one element of result matrix
        for (int i = 0; i < A->columns; i++) {
          result->matrix[row][col] += A->matrix[row][i] * B->matrix[i][col];
        }
      }
    }
  }

  return output;
}