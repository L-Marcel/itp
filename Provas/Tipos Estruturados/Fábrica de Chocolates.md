# Fábrica de Chocolates

Uma fábrica de chocolates está se preparando para a Páscoa e precisa de sua ajuda para organizar o seu inventário.

Crie uma enumeração TipoChocolates com as opções: BRANCO, AMARGO, AO_LEITE, COM_CASTANHAS.

Crie uma struct chamada Chocolate que contém:

Nome do chocolate (string de até 50 caracteres)
Peso (float, representando gramas)
Preço (float)
Tipo do chocolate (TipoChocolates)
Escreva um programa que:

Leia a quantidade de chocolates a serem inseridos.
Permita ao usuário inserir informações sobre os chocolates.
Mostre o total de chocolates por tipo.
Indique o chocolate mais caro e o mais barato.

# Entrada / Saída

```
Entrada: 
2
AmorDeVida
90.5
10.00
BRANCO
DeliciaCrocante
100.0
10.0
O_LEITE

Saída:
Total de chocolates BRANCO: 1
Total de chocolates AMARGO: 0
Total de chocolates AO_LEITE: 0
Total de chocolates COM_CASTANHAS: 0
Chocolate mais caro: AmorDeVida - R$10.00
Chocolate mais barato: AmorDeVida - R$10.00
```

```
Entrada: 
5
DeliciosoBranco
100.5
20.00
BRANCO
AmargoDaVida
120.0
25.50
AMARGO
AoLeiteSupremo
130.0
22.50
AO_LEITE
CastanhaChoco
110.0
26.00
COM_CASTANHAS
LeiteDoCeu
110.5
21.00
AO_LEITE

Saída:
Total de chocolates BRANCO: 1
Total de chocolates AMARGO: 1
Total de chocolates AO_LEITE: 2
Total de chocolates COM_CASTANHAS: 1
Chocolate mais caro: CastanhaChoco - R$26.00
Chocolate mais barato: DeliciosoBranco - R$20.00
```