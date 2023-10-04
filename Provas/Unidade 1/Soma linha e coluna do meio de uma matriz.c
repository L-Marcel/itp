#include <stdio.h>
#include <stdbool.h>

int somaLinhaMatrizMeio(int r, int c, int vectors[r][c]) {
  int count = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      bool mainRow = i == (r - 1)/2;
      bool mainCol = j == (c - 1)/2;
      if(mainCol || mainRow) {
        count += vectors[i][j];

        if(mainCol && mainRow) {
          count += vectors[i][j];
        };
      };
    };
  };

  return count;
};

int main() {
  int r, c;

  scanf("%d %d", &r, &c);

  int vectors[r][c];

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &vectors[i][j]);
    };
    fflush(stdin);
  };

  printf("%d", somaLinhaMatrizMeio(r, c, vectors));

  return 0;
};