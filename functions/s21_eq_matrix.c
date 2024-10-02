#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int output = SUCCESS;

  // checking matrices
  if (!A || !B || BAD_SIZE(A) || BAD_SIZE(B)) {
    output = FAILURE;
  }
  // checking size of matrices
  if (SIZE_NOT_EQUAL(A, B)) {
    output = FAILURE;
  }

  // element-by-element check cycle
  for (int row = 0; row < A->rows && output; row++) {
    for (int col = 0; col < A->columns && output; col++) {
      output = IS_ELEMENT_EQUAL(A, B) ? SUCCESS : FAILURE;
    }
  }

  return output;
}