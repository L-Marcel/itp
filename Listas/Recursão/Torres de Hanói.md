# Torres de Hanói

Um puzzle clássico de raciocínio lógico e matemático, o problema das Torres de Hanói foi criado em 1883 por uma matemático chamado Édouard Lucas. Esse problema consiste em um número X de discos de tamanhos distintos, e um conjunto de 3 pinos. O objetivo é levar todos os discos que estão empilhados no primeiro pino (ordenados do maior no fundo até o menor no topo) até o terceiro pino, movendo um disco de cada vez. Porém a movimentação deve obedecer a seguinte restrição: em nenhum momento, um disco maior pode ficar em cima de um disco menor.

Faça um programa recursivo que recebe uma quantidade N indicando quantos discos estarão no primeiro pino, e imprime:

- A sequência de movimentos realizados no formato "Move o disco em X para Y".
- O total de movimentos realizados no formato "Total de movimentos: X".

Observe atentamente os exemplos de entrada e saída para ver a formatação correta da impressão.

# Entrada / Saída

```
Entrada:
1

Saída:
Move o disco em 1 para 3
Total de movimentos: 1
```

```
Entrada:
2

Saída:
	Move o disco em 1 para 2
Move o disco em 1 para 3
Move o disco em 2 para 3
Total de movimentos: 3
```