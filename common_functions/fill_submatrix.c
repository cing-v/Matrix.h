#include "../s21_matrix.h"

void Fill_Submatrix(matrix_t *main, matrix_t *tmp, int elem_row, int elem_col) {
  // going by the rows of submatrix
  for (int row = 0, tmp_row = 0; row < main->rows; row++) {
    if (row != elem_row) {
      // going by the columns of submatrix
      for (int col = 0, tmp_col = 0; col < main->columns; col++) {
        if (col != elem_col) {
          tmp->matrix[tmp_row][tmp_col] = main->matrix[row][col];
          tmp_col++;
        }
      }
      tmp_row++;
    }
  }
}