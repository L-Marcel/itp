# Senegal vai para a copa do mundo

A copa do mundo está chegando e uma das sensações é a seleção do Senegal. A qualidade do futebol e a alegria do time são contagiante e não tem como não torcer pelo time (a não ser contra o Brasil, é claro).

Sabendo disso, Andrew, um grande entusiasta do futebol senegalês quer fazer uma aposta com seus amigos. Ele defende que o time vai ser o próximo campeão do mundo. Ele só precisa definir qual será o valor da aposta e decidiu também relacionar o time nessa decisão. O valor a ser colocado em disputa com os amigos vai ser retirado da bandeira do Senegal.

Como todos sabem, a bandeira do Senegal é composta por três retângulos verticais nas cores verde, amarelo e vermelho, com uma estrela no retângulo central. O valor da aposta deve ser proporcional a um dos retângulos da bandeira. Como o cálculo pode ficar muito complicado, ele solicitou a você para construir um algoritmo que vai definir o valor. Então, considere a seguinte maneira que a bandeira vai ser representada:

1. a bandeira tem sempre a proporção de 3 (largura) por 2 (altura);

2. as cores são representadas por números inteiros sequenciais definidos a partir de um número inicial: por exemplo, se o número inicial for 1, a cor do primeiro retângulo será 2, a do segundo vai ser 3 e a terceira vai ser 4.

3. os números que representam as cores não são fixos e dependem do número inicial informado pelo usuário;

4. o tamanho da bandeira é dada a partir da largura informada pelo usuário.

Com base nessas informações, o valor da aposta vai se basear na soma dos números de uma das cores da bandeira. Sendo assim, as entradas para o cálculo da aposta serão sempre uma tupla: largura, número inicial, cor; onde as cores são determinadas pelas letras G (verde), Y (amarelo) ou R (vermelho). Por exemplo, se a seguinte entrada for dada:

    6 2 Y

a saída será: 32

Isso porque a representação da bandeira pelas regras colocadas seria:

3 3 4 4 5 5
3 3 4 4 5 5
3 3 4 4 5 5
3 3 4 4 5 5

e queremos somar todos os valores igual a 4. Lembre que as cores são representadas por números sequenciais e o primeiro deles é determinado pelo valor inicial fornecido pelo usuário.

Andrew só tinha uma restrição sobre a implementação a ser feita por você: o cálculo da aposta deveria estar uma função separada que seria passada para ele dar uma conferida (já que o dinheiro dele estaria em jogo :-P). Ele então, passou o protótipo da função que você deveria implementar:

```c
int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor);
```

Vale salientar que a entrada terá sempre como largura um número múltiplo de 3, o valor inicial será um valor não negativo e as letras serão sempre G (verde), Y (amarelo) ou R (vermelho) (representando as cores da bandeira).

# Entrada / Saída

```
Entrada: 
6 2 Y

Saída:
32
```

```
Entrada:
9 3 G

Saída:
72
```