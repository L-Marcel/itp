# Valores únicos

Em grandes bases de dados, é comum existirem múltiplas entradas referentes a um mesmo sujeito. Por exemplo, um empresa de cartões de crédito possuem os registros das compras de todos os seus clientes. Ou seja, para um mesmo cliente, podem existir diversas entradas no banco de dados da empresa, cada uma referente a uma transação do seu cartão de crédito.

Uma dessas empresas modelou seu banco de dados inicialmente com apenas uma tabela para armazenar os dados das transações. Após um tempo, o CEO quis saber o quanto a empresa tinha evoluído e solicitou um relatório com o número de clientes da empresa. No entanto, ao verificar o banco de dados, percebeu-se que não daria para obter o número de clientes tão facilmente, uma vez que um mesmo cliente aparecia várias vezes.

A equipe de suporte conseguiu, no entanto, isolar em um vetor somente os códigos dos clientes de todas as transações. Ele solicitou a você conseguisse isolar somente os valores únicos desse vetor. Por exemplo, para o seguinte vetor:

`[2 3 10 222 1 2 2 3 10 15]`

os clientes que realizaram a transação são:

`[1 2 3 10 15 222]`

Seu programa vai receber duas entradas: um inteiro informando o tamanho do vetor (sempre um inteiro positivo) e o vetor em si contendo os códigos dos clientes (que serão sempre inteiros). A saída deve ser o conjunto de códigos de clientes únicos ordenados de forma crescente.

# Entrada / Saída
```
Entrada:
10
2 3 10 222 1 2 2 3 10 15

Saída:
1 2 3 10 15 222
```
```
Entrada:
5           
3 3 3 1 2

Saída:
1 2 3
```