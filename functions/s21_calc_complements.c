#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int output = OK;

  // checking matrix
  if (!result || !A || BAD_SIZE(A)) {
    output = MATRIX_ERR;
  }
  // checking matrix size
  if (NOT_SQUARE(A)) {
    output = CALC_ERR;
  }

  // create result matrix
  if (!output) {
    output = s21_create_matrix(A->rows, A->columns, result);
  }

  if (!output) {
    // 1×1 identity matrix
    if (result->rows == 1.0) {
      result->matrix[0][0] = 1.0;
    } else {
      matrix_t tmp = {0};
      output = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);

      double determinant = 0.0;

      // going by the element's of main matrix
      for (int row = 0; row < result->rows && !output; row++) {
        for (int col = 0; col < result->columns && !output; col++) {
          // filling the submatrix
          Fill_Submatrix(A, &tmp, row, col);

          // calculate minor (determinant of submatrix)
          output = s21_determinant(&tmp, &determinant);

          // calculate algebraic complement
          // (minor multiplied by a factor -1^(i+j))
          result->matrix[row][col] = pow(-1, row + col) * determinant;
        }
      }
      s21_remove_matrix(&tmp);
    }
  }

  return output;
}