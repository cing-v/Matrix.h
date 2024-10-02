#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  // check for null pointer
  if (A) {
    A->rows = 0;
    A->columns = 0;

    // check for allocated memory
    if (A->matrix) {
      free(A->matrix);
    }
  }
}