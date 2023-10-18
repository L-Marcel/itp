#include <stdio.h>
#include <string.h>

typedef enum {
  BRANCO,
  AMARGO,
  AO_LEITE,
  COM_CASTANHAS
} TipoChocolates;

typedef struct {
  char nome[50];
  float peso;
  float preco;
  TipoChocolates tipo;
} Chocolate;

int obterTipoDeChocolate(char tipo[15]) {
  if(strcmp(tipo, "BRANCO") == 0) {
    return BRANCO;
  } else if(strcmp(tipo, "AMARGO") == 0) {
    return AMARGO;
  } else if(strcmp(tipo, "AO_LEITE") == 0) {
    return AO_LEITE;
  } else if(strcmp(tipo, "COM_CASTANHAS") == 0){
    return COM_CASTANHAS;
  } else {
    return -1;
  };
};

void imprimirQuantidades(int quantidade, Chocolate chocolates[quantidade]) {
  int branco = 0;
  int amargo = 0;
  int leite = 0;
  int castanha = 0;

  for(int i = 0; i < quantidade; i++) {
    switch (chocolates[i].tipo){
      case BRANCO:
        branco++;
        break;
      case AMARGO:
        amargo++;
        break;
      case AO_LEITE:
        leite++;
        break;
      case COM_CASTANHAS:
        castanha++;
        break;
      default:
        break;
    }
  };

  printf(
    "Total de chocolates BRANCO: %d\nTotal de chocolates AMARGO: %d\nTotal de chocolates AO_LEITE: %d\nTotal de chocolates COM_CASTANHAS: %d\n",
    branco,
    amargo,
    leite,
    castanha
  );
};

void imprimirChocolatesDestacados(int quantidade, Chocolate chocolates[quantidade]) {
  int maiorPreco = 0;
  int menorPreco = -1;
  int indiceMaior = 0;
  int indiceMenor = 0;

  for(int i = 0; i < quantidade; i++) {
    if(chocolates[i].preco > maiorPreco) {
      maiorPreco = chocolates[i].preco;
      indiceMaior = i;
    };
    
    if(menorPreco == -1 || chocolates[i].preco < menorPreco) {
      menorPreco = chocolates[i].preco;
      indiceMenor = i;
    };

    if(i == quantidade - 1) {
      printf(
        "Chocolate mais caro: %s - R$%.2f\nChocolate mais barato: %s - R$%.2f",
        chocolates[indiceMaior].nome,
        chocolates[indiceMaior].preco,
        chocolates[indiceMenor].nome,
        chocolates[indiceMenor].preco
      );
    };
  };
};

int main() {
  int quantidade;
  scanf("%d", &quantidade);

  Chocolate chocolates[quantidade];

  for(int i = 0; i < quantidade; i++) {
    char nome[50];
    float peso;
    float preco;

    getchar();
    scanf("%s", nome);
    scanf("%f", &peso);
    scanf("%f", &preco);

    getchar();
    char tipo[15];
    scanf("%s", tipo);
    
    if(obterTipoDeChocolate(tipo) != -1) {
      strcpy(chocolates[i].nome, nome);
      chocolates[i].tipo = obterTipoDeChocolate(tipo);
      chocolates[i].peso = peso;
      chocolates[i].preco = preco;
    } else {
      quantidade--;
      i--;
    };
  };

  imprimirQuantidades(quantidade, chocolates);
  imprimirChocolatesDestacados(quantidade, chocolates);

  return 0;
};