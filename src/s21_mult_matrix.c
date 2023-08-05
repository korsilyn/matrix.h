#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_matrix(A) || !s21_is_matrix(B)) return 1;
  if (A->columns != B->rows) return 2;

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < B->rows; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];

  return 0;
}
