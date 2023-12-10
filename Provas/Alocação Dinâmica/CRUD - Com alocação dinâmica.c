#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char nome[30];
  int idade;
  char sexo;
} Pessoa;

typedef struct {
  int quantidade;
  Pessoa* lista;
} Pessoas;

Pessoa criar(char nome[30], int idade, char sexo) {
  Pessoa pessoa = {"",idade,sexo};
  
  strcpy(pessoa.nome, nome);

  return pessoa;
};

Pessoas criar_lista() {
  Pessoas* pessoas = malloc(sizeof(Pessoas));
  pessoas -> quantidade = 0;
  pessoas -> lista = (Pessoa*) malloc(0);

  return *pessoas;
};

void inserir(Pessoas* pessoas, Pessoa pessoa) {
  pessoas -> quantidade++;
  pessoas -> lista = realloc(pessoas -> lista, sizeof(Pessoa) * pessoas -> quantidade);
  pessoas -> lista[pessoas -> quantidade - 1] = pessoa;
};

bool mesma_pessoa(Pessoa p1, Pessoa p2) {
  return 
    p1.idade == p2.idade && 
    p1.sexo == p2.sexo &&
    strcmp(p1.nome, p2.nome) == 0;
};

void deletar(Pessoas* pessoas, Pessoa pessoa) {
  for(int i = 0; i < pessoas -> quantidade; i++) {
    if(mesma_pessoa(pessoas -> lista[i], pessoa)) {
      pessoas -> quantidade--;

      for(int j = 0; j < pessoas -> quantidade - i; j++) {
        pessoas -> lista[i + j] = pessoas -> lista[i + j + 1];
      };

      pessoas -> lista = realloc(pessoas -> lista, sizeof(Pessoa) * pessoas -> quantidade);
    };
  };
}; 

void imprimir(Pessoas* pessoas) {
  for(int i = 0; i < pessoas -> quantidade; i++) {
    Pessoa pessoa = pessoas -> lista[i];
    printf("%s,%d,%c\n", pessoa.nome, pessoa.idade, pessoa.sexo);
  };
};

int main() {
  Pessoas pessoas = criar_lista();

  while(true) {
    char acao = getchar();

    if(acao == 'p') {
      imprimir(&pessoas);
      break;
    };

    char nome[30];
    int idade;
    char sexo;

    getchar();
    scanf("%[a-zA-Z ][^\n]", nome);
    scanf("%d", &idade);

    getchar();
    sexo = getchar();
    getchar();

    Pessoa pessoa = criar(nome, idade, sexo);

    if(acao == 'i') {
      inserir(&pessoas, pessoa);
    } else if(acao == 'd') {
      deletar(&pessoas, pessoa);
    };
  };

  return 0;
};