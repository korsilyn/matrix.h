#include "s21_matrix.h"

int s21_is_matrix(matrix_t *A) {
  return (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0);
}

int s21_is_matrix_equal(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns);
}

int s21_is_square_matrix(matrix_t *A) { return (A->rows == A->columns); }
