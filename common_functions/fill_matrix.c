#include "../s21_matrix.h"

void Fill_Matrix(matrix_t *result, double start, double step) {
  // filling the matrix
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = start;
      start += step;
    }
  }
}