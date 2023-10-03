#include <stdio.h>

float calculaMedia(char tipo, float n1, float n2, float n3) {
  return tipo == 'A'? 
    (n1 + n2 + n3)/3.0:
    ((n1 * 4.0) + (n2 * 5.0) + (n3 * 6.0))/15.0;
};

int main() {
  char type;
  float n1, n2, n3;

  scanf("%c", &type);
  scanf("%f %f %f", &n1, &n2, &n3);

  printf("Média %.2f", calculaMedia(type, n1, n2, n3));
  return 0;
};