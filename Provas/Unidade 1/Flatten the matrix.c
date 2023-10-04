#include <stdio.h>
#include <stdbool.h>

void flatten(int l, int c, int m[l][c], int vetor[], int ordem) {
  bool porLinha = ordem == 0; 

  int index = 0;
  for(int i = 0; i < (porLinha? l:c); i++) {
    for(int j = 0; j < (porLinha? c:l); j++) {
      vetor[index] = m[porLinha? i:j][porLinha? j:i];
      index++;
    };
  };
};

int main() {
  int ordem, l, c;

  scanf("%d", &ordem);
  scanf("%d %d", &l, &c);

  int matriz[l][c];
  int vetor[l * c];
  
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &matriz[i][j]);
    };
    fflush(stdin);
  };

  flatten(l, c, matriz, vetor, ordem);

  for(int i = 0; i < l * c; i++) {
    printf("%d ", vetor[i]);
  };

  return 0;
};