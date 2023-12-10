#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol) {
  Matrix *matrix = (Matrix*) malloc(sizeof(Matrix));
  matrix -> nlin = nlin;
  matrix -> ncol = ncol;
  matrix -> mat = (int**) realloc(matrix -> mat, sizeof(int*) * nlin);

  return matrix;
};

void readMatrix(Matrix *m) {
  fflush(stdin);
  for(int i = 0; i < m -> nlin; i++) {
    int *mcol = (int*) malloc(sizeof(int) * m -> ncol);
    for(int j = 0; j < m -> ncol; j++) {
      scanf("%d", &mcol[j]);
    };

    *(m -> mat + i) = (int*) mcol;
    fflush(stdin);
  };
};

void printMatrix(Matrix *m) {
  for(int i = 0; i < m -> nlin; i++) {
    for(int j = 0; j < m -> ncol; j++) {
      printf("%d ", *(*(m -> mat + i) + j));
    };
    printf("\n");
  };
};

void destroyMatrix(Matrix **m) {
  for(int i = 0; i < (*m) -> nlin; i++) {
    free(*((*m) -> mat + i));
  };
  free((*m) -> mat);
  free(*m);
  *m = NULL;
};

int main() {
  int lin, col;
  Matrix* mat;

  scanf("%i %i", &lin, &col);
  mat = createMatrix(lin, col);
  readMatrix(mat);
  printMatrix(mat);
  destroyMatrix(&mat);
  if (mat == NULL) {
    printf("OK\n");
  }
  return 0;
}