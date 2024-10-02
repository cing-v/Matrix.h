#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double determinant = 0.0;
  int output = OK;

  // checking matrix
  if (!result || !A || BAD_SIZE(A)) {
    output = MATRIX_ERR;
  }
  // checking matrix size
  if (NOT_SQUARE(A)) {
    output = CALC_ERR;
  }

  // checking determinant matrix
  if (!output) {
    output = s21_determinant(A, &determinant);
    if (!determinant) {
      output = CALC_ERR;
    }
  }

  if (!output) {
    // calculate matrix of algebraic complements
    matrix_t complements = {0};
    output = s21_calc_complements(A, &complements);

    // transpose matrix of algebraic complements
    if (!output) {
      matrix_t transpose = {0};
      output = s21_transpose(&complements, &transpose);

      // inverse matrix
      if (!output) {
        output = s21_mult_number(&transpose, 1 / determinant, result);
      }

      s21_remove_matrix(&transpose);
    }

    s21_remove_matrix(&complements);
  }

  return output;
}
