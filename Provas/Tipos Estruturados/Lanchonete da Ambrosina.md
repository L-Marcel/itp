# Lanchonete da Ambrosina

Ambrosina é de lua. Quase todo dia ela quer mudar o cardápio de sua lanchonete. Ambrósio, o programador do sistema, não agüenta mais alterar o código do programa todas as vezes que Ambrosina muda o humor. Então Ambrósio resolveu mudar o software de forma que Ambrosina possa cadastrar o cardápio todas as manhãs, ao iniciar o software.

O software lê a quantidade de produtos a serem cadastrados, e depois o código de LED instalada na lanchonete seguidos pela descrição e preço do produto. Os clientes escolhem os produtos pelo código.

Se o cliente pede um produto não cadastrado ou uma quantidade negativa o pedido é considerado inválido.

O sistema calcula quantos itens o cliente escolheu de cada código e imprime o total da conta, sem descontos! Eita Ambrosina sovina !!

## Tipo de entrada

Consiste de um inteiro n, representando o número de produtos a serem cadastrados.

Depois, segue o cadastro dos n produtos, onde serão lidos para cada produto: um inteiro representando o código de LED, uma descrição do produto e um número real representando o preço. Depois, são lidos os pedidos. O pedido consiste do código do produto e da quantidade de itens daquele produto que será pedido. O pedido se encerra quando o código lido é igual a 0.

## Tipo de saída

O valor que o cliente deve pagar, formatado com duas casas decimais. Pedidos inválidos são ignorados.

# Entrada / Saída

```
Entrada: 
3
501
Guarana Antartica
1.50
101
Coxinha
2
10
Cheese Frango
3.50
501
2
101
3
0

Saída:
9.00
```