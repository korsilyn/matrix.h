#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_matrix(A) || !s21_is_matrix(B) || !s21_is_matrix_equal(A, B))
    return 0;

  int status = 1;
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) status = 0;

  return status;
}
