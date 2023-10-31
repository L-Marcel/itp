# Campo Minado

Os usuários mais experientes dos sistemas operacionais Windows já investiram algumas horas em um jogo chamado Campo Minado.

O Campo Minado é um jogo onde você deve identificar corretamente, em um território, a localização de um número X de bombas. Inicialmente todas as casas do campo estão escondidas, e a medida que o jogador vai abrindo, ele vai recebendo dicas de quantas bombas estão em volta da casa que ele selecionou. Ao clicar em uma casa, existem 3 resultados possíveis:

- O jogador clicou em uma bomba. Nesse caso ele perde o jogo!

- O jogador clicou em uma casa que possui bombas em volta. Nesse caso, o jogo mostra um valor numérico indicando a quantidade de bombas em volta.

- O jogador clicou em uma casa que não possui bombas ao redor. Nesse caso ele abre todas as casas vizinhas, seguindo as mesmas regras.

Nesse programa, você vai fazer uma simulação das jogadas em um Campo Minado.

Seu programa vai ler dois inteiros N e M, que representam o tamanho do campo (N linhas e M colunas).  Em seguida ele vai ler um inteiro B, que representa a quantidade de bombas existentes no mapa.

As próximas B linhas vão conter um par de inteiros LINHA_B e COLUNA_B, indicando a posição da bomba. Por exemplo, 2 2 indica que a bomba está na segunda linha e segunda coluna do campo.

Após a leitura das bombas, o seu programa lerá um inteiro J indicando o número de jogadas a serem simuladas. As jogadas podem ser de dois tipos apenas:

- Clica LINHA COLUNA, indica que o jogador clicou para abrir a casa na posição LINHA e COLUNA do mapa.

- Marca LINHA COLUNA, indica que o jogador deseja marcar a posição LINHA, COLUNA do campo como contendo uma bomba.

O seu programa deverá imprimir o passo a passo da simulação, desenhando o mapa de acordo com as regras do campo minado. Cada mapa será precedido de uma barra de caracteres "=", com tamanho igual a M+2. O campo deve ser impresso da seguinte forma:

- Um asterisco (*) para as casas que ainda não foram reveladas.
- Um valor numérico (entre 1 e 9) para as casas que foram reveladas e que possuem bombas ao redor.
- Um valor numérico 0 para casas que foram reveladas e não possuem bombas em volta
- Uma letra "B" para casas que foram marcadas como bomba pelo jogador
- Uma letra "X" para casas que foram clicadas e contém uma bomba.

O seu jogo deve simular os passos de acordo com as regras do campo minado:

- Se o jogador clicar em uma casa com uma bomba, Uma mensagem "CABUUUUM!" seguida pela mensagem "Game Over...." devem ser impressas.
- Se o jogador clicar em uma casa com bombas ao redor, um número deve ser exibido indicando a quantidade de bombas ao redor da casa (verificar as 8 casas em volta).
- Se o jogador clicar em uma casa sem bombas ao redor, o jogo deve abrir recursivamente todas as casas vizinhas, seguindo as mesmas regras acima.
- Se o jogador executar todos os passos da simulação, uma mensagem "Você sobreviveu!" deve ser impressa.

Ao final da partida, independente se o jogador sobreviveu ou perdeu, o mapa do campo minado deve ser completamente revelado. Nesse momento, bombas que ainda não haviam sido marcadas serão impressas com a letra B.

# Entrada / Saída

```
Entrada:
3 4
2
2 2
1 4
5
Clica 1 1
Clica 3 4
Clica 1 3
Marca 1 4
Clica 2 2

Saída:
======
1***
****
****
======
1***
**21
**10
======
1*2*
**21
**10
======
1*2B
**21
**10
CABUUUUM!
Game Over....
======
112B
1X21
1110
```

```
Entrada:
3 3
8
1 1
1 2
1 3
2 1
2 3
3 1
3 2
3 3
2
Clica 2 2
Marca 1 1

Saída:
=====
***
*8*
***
=====
B**
*8*
***
Você sobreviveu!
=====
BBB
B8B
BBB
```