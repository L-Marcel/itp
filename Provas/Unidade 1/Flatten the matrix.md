# Flatten the matrix

Na análise de dados é comum precisarmos reorganizar os valores de uma matriz em uma estrutura sequencial, como um vetor. Um nome comum para essa operação é flatten que coloca todos as linhas ou colunas de uma matriz em um único vetor. Por exemplo, para a matriz:

1 2 3
4 5 6
7 8 9

uma representação flattened dela seria `[1 2 3 4 5 6 7 8 9]`. No que usamos a sequência das linhas. Mas, poderíamos também ter utilizado a colunas como referência. Assim, o vetor usando as colunas seria `[1 4 7 2 5 8 3 6 9]`.

Diante disso, implemente um programa em C que realize a operação de flatten. Para isso é necessário que você faça uso da seguinte função:

```c
void flatten(int l, int c, int m[l][c], int vetor[], int ordem);
```

em que l e c são a quantidade de linhas e colunas da matriz m, vetor é o array onde os valores vetorizados vão ficar e ordem é o indicador se devemos seguir as linhas ou colunas para vetorizar a matriz: 0 para linhas e 1 para colunas.

O seu programa receberá um valor inteiro indicando a ordem a ser utilizada, dois outros valores inteiros para indicar o tamanho da matriz e, por último, a matriz a ser vetorizada.


# Entrada / Saída
```
Entrada:
0
3 3
1 2 3
4 5 6
7 8 9	

Saída:
1 2 3 4 5 6 7 8 9
```
```
Entrada:
1
3 3
1 2 3
4 5 6
7 8 9

Saída:
1 4 7 2 5 8 3 6 9 
```



