#include "../s21_matrix.h"

double randf(double min, double max) {
  double rnd_num = 0.0;

  // convert int to doble
  rnd_num = (double)rand() / RAND_MAX;

  // limit (put between min & max)
  rnd_num = rnd_num * (max - min) + min;

  // round to the nearest hundredth
  rnd_num = round(rnd_num * 100.00) / 100;

  return rnd_num;
}

void Random_Fill_Matrix(matrix_t *result, double min, double max) {
  srand(time(NULL));

  // filling the matrix
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      // put random number to matrix
      result->matrix[i][j] = randf(min, max);
    }
  }
}