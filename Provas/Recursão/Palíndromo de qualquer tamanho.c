#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool check_words(char *entrada, int start) {
  int tamanho = strlen(entrada);

  if(start > tamanho - start - 1) {
    return true;
  } else if(tolower(entrada[start]) == tolower(entrada[tamanho - start - 1])) {
    return check_words(entrada, start + 1);
  };

  return false;
};

int palindromo(char *entrada) {
  int tamanho = 0;
  int tamanho_com_espacos = strlen(entrada);
  char* texto = malloc(0);

  for(int i = 0; i < tamanho_com_espacos; i++) {
    if(entrada[i] != ' ' && entrada[i] != '\0') {
      tamanho++;
      texto = realloc(texto, sizeof(char) * (tamanho + 1));
      texto[tamanho - 1] = entrada[i];
      texto[tamanho] = '\0';
    };
  };

  return check_words(texto, 0);
};

int main() {
  char texto[20];
  fgets(texto, 20, stdin);

  if(texto[strlen(texto) - 1] == '\n') {
    //vscode
    texto[strlen(texto) - 1] = '\0';
  } else {
    //lop
    texto[strlen(texto)] = '\0';
  };

  printf(
    palindromo(texto) == 0? 
    "O texto \"%s\" não é palíndromo":
    "O texto \"%s\" é palíndromo",
    texto
  );

  return 0;
};