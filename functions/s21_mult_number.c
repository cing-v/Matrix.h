#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int output = OK;

  // checking matrix
  if (!result || !A || BAD_SIZE(A)) {
    output = MATRIX_ERR;
  }

  // create result matrix
  if (!output) {
    output = s21_create_matrix(A->rows, A->columns, result);
  }

  if (!output) {
    // multiply the matrix by the number
    for (int row = 0; row < result->rows; row++) {
      for (int col = 0; col < result->columns; col++) {
        result->matrix[row][col] = A->matrix[row][col] * number;
      }
    }
  }

  return output;
}