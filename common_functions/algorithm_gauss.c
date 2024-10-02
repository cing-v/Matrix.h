#include "../s21_matrix.h"

double Algorithm_Gauss(matrix_t main) {
  double multiplier = 0.0;
  double result = 1.0;

  // reduce the matrix to triangular form
  for (int i = 0; i < main.columns - 1; i++) {
    for (int row = main.rows - 1; row > i; row--) {
      // multiplier = (main.matrix[row][i] / main.matrix[i][i]);
      multiplier = main.matrix[row][i];
      for (int col = 0; col < main.columns; col++) {
        // main.matrix[row][col] -= main.matrix[i][col] * multiplier;
        main.matrix[row][col] = main.matrix[row][col] * main.matrix[i][i] - main.matrix[i][col] * multiplier;
      }
      Print_Matrix(&main);
      printf("\n");
    }
  }

  // Print_Matrix(&main);
  // printf("\n");

  // multiply the elements of the main diagonal
  for (int i = 0; i < main.rows; i++) {
    result *= main.matrix[i][i];
  }

  return result;
}
