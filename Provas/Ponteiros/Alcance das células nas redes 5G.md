# Alcance das células nas redes 5G

D e As redes 5G prometem revolucionar nossas vidas possibilitando aplicações que requerem um grande tráfego de dados com baixa latência. Porém, a implementação da rede requer uma infraestrutura diferente da existente atualmente, em especial com relação às estações base. As redes 4G LTE já usam um número grande de estações, mas a 5G precisará de um número ainda maior, apoiada no conceito de pequenas células (small cells). Small Cells são estações base que requerem potência mínima para operar e podem ser colocadas a cada 100 metros nas regiões de alto tráfego, indo até 1 km em zonas suburbanas.

Você foi contratado por uma operadora de celular para ajudar na programação do tráfego de dados por diferentes células. A primeira fase do projeto constitui em criar um protótipo de tráfego de dados, apenas para simular o funcionamento. Nesse protótipo, a cidade foi modelada em uma única dimensão. Logo, todos os locais da cidade são definidos em uma reta, cuja origem é a central da operadora. A localização dos pontos da cidade é então definida através da distância que eles se encontram da central.

Sua tarefa neste protótipo é escrever uma função que identifique o grupo de células que um usuário da rede tem acesso. Para isso, sua função recebe uma lista de células da cidade, ordenada em relação à origem (central da operadora), a distância que o sinal das células alcança e a posição do usuário (também referente à central da operadora). Sua função deve então retornar a quantidade de células que o usuário consegue sinal, bem como calcular os índices das células que limitam o alcance do usuário. Por exemplo, se as células se encontram nas posições -50, -30, -25, 0, 10, 50, 60 e 70, o alcance das células for de 30 e o usuário se encontrar na posição 35, então os índices devem ser ajustados para 4 (índice do valor 10) e 6 (índice do valor 60).

Sua função deve então ter a seguinte assinatura:
```c
int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index);
```

Escreva um programa que utilize esta função. A entrada de seu programa consiste em uma primeira linha com três valores inteiros, N, D e U, que correspondem respectivamente ao número de células, a distância que as células alcançam e a posição do usuário. Em seguida, haverá N linha, cada uma contendo a posição de uma célula em ordem crescente de sua posição. O programa deverá imprimir as células que se encontram no alcance do usuário. Caso não haja célula que dê cobertura ao usuário, a mensagem USUARIO DESCONECTADO deverá ser impressa.

# Entrada / Saída

```
Entrada:
8 30 35
-50
-30
-25
0
10
50
60  
70

Saída:
10 50 60
```

```
Entrada:
5 15 20
-20
-15
-10
-5
0

Saída:
USUARIO DESCONECTADO
```