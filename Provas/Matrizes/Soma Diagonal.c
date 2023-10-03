#include <stdio.h>

int calculate(int size, int vectors[size][size]) {
  int value = 0;

  for(int r = 0; r < size; r++) {
    for(int c = 0; c < size; c++) {
      scanf("%d", &vectors[r][c]);

      if(r == c) {
        value += vectors[r][c];
      };
    };
    fflush(stdin);
  };

  return value;
};

int main() {
  int size;
  scanf("%d", &size);

  int vectors[size][size];

  printf("%d", calculate(size, vectors));

  return 0;
};