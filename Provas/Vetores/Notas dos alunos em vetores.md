# Notas dos alunos em vetores

Numa escola as médias finais dos alunos estão armazenadas em um vetor cuja ordem é a da lista de chamada da turma. Alunos com média maior ou igual a 7.0 estão aprovados, maior ou igual a 5.0 e menor que 7.0 estão em recuperação, e abaixo de 5.0 estão reprovados. Escreva um programa que lê a quantidade de alunos n da turma, e em seguida as suas nnn médias. Então, crie vetores que guardem a lista de alunos aprovados, em recuperação e reprovados com as respectivas notas.

## Valor de entrada​

- número n de alunos da turma;
- número do aluno na chamada - sua média parcial (n vezes).

## Valor de saída​

- Listas de alunos aprovados, em recuperação e reprovados identificados pelo seu número e sua nota entre parênteses;

# Entrada / Saída

```
Entrada:
5
1 - 3.2
2 - 9.2
3 - 6.1
4 - 8.6
5 - 0.3

Saída:
Aprovados: 2 (9.2), 4 (8.6)
Recuperação: 3 (6.1)
Reprovados: 1 (3.2), 5 (0.3)
```

```
Entrada:
15
1 - 9.0
2 - 5.7
3 - 9.3
4 - 8.1
5 - 4.1
6 - 5.0
7 - 1.6
8 - 5.5
9 - 0.6
10 - 8.8
11 - 7.2
12 - 5.0
13 - 5.7
14 - 0.1
15 - 1.8

Saída:
Aprovados: 1 (9.0), 3 (9.3), 4 (8.1), 10 (8.8), 11 (7.2)
Recuperação: 2 (5.7), 6 (5.0), 8 (5.5), 12 (5.0), 13 (5.7)
Reprovados: 5 (4.1), 7 (1.6), 9 (0.6), 14 (0.1), 15 (1.8)
```