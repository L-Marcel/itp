#include <stdio.h>

void populate(int rows, int columns, int vector[rows][columns]) {
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      scanf("%d", &vector[r][c]);
      fflush(stdin);
    };
  };
};

int maxInColumn(int rows, int columns, int column, int vector[rows][columns]) {
  int max = vector[0][column];

  for(int r = 0; r < rows; r++) {
    if(vector[r][column] >= max) {
      max = vector[r][column];
    };
  };

  return max;
};

int maxInRow(int rows, int columns, int row, int vector[rows][columns]) {
  int max = vector[row][0];

  for(int c = 0; c < columns; c++) {
    if(vector[row][c] >= max) {
      max = vector[row][c];
    };
  };

  return max;
};

int main() {
  int rows, columns;

  scanf("%d", &rows);
  scanf("%d", &columns);

  int vector[rows][columns];

  populate(rows, columns, vector);

  char option;
  scanf(" %c", &option);

  int id;
  scanf("%d", &id);

  int max = option == 'c'? 
    maxInColumn(rows, columns, id, vector):
    maxInRow(rows, columns, id, vector);
  
  printf("%d", max);
};