# CRUD - Com alocação dinâmica

CRUD é uma das principais atividades que fazemos em qualquer sistema de informação. Como o nome já remete, essa expressão vem do ato de Criar, Ler, Atualizar e Deletar informações, essa expressão é bem comum no desenvolvimento WEB mas também em sistemas menores estaremos sempre fazendo uma parte deste trabalho.

Para fazer CRUD em C uma das principais partes é modelar os dados que estarão envolvidos nas operações. Nossos dados serão o clássico de uma Pessoa: nome (sem limite de caracteres), idade (um número inteiro), sexo (uma dentre três possibilidades M-masculino, F-feminino, N-nao informado). 

​- Modele um registro (struct) que possa ser usada para armazenar os dados no formato especificado.

- O programa deve armazenar qualquer número de entradas recebido (use alocação dinâmica para um vetor da struct modelada).

Usando a struct e o vetor de structs, implemente as seguintes funções:

- criar: uma função que recebe como parâmetro os valores a serem preenchidos nos campos do registro: nome, idade e sexo; a função retorna uma struct preenchida com os campos fornecidos. 

- inserir: uma função que recebe como parâmetro o vetor de structs, contendo todas as entradas até agora, e uma struct do formato especificado. A função deve inserir a struct recebida no fim do vetor.

- deletar: uma função que recebe uma struct do formato projetado e um vetor com os elementos atualmente adicionados. A função deve buscar o elemento dentro do vetor e deletar este elemento. Um elemento só é considerado igual a outro quando todos os seus campos são iguais. Após deletar, a função deve atualizar o vetor de elementos para conter apenas elementos válidos (desloque todos os elementos depois do deletado uma posição para trás)​

- imprimir: uma função que recebe um vetor de structs com o formato projetado e imprime todos os elementos válidos no vetor.​

# Entrada / Saída

```c
Entrada: 

Saída:

```

```c
Entrada:

Saída:

```