# Experimento em Marte

Com o avanço da exploração do planeta Marte por vários países, os governos mundiais começam a ficar mais ousados em relação aos experimentos que desejam executar. Após analisar várias condições do planeta, tentando não contaminar o estado natural com elementos de vida da Terra (o que praticamente impossível), chegou a hora de passar para uma nova etapa: verificar se é possível reproduzir condições similares ao que temos no nosso planeta a partir de terraformação.

Um primeiro passo que os cientistas querem descobrir é a possibilidade de reproduzir biomas existentes no nosso planeta em Marte. Para isso, eles querem iniciar com testes simples: se existe a possibilidade de crescer um determinado tipo de planta em alguma região do planeta. Para isso, os cientistas inventaram uma fórmula que leva em conta 300 variáveis para definir um índice de sobrevivência da planta baseada em diversos elementos do terreno: composição mineral, temperatura da região, ventos, etc.... Os cientistas também definiram que para a planta ser considerada um sucesso, é necessário que ela ocupe uma área de tamanho 3x3 na superfície do planeta, logo seria necessária que o valor das variáveis espalhadas por essa área totalizassem um valor igual ou o mais próximo possível desse índice de sobrevivência (dado que uma área pode compensar recursos que outra área não tem, e as duas juntas sustentarem a planta).

Agora você precisa ajudar a humanidade em seu esforço de colonização interplanetária, e fazer um programa que determina a melhor área do planeta para o drone plantar as sementes da planta.

Seu programa vai receber como entrada os seguintes valores: as dimensões da área investigada N x M, indicando um mapa retangular com N linhas e M colunas, mapeando uma área da superfície. Seu programa também receberá um valor S, indicando o índice de sobrevivência da planta.

Em seguida, seu programa receberá N x M valores, indicando as notas de cada uma das áreas do planeta em função das variáveis similares as que foram utilizadas para calcular o índice S da planta. Seu programa deve então procurar uma região 3x3 no mapa onde a soma dos valores obtidos seja a mais próxima possível do índice S da planta, de forma que ela tenha mais chances de sobreviver. Caso duas regiões tenham o mesmo valor, escolha a primeira que for encontrada.

Por exemplo, imagine que a entrada do seu programa é

4 4 10

Ou seja, um mapa 4x4, e o índice de sobrevivência da planta é 10.

E os seguintes valores mapeiam os recursos do terreno:

1 1 1 3
1 1 1 1
1 1 1 2
5 1 1 1

A imagem do link mostra as possíveis áreas 3x3 com seus valores (constituídos pela soma dos recursos de cada um dos espaços da área).

Imagem: [Exemplo das áreas](https://docs.google.com/drawings/d/1TxSfPjzRe1QUchZ6OM8E18TXnB7KgCGIzbYK9D8uQa4/edit)

Como vocês podem ver na imagem, a melhor área para mandar as sementes da planta é a quarta área, que inicia na posição 2, 2 e possui valor de 10, porque é a mais próxima do valor de sobrevivência 10 da planta (igual na verdade!).

A saída do seu programa vai ser um texto no seguinte formato:

A melhor area para exploracao eh X Y com valor M, onde X e Y são as posições da linha e coluna iniciais da área que possui o valor mais próximo do índice de sobrevivência da planta, e M é a diferença desse valor para o valor do índice de sobrevivência.

Para o exemplo acima, a saída do seu programa seria:

A melhor area para exploracao eh 2 2 com valor 0

# Entrada / Saída

```
Entrada: 
4 4 10
1 1 1 3
1 1 1 1
1 1 1 2
5 1 1 1

Saída:
A melhor area para exploracao eh 2 2 com valor 0
```

```
Entrada:
5 5 68
9 7 12 4 -30
18 8 50 25 28
7 5 1 0 15
2 30 27 8 11
1 17 0 1 3

Saída:
A melhor area para exploracao eh 3 3 com valor 2
```