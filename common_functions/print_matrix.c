#include "../s21_matrix.h"

void Print_Matrix(matrix_t *result) {
  // printing the matrix
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      printf("%6.2lf ", result->matrix[i][j]);
    }
    printf("\n");
  }
}