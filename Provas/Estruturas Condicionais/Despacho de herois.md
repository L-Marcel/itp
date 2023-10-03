# Despacho de heróis

A associação de heróis decidiu criar um sistema para minimizar as baixas de seus membros no combate a monstros. Ocasionalmente, um grupo de heróis mais fraco acabava sendo enviado para enfrentar um monstro muito forte, e a associação perdia muitos membros de seus rankings. Para isso, a associação resolveu avaliar a classificação dos heróis e o nível de ameaça dos monstros, e a partir de uma análise minuciosa de dados feita por um de seus heróis, Kid Emperor, criou regras para o envio das equipes.

A classificação dos heróis quanto a força é feita de acordo com a seguinte tabela:

1 - Heróis classe C

2 - Heróis classe B

3 - Heróis classe A

4 - Heróis classe S

5 - Saitama

Já a classificação dos monstros em nível de ameaça é feita de acordo com a seguinte tabela:

1 - Monstro nível Lobo (ameaça pequenos grupos de pessoas)

2 - Monstro nível Tigre (ameaça um grande número de pessoas)

3 - Monstro nível Demônio (pode destruir uma cidade inteira)

4 - Monstro nível Dragão (pode destruir um continente inteiro)

5 - Monstro nível Divindade (pode exterminar a raça humana)

Observando esses dois grupos, Kid Emperor percebeu que:

- Para eliminar uma ameaça do nível Lobo, é necessário um herói classe B ou acima, ou pelo menos 3 heróis classe C

- Para eliminar uma ameaça do nível Tigre, é necessário um herói classe A ou acima, ou pelo menos 3 heróis classe B

- Para eliminar uma ameaça do nível Demônio, é necessário um herói classe S ou acima, ou pelo menos 3 heróis classe A

- Para eliminar uma ameaça do nível Dragão, é necessário Saitama, ou pelo menos 3 heróis classe S

- Para eliminar uma ameaça do nível Divindade, apenas Saitama consegue lidar.

Como Kid Emperor é um herói classe S e muito ocupado, ele não teve tempo de implementar o algoritmo que faz a análise da ameaça e diz se a equipe escolhida vai vencer ou não o monstro. Por isso, a associação escolheu você para essa tarefa.

O seu programa vai receber 3 valores inteiros, na seguinte ordem:

- Quantidade de heróis que serão enviados

- Um valor indicando a classe dos heróis (todos são da mesma classe), de acordo com a tabela acima

- Um valor indicando o nível de ameaça do monstro, de acordo com a tabela acima


Por exemplo:

- Se a entrada do programa for 3 1 1 significa que serão enviados 3 heróis de classe C (1) para combater um monstro de nível Lobo (1). Vai dar tudo certo!

- Se a entrada for 1 2 4 significa que será enviado 1 heróis da classe B (2) para combater um monstro de nível Dragão (4). Não é uma boa ideia.

Seu programa deve, a partir dessas informações, imprimir a mensagem "Heróis vencerão!" se a equipe escolhida for capaz de vencer a ameaça, ou "Melhor chamar Saitama!" se a equipe não for capaz de vencer a ameaça.

Observem os casos de teste para verificar a formatação tanto da entrada quanto da saída.

# Entrada / Saída

```
Entrada: 
1 2 4

Saída:
Melhor chamar Saitama!
```

```
Entrada:
3 1 1	

Saída:
Heróis vencerão!
```