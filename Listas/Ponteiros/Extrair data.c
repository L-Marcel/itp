#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool extrair_data(
  char entrada[10], 
  int* dia, int* mes, int* ano
) {
  if(strlen(entrada) < 10) {
    return false;
  };

  entrada[2] = '-';
  entrada[5] = '-';

  sscanf(entrada, "%d-%d-%d", dia, mes, ano);

  if(dia == NULL || mes == NULL || ano == NULL) {
    return false;
  };

  return true;
};

int main() {
  char entrada[10];
  scanf("%[0-9-/][^\n]", entrada);
  
  int dia, mes, ano;
  bool sucesso = extrair_data(entrada, &dia, &mes, &ano);

  if(!sucesso) {
    printf("INVALIDO!");
    return 0;
  };

  printf("%02d/%02d/%04d", dia, mes, ano);

  return 0;
};