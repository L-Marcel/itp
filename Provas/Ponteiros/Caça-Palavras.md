# Caça-Palavras

Quando criamos uma matriz A[M][N], por exemplo int A[2][4], imaginamos uma estrutura bidimensional com M linhas e N colunas, como abaixo:

A[0][0]
A[0][1]
A[0][2]
A[0][3]
A[1][0]
A[1][1]
A[1][2]
A[1][3]
No entanto, a memória do computador é linear e os dados da estrutura matricial acima são armazenados consecutivamente, tal como em um vetor:

*(A+0)
*(A+1)​
*(A+2)​
*(A+3)​
*(A+4)​
*(A+5)​
*(A+6)​
*(A+7)​
A[0][0]
A [0][1]
A[0][2]
A[0][3]
A[1][0]
A[1][1]
A[1][2]
A[1][3]
O identificador da matriz ('A', no exemplo) é um ponteiro para o endereço de memória do primeiro elemento, e o acesso aos demais ocorre, basicamente, por aritmética de ponteiros. Em uma matriz bidimensional MxN, o item [r][s] é alcançado através do salto de r*N+s elementos a partir do ponteiro inicial.

Exemplo:

A[1][2]

salto=r*N+s -->

salto=1*4+2

salto=6

Logo, o acesso ao elemento A[1][2] pode ser feito através de *(A+6)



Atividade:

Implemente um caça-palavras utilizando ponteiros. Seu código principal será responsável por receber as entradas e chamar as funções de localização de palavras (implementada por você) e impressão (mostrada abaixo).

A função de localização de palavras deverá receber como parâmetros a matriz de caracteres e a palavra a localizar. Deverá fornecer como resultados o endereço de memória do primeiro caractere da palavra encontrada na matriz de caracteres (ou NULL, caso contrário) e a quantidade de saltos para cada caracter seguinte.

Observação: em caso de uma palavra em mais de um localização, considerar apenas o menor endereço.

Para cada palavra de entrada, seu programa deverá gerar uma linha de saída utilizando a função abaixo:

```c
void imprimePalavra (char *c, int salto, int tam) {
    if (c==NULL) {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i=0; i<tam; i++) {
        printf("%c", *c);
        c+=salto;
    }
    printf(", salto:%d\n", salto);
}
```

A função recebe como parâmetros:

o endereço do primeiro caractere da palavra encontrada na matriz de caracteres, gerado pela função de localização de palavras;
a quantidade de saltos para cada caracter seguinte, gerado pela função de localização de palavras;
o tamanho da palavra.


Entrada do programa:

a quantidade de palavras a procurar (máximo de 5);
as palavras a procurar, uma por linha.
uma matriz de caracteres 10x10, com uma linha de 10 letras por vez.


# Entrada / Saída

```
Entrada:
3
casa
RATO
ave
LRFKqYUqfJ
kxYqvnrtYs
fRZRMZLygf
VeULqFPdbh
LQdQRRcrWd
NxEUoqrEKL
aitgasACsp
iJThBSTYFV
LadZpboUDK
kLRWQaoZmI

Saída:
CAsa, salto:-1
rATo, salto:10
Palavra nao encontrada
```

```
Entrada:
5
venca
Torre
Derrota
ITP
desistir
hzVHzUIcvh
hUaWlqffxc
SFAFqAaXVv
RsIhcPcpjY
hIpCczNfOM
taToRReDSk
gbIPpwvgiT
bEFBgfvUVR
najdZGVOPk
EhcrZgtdKB

Saída:
veNca, salto:-10
ToRRe, salto:1
DeRRoTa, salto:-1
ITP, salto:11
Palavra nao encontrada
```