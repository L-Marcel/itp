# Concorrência no BTI

O Bacharelado em Tecnologia da Informação é um curso com muitos discentes e a concorrência por vagas nas turmas se torna bastante alta no período de matrículas. Na rematrícula, nem se fala... o número de vagas se torna mínimo e representam somente aquelas vagas não preenchidas na matrícula ou provenientes de desistência (mudança de turma, por exemplo) de alguém que conseguiu a vaga. 

Um dos critérios de desempate é o desempenho dos alunos no curso. Além disso, existe o fator de reserva de vagas para um determinado turno, em que somente os alunos daquele turno podem conseguir as vagas (se sobrar vagas, os alunos do outro passam a concorrer). Sem entender direito como isso tudo funciona, você resolveu implementar um algoritmo semelhante ao utilizado pelo SIGAA simular a concorrência e se situar melhor.

Então, uma versão simplificada do SIGAA usa a seguinte estrutura para representar um discente:

```c
typedef struct discente{  
    char nome[100];  
    float mc;  
    char turno;
}Discente;
```

Nesse caso, `mc` é a média de conclusão do aluno (aquela que aparece no histórico) e o `turno` é um único caracter `d` (diurno) ou `n` (noturno).

A simulação que você vai implementar vai receber:

- o nome da turma (string de no máximo 50 caracteres);
- o número n de vagas disponíveis para rematrícula (inteiro positivo);
- o turno t da turma (char n ou d);
- o número m de alunos que estão concorrendo às vagas (inteiro positivo);
- conjunto de dados de m discentes na forma:
  - nome (string de até 100 caracteres);
  - média de conclusão (float);
  - turno (char).

O seu objetivo é mostrar o nome dos alunos que conseguem a vaga. Esses alunos são aqueles que possuem as maiores médias de conclusão entre os candidatos. Nessa simulação, considere que as médias de conclusão são sempre valores positivos e não são iguais entre os discentes. Considere também que a reserva de vagas elimina a possibilidade de um discente de um turno distinto daquele reservado ser selecionado. 

# Entrada / Saída

```
Entrada: 
Introdução às Técnicas de Programação
2
d
4
Princesa Peach
9.8
n
Mario
7.8
d
Luigi
9.5
d
Shy Guy
4.3
d

Saída:
Luigi
Mario
```

```
Entrada:
Estruturas de Dados Básicas I
1
n
3
Huguinho
5.6
d
Zezinho
6.0
n
Luizinho
7.9
n

Saída:
Luizinho
```