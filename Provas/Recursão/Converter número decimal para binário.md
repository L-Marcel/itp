# Converter número decimal para binário

Faça uma função recursiva que realiza a conversão de um número inteiro não negativo para o seu valor binário.

Para converter um número decimal para binário, você realiza uma sequência de divisões. Vamos exemplificar com o valor 10:

10 / 2 = 5, resto 0
5/2 = 2, resto 1
2/2 = 1, resto 0
1/2 = 0, resto 1

O valor binário é obtido a partir dos restos da divisão, tomados na ordem do último ao primeiro:

10 em binário é 1010.

# Entrada / Saída

```
Entrada:
10	

Saída:
1010
```

```
Entrada:
3

Saída:
11
```