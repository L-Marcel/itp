# Pacman

Um clássico dos arcades, e um dos primeiros grandes sucessos da indústria dos jogos, Pacman, ou o popular "Come-Come", é até hoje jogado por pessoas de várias idades e grupos sociais. O jogo é um desafio de navegação em um labirinto, e o seu objetivo é consumir todas as bolinhas que estão pelo caminho. Porém nem tudo na vida é só comilança, e um grupo de fantasmas percorre o labirinto atrás do herói guloso. Caso um fantasma alcance o Pacman, é Game Over!!

Caso você não conheça o jogo, digita Pacman no Google, e joga no próprio Doodle :)

Mas calma, você não vai implementar o jogo do Pacman...ainda.

A sua tarefa vai ser mais simples: dado um mapa do jogo, você vai avaliar os caminhos e contar quantas bolinhas o Pacman consegue comer no cenário sem ser bloqueado por paredes ou fantasmas. O mapa será representado como uma matriz de caracteres onde:

. - representa uma bolinha
* - representa uma parede
M - representa um fantasma inimigo
C - representa o Pacman.

Seu programa iniciará lendo dois valores inteiros representando o tamanho dessa matriz, em linhas e colunas. Na sequência, a matriz de caracteres é informada.

Para cada cenário, você deve calcular quantas bolinhas foram devoradas, e fazer a impressão do mapa, substituindo as bolinhas devoradas por um espaço vazio.

Por exemplo, para a seguinte entrada:

4 4
**.*
*C.*
*M.*
****

Teríamos como resultado que o Pacman conseguiria comer as três bolinhas, e a matriz final a ser impressa ficaria:

4 4
** *
*C *
*M *
****

Ou seja, todas as bolinhas foram trocadas por espaços em branco. Eu sei, nos casos de teste do LoP os desenhos ficam feios, mas no terminal (ou o replit.com) eles ficam mais bonitinhos como o do texto :P

Observe atentamente os casos de teste para não errar as formatações de entrada e saída.

DICA: use recursão, vai diminuir muito sua dor de cabeça :)

# Entrada / Saída

```
Entrada:
7 7
*******
M..*..*
*...M.*
*..M..*
C.....*
**..*.*
*******

Saída:
Total de bolinhas devoradas: 20
Mapa final:
*******
M  *  *
*   M *
*  M  *
C     *
**  * *
*******
```

```
Entrada:
7 7
*******
*.*...*
*.*.M.*
*C*...*
*.**M**
*.....*
*******

Saída:
Total de bolinhas devoradas: 8
Mapa final:
*******
* *...*
* *.M.*
*C*...*
* **M**
*     *
*******
```