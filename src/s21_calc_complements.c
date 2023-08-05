#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_is_matrix(A)) return 1;
  if (!s21_is_square_matrix(A)) return 2;

  s21_create_matrix(A->columns, A->rows, result);
  if (A->rows == 1)
    result->matrix[0][0] = 1;
  else {
    matrix_t aux = {0};
    s21_create_matrix(A->rows, A->columns, &aux);
    for (int sign = 0, i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_calc_minor(A->matrix, aux.matrix, i, j, A->rows);
        if ((i + j) % 2 == 0)
          sign = 1;
        else
          sign = -1;
        result->matrix[i][j] = sign * s21_calc_determinant(&aux, A->rows - 1);
      }
    }
    s21_remove_matrix(&aux);
  }

  return 0;
}

void s21_calc_minor(double **A, double **aux, int deleteRow, int deleteColumn,
                    int size) {
  for (int row = 0, i = 0; row < size; row++) {
    for (int col = 0, j = 0; col < size; col++) {
      if (row != deleteRow && col != deleteColumn) {
        aux[i][j++] = A[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}
