#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_matrix(A) || !s21_is_matrix(B)) return 1;
  if (!s21_is_matrix_equal(A, B)) return 2;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];

  return 0;
}
