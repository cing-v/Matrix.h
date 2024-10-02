#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int output = OK;

  // checking matrix
  if (!result || !A || BAD_SIZE(A)) {
    output = MATRIX_ERR;
  }

  // create result matrix
  if (!output) {
    output = s21_create_matrix(A->columns, A->rows, result);
  }

  if (!output) {
    // transpose result matrix
    for (int row = 0; row < result->rows; row++) {
      for (int col = 0; col < result->columns; col++) {
        result->matrix[row][col] = A->matrix[col][row];
      }
    }
  }

  return output;
}