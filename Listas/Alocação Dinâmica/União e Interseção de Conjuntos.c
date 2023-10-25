#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int tamanho;
  int* valores;
} Conjunto;

Conjunto criar_conjunto() {
  Conjunto* conjunto = malloc(sizeof(Conjunto));
  conjunto -> tamanho = 0;
  conjunto -> valores = malloc(0);

  return *conjunto;
};

void popular_conjunto(Conjunto* conjunto) {
  scanf("%d", &(conjunto -> tamanho));
  conjunto -> valores = realloc(conjunto -> valores, sizeof(int) * conjunto -> tamanho);
  
  for(int i = 0; i < conjunto -> tamanho; i++) {
    scanf("%d", conjunto -> valores + i);
  };
};

void adicionar_no_conjunto(Conjunto* conjunto, int numero) {
  conjunto -> tamanho++;
  conjunto -> valores = realloc(conjunto -> valores, sizeof(int) * conjunto -> tamanho);
  conjunto -> valores[conjunto -> tamanho - 1] = numero;
};

void apagar_conjunto(Conjunto* conjunto) {
  free(conjunto -> valores);
  conjunto = NULL;
};

bool pertence_ao_conjunto(Conjunto* conjunto, int numero) {
  for(int i = 0; i < conjunto -> tamanho; i++) {
    if(conjunto -> valores[i] == numero) {
      return true;
    };
  };

  return false;
};

Conjunto uniao(Conjunto a, Conjunto b) {
  Conjunto c = criar_conjunto();

  for(int i = 0; i < a.tamanho; i++) {
    if(!pertence_ao_conjunto(&c, a.valores[i])) {
      adicionar_no_conjunto(&c, a.valores[i]);
    };
  };

  for(int i = 0; i < b.tamanho; i++) {
    if(!pertence_ao_conjunto(&c, b.valores[i])) {
      adicionar_no_conjunto(&c, b.valores[i]);
    };
  };

  return c;
};

Conjunto intersecao(Conjunto a, Conjunto b) {
  Conjunto c = criar_conjunto();

  for(int i = 0; i < b.tamanho; i++) {
    if(pertence_ao_conjunto(&a, b.valores[i])) {
      adicionar_no_conjunto(&c, b.valores[i]);
    };
  };

  return c;
};

void imprimir_conjunto(Conjunto a, char identificao[15]) {
  printf("%s == {", identificao);
    
  if(a.tamanho == 0) {
    printf("vazio}\n");
    return;
  };
    
  for(int i = 0; i < a.tamanho; i++) {
    printf("%d%s", a.valores[i], i == a.tamanho - 1? "}\n":" ");
  };
};

int main() {
  Conjunto a = criar_conjunto();
  Conjunto b = criar_conjunto();

  popular_conjunto(&a);
  popular_conjunto(&b);

  Conjunto c = uniao(a, b);
  Conjunto d = intersecao(a, b);

  apagar_conjunto(&a);
  apagar_conjunto(&b);

  imprimir_conjunto(c, "A união B");
  imprimir_conjunto(d, "A interseção B");
 
  apagar_conjunto(&c);
  apagar_conjunto(&d);

  return 0;
};