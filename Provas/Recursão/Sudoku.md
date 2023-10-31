# Sudoku

> A mais difícil dessas listas (provas)

O jogo de Sudoku é um clássico para os amantes de puzzle!

Ele consiste em uma matriz 9x9 parcialmente preenchida. O objetivo do jogo é completar a matriz com dígitos de 1 a 9, seguindo as seguintes regras:

- Nenhum número pode estar repetido em uma linha;
- Nenhum número pode estar repetido em uma coluna;
- Nenhum número pode estar repetido em uma das 9 matrizes menores 3x3 que compõem a matriz grande.

Faça um programa que receba um jogo de sudoku parcialmente resolvido, e imprima a solução caso ela exista, ou "Não tem solução!" caso não seja possível de resolver o puzzle.

A entrada será uma matriz 9x9 contendo números para valores inicialmente preenchidos, e asteriscos representando as casas não preenchidas.

Observe atentamente a formatação dos testes para fazer a entrada e saída do seu programa.

# Entrada / Saída

```
Entrada:
1***79**8
*9*261**5
****8*219
64****792
521*****6
98**2***1
**493*6**
***817*24
879*****3	

Saída:
132579468
498261375
756384219
643158792
521793846
987426531
214935687
365817924
879642153
```

```
Entrada:
1***79**8
*9*261**5
****8*219
64****792
521*****6
98**2***1
**493*6**
***817*24
879***135

Saída:
Não tem solução!
```