#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int output = OK;

  if (!result || rows < 1 || columns < 1) {
    return output = MATRIX_ERR;
  }

  if (!output) {
    result->matrix = (double **)calloc(rows * columns + rows, sizeof(double));
  }

  if (result->matrix) {
    // write rows/columns size to the matrix structure
    result->rows = rows;
    result->columns = columns;

    // create pointer's to rows
    for (int i = 0; i < rows; i++) {
      *(result->matrix + i) = (double *)(result->matrix + rows + columns * i);
    }

    // null matrix
    for (int row = 0; row < result->rows; row++) {
      for (int col = 0; col < result->columns; col++) {
        result->matrix[row][col] = 0.0;
      }
    }

  } else {
    // fprintf (stderr, "WRONG MEMORY ALLOCATION!\n");
    output = MATRIX_ERR;
  }

  return output;
}