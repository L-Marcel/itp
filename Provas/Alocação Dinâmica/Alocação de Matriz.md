# Alocação de Matriz


Escreva um programa que lê uma matriz de valores inteiros, alocando os dados dinamicamente, imprime os valores da matriz e, por fim, libera o espaço alocado. A função main() de seu programa já se encontra implementada. Basta agora usar o tipo Matrix e escrever as funções createMatrix(), readMatrix(), printMatrix() e destroyMatrix() com as assinaturas a seguir:

```c
typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol);
void readMatrix(Matrix *m);
void printMatrix(Matrix *m);​
void destroyMatrix(Matrix **m);
```

A implementação do main() DEVE SER (não alterar):

```c
int main() {
  int lin, col;
  Matrix* mat;

  scanf("%i %i", &lin, &col);
  mat = createMatrix(lin, col);
  readMatrix(mat);
  printMatrix(mat);
  destroyMatrix(&mat);
  if (mat == NULL) {
    printf("OK\n");
  }
  return 0;
}
```

# Entrada / Saída

```
Entrada: 
3 4
1 2 3 4
5 6 7 8
9 0 1 2

Saída:
1 2 3 4
5 6 7 8
9 0 1 2
OK
```

```
Entrada:
2 2
1 1
2 2

Saída:
1 1
2 2
OK
```