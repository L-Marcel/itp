#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void imprimePalavra (char *c, int salto, int tam) {
  if(c == NULL) {
    printf("Palavra nao encontrada\n");
    return;
  }
  for(int i = 0; i < tam; i++) {
    printf("%c", *c);
    c += salto;
  }
  printf(", salto:%d\n", salto);
};

bool cacarPalavra(
  char palavra[30], 
  int tam,
  char *matriz, 
  int posicao, 
  int salto 
) {
  if(tolower(*(matriz + posicao)) == tolower(palavra[0])) {
    for(int i = 1; i < tam; i++) {
      if(tolower(*(matriz + posicao + (i * salto))) != tolower(palavra[i])) {
        return false;
      };
    };
    
    return true;
  };

  return false;
};

void cacarPalavras(
  char* matriz, 
  int num_palavras, 
  char palavras[num_palavras][30]
) {
  for(int p = 0; p < num_palavras; p++) {
    int tam = strlen(palavras[p]);

    //desconsiderando \0 e primeira letra
    int tam_reduzido = tam - 2;
    bool encontrada = false;
    int menorPosicao = 100;
    int saltoNecessario = 1;

    //para a direita ou para baixo
    int saltos[3] = {1, 10, 11};
    for(int s = 0; s < 3; s++) { 
      for(int i = 0; (i < 100 - (tam_reduzido * 10)); i++) {
        int posicao = i + (tam_reduzido * (i / (10 - tam_reduzido)));
        int salto = saltos[s];

        bool sucesso = cacarPalavra(palavras[p], tam, matriz, posicao, salto);
        if(sucesso && posicao < menorPosicao) {
          encontrada = true;
          menorPosicao = posicao;
          saltoNecessario = salto;
          break;
        };
      };

      saltos[s] = -saltos[s];
    };

    //para a esquerda ou para cima
    for(int s = 2; s >= 0; s--) { 
      for(int i = 0; i < 100 - (tam_reduzido * 10); i++) {
        int posicao = i + (tam_reduzido * ((i / (10 - tam_reduzido)) + 1));
        int salto = saltos[s];

        bool sucesso = cacarPalavra(palavras[p], tam, matriz, posicao, salto);
        if(sucesso && posicao < menorPosicao) {
          encontrada = true;
          menorPosicao = posicao;
          saltoNecessario = salto;
          break;
        };
      };
    };

    if(encontrada) {
      imprimePalavra(matriz + menorPosicao, saltoNecessario, tam);
    } else {
      printf("Palavra nao encontrada\n");
    };
  };
};

int main() {
  int num_palavras;
  scanf("%d", &num_palavras);
  getchar();

  char palavras[num_palavras][30];
  for(int i = 0; i < num_palavras; i++) {
    scanf("%s[^\n]", palavras[i]);
  };

  char *matriz = malloc(sizeof(char) * 100);
  for(int i = 0; i < 100; i++) {
    char letra = getchar();
    while(letra == '\n') {
      letra = getchar();
    };

    *(matriz + i) = letra;
  };

  cacarPalavras(matriz, num_palavras, palavras);

  return 0;
};