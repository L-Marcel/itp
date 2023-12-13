# Carregando dados heterogêneos a partir de strings

O formato CSV que significa “comma-separated-values” (valores separados por vírgulas) é um tipo de estrutura textual muito utilizado para transferência de informações entre aplicativos diferentes. O Microsoft Excel, por exemplo, permite importar os dados de uma planilha a partir de um arquivo texto nesse formato.

Imagine que queremos ler os dados de produtos de uma loja a partir de um arquivo CSV. Cada produto possui os seguintes campos:

```c
int codigo;
char descricao[20];
float preco;
```

Assim, um exemplo de conteúdo para este arquivo seriam as linhas:

```
123,Agua Sanitaria,12.54
324,Farinha Lactea,8.89
657,Vassoura,20.01
\n
```

Faça um programa em C que permita ler a partir da stdin as linhas de um arquivo csv e inserir em um vetor de produtos os dados de cada produto lido, caso tal produto ainda não tenho sido inserido. Ao final, exiba todos os produtos deste vetor na tabela:

```
=======================================
| Código | Descrição       | Preço    |
---------------------------------------
|    123 |  Agua Sanitaria | R$ 12.54 |
|    324 |  Farinha Lactea | R$  8.89 |
|    657 |        Vassoura | R$ 20.01 |
---------------------------------------
```

## Dicas

Use as funções atoi(char str[]) e atof(char str[]) da string.h que convertem str para inteiro e float, respectivamente, quando estiver pegando o código e o preço do produto;
Use as funções abaixo para ler cada linha do arquivo "stdin" e para exibir a tabela de produtos, respectivamente:

```c
void read_line(char linha[30], int tam) {
    fgets(linha, tam, stdin);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1]='\0'; //remove o \n do final
}

void imprimeProdutos(Produto prod[], int qtdprod) {
    printf("========================================\n");
    printf("| Código | Descrição       | Preço     |\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < qtdprod; i++) {
        printf("| %6d ", prod[i].codigo);
        printf("| %15s ", prod[i].descricao);
        printf("| R$ %6.2f |\n", prod[i].preco);
    }
    printf("----------------------------------------\n");
}
```

# Entrada / Saída

```
Entrada:
123,Agua Sanitaria,12.54
324,Farinha Lactea,8.89
657,Vassoura,20.01
324,Farinha Lactea,8.89
123,Agua Sanitaria,12.54
657,Vassoura,20.01

Saída:
========================================
| Código | Descrição       | Preço     |
----------------------------------------
|    123 |  Agua Sanitaria | R$  12.54 |
|    324 |  Farinha Lactea | R$   8.89 |
|    657 |        Vassoura | R$  20.01 |
----------------------------------------
```