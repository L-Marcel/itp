#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int row;
  int columns;
  int** matrix;
} Img;

Img createImg(int r, int c, int matrix[r][c]) {
  Img *img = malloc(sizeof(Img));
  img -> row = r;
  img -> columns = c;
  img -> matrix = calloc(r, sizeof(Img) * c);
  
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      img -> matrix[i] = matrix[i];
    };
  };

  return *img;
};

Img reflects(Img imgIn) {
  Img imgOut = createImg(imgIn.row, imgIn.columns, imgIn.matrix);
  
  for(int i = 0; i < imgIn.row; i++) {
    for(int j = 0; j < imgIn.columns; j++) {
      if(i >= imgIn.row / 2) {
        imgOut.matrix[i][j] = imgIn.matrix[i][j];
      } else {
        imgOut.matrix[i][j] = imgIn.matrix[imgIn.row - i - 1][j];
      };
    };
  };

  return imgOut;
};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);

  int matrix[r][c];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &matrix[i][j]);
    };
    fflush(stdin);
  };

  Img imgIn = createImg(r, c, matrix);
  Img imgOut = reflects(imgIn);

  printf("%d %d\n", r, c);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      //originalmente eram esperados dois espaços
      //mas acho que a saída ficou melhor assim
      printf("%d ", imgOut.matrix[i][j]);
    };
    printf("\n");
  };

  return 0;
};