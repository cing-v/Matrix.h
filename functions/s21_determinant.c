#include "../s21_matrix.h"

double Algorithm_Laplace(matrix_t *main) {
  double result = 0.0;

  // 1×1 identity matrix
  if (main->rows == 1) {
    result = main->matrix[0][0];

    // n×n identity matrix
  } else {
    int sign = 1;

    // create submatrix
    matrix_t tmp = {0};
    s21_create_matrix(main->rows - 1, main->columns - 1, &tmp);

    // going by the first row of main matrix
    for (int main_col = 0; main_col < main->columns; main_col++) {
      // filling the submatrix
      Fill_Submatrix(main, &tmp, 0, main_col);

      // calculate using a recursive algorithm by Laplace’s theorem
      result += sign * main->matrix[0][main_col] * Algorithm_Laplace(&tmp);
      sign *= -1;
    }

    s21_remove_matrix(&tmp);
  }

  return result;
}

int s21_determinant(matrix_t *A, double *result) {
  int output = OK;

  // checking matrix
  if (!result || !A || BAD_SIZE(A)) {
    output = MATRIX_ERR;
  }

  // checking matrix size
  if (NOT_SQUARE(A)) {
    output = CALC_ERR;
  }

  if (!output) {
    *result = Algorithm_Laplace(A);
  }

  return output;
}
