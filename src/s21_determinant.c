#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_is_matrix(A)) return 1;
  if (!s21_is_square_matrix(A)) return 2;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    *result = s21_calc_determinant(A, A->rows);

  return 0;
}

double s21_calc_determinant(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t aux = {0};
  double result = 0.0;

  s21_create_matrix(size, size, &aux);
  for (int sign = 1, i = 0; i < size; i++, sign *= (-1)) {
    s21_calc_minor(A->matrix, aux.matrix, 0, i, size);
    result += sign * A->matrix[0][i] * s21_calc_determinant(&aux, size - 1);
  }

  s21_remove_matrix(&aux);

  return result;
}
