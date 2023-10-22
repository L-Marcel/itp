# Vetor distinto

Crie um programa que receba uma sequência de n valores reais e então exibe somente os valores que não se repetem na sequência. Para isso, crie uma função que receba a sequência de valores e retorna um vetor contendo somente os valores distintos na mesma ordem em que foram apresentados ao programa. O tamanho do vetor retornado deve ser obtido através de passagem por referência.

O programa não deve utilizar variáveis globais e a função não deve exibir dados na saída padrão, isto é, não deve fazer chamadas a função printf ou similar. Além disso, o tamanho do vetor retornado deve ser igual a quantidade de elementos distintos e a saída deve ser formatada como exibido nos exemplos de entrada e saída. Lembre de liberar a memória alocada dinamicamente.

# Entrada / Saída

```
Entrada:
5
1 2 3 4 5

Saída:
[1.0000, 2.0000, 3.0000, 4.0000, 5.0000]
```

```
Entrada:
6
1.1 2.0 1.0 5.2 8.3 8.3

Saída:
[1.1000, 2.0000, 1.0000, 5.2000]
```