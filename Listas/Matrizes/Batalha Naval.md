# Batalha Naval

Um clássico dos jogos de tabuleiro e digitais, a Batalha naval consiste em dois tabuleiros 10 x 10, um para cada jogador. Cada um dos jogadores irá posicionar seu conjunto de barcos de forma que o outro não veja, e então eles devem alternar turnos tentando adivinhar onde o oponente colocou os barcos. Se o adversário errar, o jogador grita "Água!", e se acertar o jogador informa que o tiro foi bem sucedido.

Os barcos possuem tamanhos distintos, indo de 2 a 5, ou 1 a 4 dependendo da versão do jogo. Um barco de 4 partes só afunda quando as 4 são atingidas pelo jogador. Vence a partida quem afundar todos os barcos do adversário primeiro.

Mas calma jovem! Nesse exercício você não vai precisar implementar o jogo de batalha naval. Apenas uma parte :P

Faça um programa que leia a posição, representada por valores inteiros de 0 a 9, de quatro barcos de tamanhos distintos, na seguinte ordem:

- Canoa - 1 posição
- Barco - 2 posições
- Fragata - 3 posições
- Destróier - 4 posições

Em seguida, imprima um mapa de batalha naval (10x10), com as seguintes características:

- ~ - água
- \* - canoa
- < OU > - Pontas dos barcos com 2 ou mais posições
- | - corpo de barco na vertical (3 ou mais posições)
- = - corpo de barco na horizontal (3 ou mais posições).

Verifique os exemplos de entrada e saída para entender o formato de impressão desejado.