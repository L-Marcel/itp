# Tipo vetor e operações

Defina um tipo de dado (tipo estruturado) para representar um vetor de dimensão arbitrária. Seu tipo deve portanto conter a dimensão do vetor (N) e um array com N valores reais (double).

Defina também funções para realizar as seguintes operações sobre os vetores:

Soma de vetores: a função deve receber dois vetores de mesma dimensão e retornar um novo vetor com o resultado da soma dos vetores passados. A soma de dois vetores de dimensão N é definida por um novo vetor (também de dimensão N) cujos valores resultam da soma das coordenadas correspondentes nos dois vetores. Por exemplo, se os vetores A e B tiverem 3 dimensões, sendo A = (3, 5, 6) e B = (-4, 0, 3), a soma deles será (3 + -4, 5 + 0, 6 + 3) = (-1, 5, 9).​
Produto interno: a função deve receber dois vetores de mesma dimensão e retornar um valor com o resultado do produto interno entre os vetores passados. O produto interno entre e dois vetores A e B é definido pela soma das multiplicações de cada coordenada. Por exemplo, se os vetores A e B tiverem 3 dimensões, sendo A = (3, 5, 6) e B = (-4, 0, 3), o produto interno entre eles será (3 x -4) + (5 x 0) + (6 x 3) = -12 + 0 + 18 = 6.

A entrada do programa constitui de 3 linhas. A 1ª linha contém um valor inteiro N, indicando a dimensão dos vetores. As duas linhas seguintes representam dois vetores, cada linha contendo os N valores do vetor.

O programa deverá enviar para a saída de dados a soma e o produto interno dos vetores lidos. Os valores devem ser impressos com duas casas de precisão.

# Entrada / Saída

```
Entrada: 
3
3 5 6
-4 0 3

Saída:
-1.00 5.00 9.00
6.00
```

```
Entrada: 
5
-2 -1 8 4 0
12 0 -4 5 1

Saída:
10.00 -1.00 4.00 9.00 1.00
-36.00
```