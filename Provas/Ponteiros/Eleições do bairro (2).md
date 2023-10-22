# Eleições do bairro (2)

A eleição para representante do seu bairro, que atualmente usa o voto eletrônico, entrou numa discussão sem fim sobre se a eleição pode ser burlada ou não. E o grupo do WhatsApp da sua família resolveu parar de dar "Bom dia" e entrou na onda da discussão.

Para aliviar os ânimos, você criou um programa para mostrar como a contagem no computador funciona e deixou seu código aberto para todos verem o que está ocorrendo. Só que isso gerou ainda mais discussões no seu grupo familiar. Você, inocentemente achando que seu conhecimento técnico em TI iria ajudar a acabar com as discussões, resolve colocar mais detalhes no código, como nomes dos candidatos, computar votos inválidos e tudo mais.

Crie um registro com as informações de uma chapa. O registro deve conter três campos: um número inteiro com o identificador da chapa, uma string para o nome da chapa e, por fim, um inteiro para a quantidade de votos da chapa.

Escreva então, uma função para computar as duas chapas mais votadas (a eleição do bairro ainda está no 1º turno). Sua função deve receber como parâmetro uma sequência (array) com os votos de uma urna (valores inteiros) e um array com os dados das chapas (registro criado anteriormente). Sua função deverá alterar os dados dos registros no array e indicar (referenciar) os dois mais votados, bem como retornar a quantidade de votos válidos, ou seja a quantidade de identificadores pertecentes a uma das chapas.

Assim, a assinatura da sua função deve ser:

```c
int compute_votes(
  int num_votes, int votes[num_votes],
  int num_parties, Party parties[num_parties],
  Party *most_voted, Party *second_most_voted
);
```

Escreva um programa que utilize esta função. Seu programa deve receber inicialmente um valor N, com a quantidade de chapas, seguido de N linhas. Cada linha contém um valor inteiro, com o identificador da chapa, e uma string (sem espaços em branco) com o nome da chapa. Depois, o programa receberá um valor M, com a quantidade de votos, seguido de M valores inteiros positivos. Cada valor representando uma chapa da eleição. O programa deve, em seguida, imprimir a quantidade de votos, de votos válidos e os dados referentes às duas chapas mais votadas.

​Obs: É garantido, nos casos de teste, que não haja empates entre os primeiros colocados (sempre haverá um vencedor e um vice). Portanto, tranquilize sua família que isso não é um bug do software :-). É apenas uma característica dos dados tratados.

# Entrada / Saída

```
Entrada:
3
1 PXDY
2 PPAAW
3 REP
9
1 2 3 4 2 3 4 3 4

Saída:
VENCEDOR: REP (3 votos = 50.00%)
VICE: PPAAW (2 votos = 33.33%)
```

```
Entrada: 
5 
9 PDET
8 YUPAI
4 UQT
5 WEQUIA
1 LOPAQI
15
1 5 4 1 9 8 5 1 3 4 9 1 6 5 3

Saída:
VENCEDOR: LOPAQI (4 votos = 33.33%)
VICE: WEQUIA (3 votos = 25.00%)
```