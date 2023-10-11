# Assuma o controle

Durante o roubo, (La Casa de Papel) o Professor e sua equipe decidiram que sua equipe precisava manter o máximo controle de que estava operando em cada parte da Casa da Moeda para que dessa forma eles não perdessem nada do que estavam e não deixassem de lucrar 1 centavo.

Para isso eles anotavam em um quadro branco todos que estavam trabalhando nos setores, mas Berlim, que estava no comando de toda essa organização dentro da casa da moeda, percebeu que ficar atualizando constantemente essas informações estava tomando muito seu tempo e decidiu pedir sua ajuda para manter a ordem.

Ele lhe deu a tarefa de criar um programa que guardasse a lista de pessoas que estavam trabalhando na casa naquele momento e, quando fosse solicitado por Berlim, fosse impresso o nome de todos que estavam presentes naquele instante. Sabe-se que os reféns estão frequentemente trocando de turno, por isso, há gente sempre saindo e entrando na produção.

Construa sua solução declarando e usando pelo menos um tipo estruturado criado por você.

## Tipo de entrada

Um inteiro N, seguido de N linhas (até o fim da entrada) que podem estar em um desses 3 formatos:

- INSERIR Nome 
- REMOVER Nome   
- IMPRIMIR

Onde Nome corresponderá ao nome da pessoa a qual se referencia a ação de entrada ou saída. Para cada vez que for solicitada a impressão da lista, por meio da frase "IMPRIMIR", deverá ser impressa a seguinte frase (seguido de uma lista com X nomes, sendo X a quantidade de pessoas que estão trabalhando naquele momento):

```
Atualmente trabalhando:
Nome1
Nome2
...
NomeX
```

Seguido de uma linha em branco ao final de cada impressão da lista.

# Entrada / Saída

```
Entrada:
5
INSERIR Daniel
REMOVER Daniel
INSERIR Ramon
INSERIR Daniel
IMPRIMIR	

Saída:
Atualmente trabalhando:
Ramon
Daniel
```
```
Entrada:
8
INSERIR Daniel
INSERIR Sergio
INSERIR Ricardo
INSERIR Ramon
IMPRIMIR
REMOVER Daniel
REMOVER Ramon
IMPRIMIR	

Saída:
Atualmente trabalhando:
Daniel
Sergio
Ricardo
Ramon

Atualmente trabalhando:
Sergio
Ricardo
```