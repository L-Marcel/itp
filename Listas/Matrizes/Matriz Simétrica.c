#include <stdio.h>
#include <stdbool.h>

bool have_symmetry(int row, int column, int vectors[row][column]) {
  if(row != column) {
    return false;
  };

  for(int r = 0; r < row; r++) {
    for(int c = 0; c < column; c++) {
      if(vectors[c][r] != vectors[r][c]) {
        return false;
      };
    };
  };

  return true;
};

void populate(int row, int column, int vectors[row][column]) {
  for(int r = 0; r < row; r++) {
    for(int c = 0; c < column; c++) {
      scanf("%d", &vectors[r][c]);
    };
    fflush(stdin);
  };
};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);

  int vectors[r][c];

  populate(r, c, vectors);

  if(have_symmetry(r, c, vectors)) {
    printf("Matriz Simétrica");
  } else {
    printf("Matriz não Simétrica");
  };

  return 0;
};