# Flechada no Joelho

Eu costumava ser um aventureiro como você, até levar uma flechada no joelho...

Essa é uma frase muito comum entre os guardas da província de Whiterun, em Skyrim. Eles pararam com suas aventuras porque não conseguem mais carregar uma boa quantidade de tesouros como antigamente...

Como um mago especializado na área de magia chamada Programmium, você deve escrever um programa que ajude os antigos aventureiros a calcular qual o maior valor de tesouro que eles conseguiriam carregar de uma caverna, de forma que eles possam decidir se vão arriscar a aventura ou não.

Seu programa lerá dois valores inteiros iniciais, Q e P:

- Q representa a quantidade de itens que estarão presentes na caverna;
- P representa o peso máximo que um aventureiro consegue carregar.

A sequência da entrada contém Q linhas descrevendo cada um dos itens, no seguinte formato:

> NOME VALOR PESO

onde NOME é uma string simples, sem espaços em brancos, e menor do que 20 letras; VALOR é o preço do item (em inteiros, porque Skyrim ainda não descobriu os números reais) e PESO é... bem, o peso dele :)

Seu programa então deve determinar qual é o conjunto de tesouros de maior valor que o aventureiro consegue resgatar de acordo com o limite de peso que ele consegue carregar. Por exemplo, para a entrada:

```
3 20
espada 100 21
ouro 50 10
meia 1 1
```

O melhor resultado da aventura seria ele voltar com o ouro e a meia, um total de 51 e de peso 11, já que a espada é muito pesada para ele carregar!

Seu programa deverá imprimir como resultado:

Caso não exista uma combinação possível de tesouros na caverna, uma mensagem "Nada para carregar..."

Caso exista uma combinação possível, o programa deve imprimir a mensagem "Inventario final:", seguido por uma lista de itens no formato "Item: NOME", com uma última linha indicando "Valor total: VALOR_DE_TODOS_OS_TESOUROS_DA_COMBINAÇÃO".

Atente para os exemplos para ver a formatação adequada.

# Entrada / Saída

```
Entrada:
4 30
espada 50 20
sacola 10 10
diamante 23 5
pedra 1 30

Saída:
Inventario final:
Item: espada
Item: diamante
Valor total: 73
```

```
Entrada:
8 5
rubi 100 1
esmeralda 200 2
diamante 400 3
lata 1 1
cobre 150 1
prata 50 2
pepita 100 1
scroll 500 5

Saída:
Inventario final:
Item: rubi
Item: diamante
Item: cobre
Valor total: 650
```