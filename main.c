#include "s21_matrix.h"

int main() {
    matrix_t matr;
    s21_create_matrix(3, 3, &matr);
    Fill_Matrix(&matr, 1.0, 1.0);
    Print_Matrix(&matr);
    printf("\n    --- GAUSS ---\n\n");

    Algorithm_Gauss(matr);
    
    s21_remove_matrix(&matr);

    return 0;
}
