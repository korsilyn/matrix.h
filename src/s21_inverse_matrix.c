#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_is_matrix(A)) return 1;
  if (!s21_is_square_matrix(A)) return 2;

  double determinant = 0;
  int status = s21_determinant(A, &determinant);
  if (fabs(determinant) < 1e-6 || status != 0) status = 2;

  if (status == 0) {
    matrix_t aux = {0}, aux_t = {0};
    s21_calc_complements(A, &aux);
    s21_transpose(&aux, &aux_t);
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = aux_t.matrix[i][j] / determinant;

    s21_remove_matrix(&aux);
    s21_remove_matrix(&aux_t);
  }

  return status;
}
