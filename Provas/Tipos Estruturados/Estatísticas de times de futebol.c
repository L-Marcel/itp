#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char nome[30];
  int golsMarcados;
  int golsSofridos;
} Time; 

bool naLista(int quantidade, char times[quantidade][30], Time time) {
  for(int i = 0; i < quantidade; i++) {
    if(times[i] != NULL && strcmp(times[i], time.nome) == 0) {
      return true;
    };
  };

  return false;
};

void imprimirTimes(int quantidade, Time times[quantidade]) {
  char timesImprimidos[quantidade][30];
  
  int indice = 0;
  for(int i = 0; i < quantidade; i++) {
    int maiorContagemDeGols = 0;

    for(int j = 0; j < quantidade; j++) {
      if(
        !naLista(quantidade, timesImprimidos, times[j]) &&
        maiorContagemDeGols < times[j].golsMarcados
      ) {
        maiorContagemDeGols = times[j].golsMarcados;
        indice = j;
      };

      if(j == quantidade - 1) {
        strcpy(timesImprimidos[i], times[indice].nome);
        printf(
          "%d - %sGols marcados: %d\nGols sofridos: %d\n", 
          i + 1, 
          times[indice].nome, 
          times[indice].golsMarcados, 
          times[indice].golsSofridos
        );
      };
    };
  };
};

int main() {
  int quantidade;
  scanf("%d", &quantidade);

  Time times[quantidade];

  for(int i = 0; i < quantidade; i++) {
    getchar();
    fgets(times[i].nome, 30, stdin);

    scanf("%d", &times[i].golsMarcados);
    scanf("%d", &times[i].golsSofridos);
  };
  
  imprimirTimes(quantidade, times);

  return 0;
};