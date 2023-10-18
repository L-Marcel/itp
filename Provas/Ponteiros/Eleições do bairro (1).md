# Eleições do bairro (1)

A eleição para representante do seu bairro, que atualmente usam o voto eletrônico, entrou numa discussão sem fim, sobre se a eleição poderia ser burlada ou não. E o grupo do WhatsApp da sua família resolveu parar de dar "Bom dia" e entrou na onda da discussão.

Para aliviar os ânimos, você resolve mostrar como a contagem no computador funciona, deixando seu código aberto para todos verem o que está ocorrendo. Mostre o processo de contagem dos votos de uma eleição escrevendo uma função para computar as duas chapas mais votadas (a eleição do bairro ainda está no 1º turno).

Considerando que há 10 chapas na eleição, identificadas com os números de 1 a 10, e que todos os votos foram válidos (estão no intervalo de 1 a 10), escreva uma função que recebe uma sequência de votos (números de 1 a 10) e computa as duas chapas mais votadas. A assinatura da sua função deve ser:

```c
void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted);
```

Escreva um programa que utilize esta função. Seu programa deve receber como entrada um valor inteiro N seguido de N valores inteiros positivos. Cada valor representando uma chapa da eleição. O programa deve, em seguida, imprimir as chapas mais votadas, sendo a primeira a mais votada.

Obs: É garantido, nos casos de teste, que não haja empates entre os primeiros colocados (sempre haverá um vencedor e um vice). Portanto, tranquilize sua família que isso não é um bug do software :-). É apenas uma característica dos dados tratados.

# Entrada / Saída

```
Entrada:
6
2 3 2 2 1 3

Saída:
2 3
```

```
Entrada:
10
9 1 8 2 7 3 9 1 9 5

Saída:
9 1
```