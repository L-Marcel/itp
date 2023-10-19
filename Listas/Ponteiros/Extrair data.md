# Extrair data

Crie um programa que recebe uma palavra e extrai dessa palavra, caso exista, uma data no formato dia/mês/ano em que dia e mês possuem dois dígitos e o ano quatro digitos.

Para isso, crie uma função "extrair_data" que receba uma string e também três variáveis inteiras passadas por referência (ponteiros) representando o dia, o mês e o ano. A função deve retornar verdadeiro se existir uma data na palavra e falso em caso contrário. Além disso, deve armazenar o dia, o mês e o ano nos ponteiros para inteiro recebidos. Mas, se não existir uma data na palavra, as variáveis não devem ser alteradas.



Uma data válida será uma sequência de três campos separados por '/' ou por '-'. Os dias variam no intervalo natural [1,31], sempre com dois dígitos (zero a esquerda para valores menores que 10), os meses entre [1,12], também com dois dígitos, e os anos como uma sequência de quatro dígitos. Por exemplo, "01/02/1990" e "10-01-2020" representam as datas primeiro de fevereiro de 1990 e 10 de janeiro de 2020 respectivamente.

Uma data válida não deverá conter outros caracteres não brancos (de acordo com o método de leitura, caracteres em branco podem precisar ser tratados).



O programa deve chamar a função de extração de data, passando a palavra lida da entrada padrão. Caso a função identifique que a palavra não é uma data válida, o programa deve exibir a mensagem "INVALIDO!". Se a data for válida, o programa deve imprimir a data formatada como "<dia>/<mes>/<ano>".

Atenção:

O programa não deve utilizar variáveis globais e a função não deve exibir dados na saída padrão, isto é, não deve fazer chamadas a função printf ou similar. Além disso, considere que as palavras terão um máximo de 255 caracteres, que não existem palavras com duas ou mais datas e que não serão fornecidas entradas com datas inválidas considerando a quantidade de dias, meses e anos.

Lembre que a função implementada deve seguir a especificação descrita no problema.​

Você pode utilizar outras funções auxiliares, chamadas pela função "extrair_data".

# Entrada / Saída

```
Entrada:
10/10/2020

Saída:
10/10/2020
```

```
Entrada:
10-11-2021

Saída:
10/11/2021
```