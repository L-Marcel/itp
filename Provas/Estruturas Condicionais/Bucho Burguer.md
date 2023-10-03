# Bucho Burguer

Uma das franquias fictícias de maior sucesso, especializada em sanduíches regionais, é o Bucho Burger. Porém, apesar de ser muito bom em fazer sanduíches, o seu dono não é tão apto a fazer contas de matemática, e frequentemente tem problemas para acertar o troco ou saber quando está faltando alguma coisa no pagamento.

Para minimizar o prejuízo do estabelecimento e o descontentamento dos clientes quando recebem o troco errado, o Bucho Burger resolveu contratar você para fazer um programa simples de caixa. Você fará um programa que recebe o código do pedido e o valor em dinheiro pago pelo cliente, e informará se o valor está correto, se precisa de troco ou se está faltando dinheiro.

Os preços dos combos de sanduíches do Bucho Burger, acompanhados de fritas arretadas e suco de pitomba, são de acordo com a tabela abaixo:

Combos Bucho Burguer

1 - Bucho de Panela = R$ 12

2 - Bucho Inchado = R$ 23

3 - Bucho Duplo = R$ 31

4 - Bucho No Queixo = R$ 28

5 - Buchinho Fit = R$ 15

Seu programa receberá dois valores inteiros, correspondentes ao número do combo e a quantidade de dinheiro fornecida pelo cliente.

Seu programa deve então informar uma de três situações possíveis:

1 - Se houver troco, ele deve imprimir a mensagem "Troco = X reais", onde X é o valor do troco devido ao cliente.

2 - Se não houver troco, ele deve imprimir a mensagem "Deu certim!".

3 - Se faltar dinheiro para completar o valor do combo, ele deve imprimir a mensagem "Saldo insuficiente! Falta X reais", onde X é a quantia que falta para chegar ao valor do combo escolhido.

Exemplos:

- Se a entrada do programa for 1 12, seu programa imprimirá "Deu certim!" porque o valor do combo 1 é 12 reais, e não há troco para o cliente.

- Se a entrada do programa for 4 23, seu programa imprimirá "Saldo insuficiente! Falta 5 reais", porque o valor do combo 4 é de 28 reais.

# Entrada / Saída

```
Entrada: 
1 12

Saída:
Deu certim!
```

```
Entrada:
4 23

Saída:
Saldo insuficiente! Falta 5 reais
```