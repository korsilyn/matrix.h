#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) return 1;

  int status = 0;
  result->matrix =
      malloc(rows * columns * sizeof(double) + rows * (sizeof(double *)));
  double *ptr = (double *)(result->matrix + rows);
  for (int i = 0; i < rows; i++) result->matrix[i] = ptr + columns * i;
  result->rows = rows;
  result->columns = columns;
  if (s21_is_matrix(result))
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) result->matrix[i][j] = 0.0;
  else
    status = 1;

  return status;
}
