#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  true = 1,
  false = 0
} bool;

typedef struct {
  int codigo;
  char descricao[20];
  float preco;
} Produto;

void read_line(char linha[30], int tam) {
  fgets(linha, tam, stdin);
  if (linha[strlen(linha)-1] == '\n')
    linha[strlen(linha)-1]='\0';
};

void imprimeProdutos(Produto prod[], int qtdprod) {
  printf("========================================\n");
  printf("| Código | Descrição       | Preço     |\n");
  printf("----------------------------------------\n");
  for (int i = 0; i < qtdprod; i++) {
    printf("| %6d ", prod[i].codigo);
    printf("| %15s ", prod[i].descricao);
    printf("| R$ %6.2f |\n", prod[i].preco);
  }
  printf("----------------------------------------\n");
};

Produto criarProduto(int codigo, char descricao[20], float preco) {
  Produto novoProduto;
  novoProduto.codigo = codigo;
  novoProduto.preco = preco;
  strcpy(novoProduto.descricao, descricao);
  return novoProduto;
};

bool produtoCadastrado(Produto produtos[], int quantidade, int codigo) {
  for(int i = 0; i < quantidade; i++) {
    if(produtos[i].codigo == codigo) {
      return true;
    };
  };

  return false;
};

int main() {
  Produto * produtos = malloc(sizeof(0));
  int qtd = 0;

  while(true) {
    char linha[30];
    read_line(linha, 30);

    if(strlen(linha) == 0){
      break;
    };

    int codigo;
    char descricao[20];
    float preco;

    sscanf(linha, "%d,%[A-Za-z ],%f", &codigo, descricao, &preco);

    if(!produtoCadastrado(produtos, qtd, codigo)) {
      qtd++;

      Produto produto = criarProduto(codigo, descricao, preco);

      produtos = realloc(produtos, sizeof(Produto) * qtd);
      produtos[qtd - 1] = produto;
    };
  };

  imprimeProdutos(produtos, qtd);

  return 0;
};