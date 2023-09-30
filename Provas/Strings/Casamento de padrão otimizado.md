# Casamento de padrão otimizado

Logo no início da pandemia, duas cientistas brasileiras mostraram ao mundo o potencial científico brasileiro sequenciando o genoma do Coronavírus que apareceu por aqui apenas 48h após a confirmação do primeiro caso de Covid no Brasil (na época, um recorde). É uma amostra da nossa capacidade quando há investimento na ciência.

O sequenciamento do genoma é essencial para identificar novas variantes, comparando com o sequenciamento de outros genomas. A comparação é então realizada através de algoritmos de casamento de padrões de texto (também conhecidos como pattern matching ou string-searching), já que o DNA pode ser representado por uma sequência de caracteres, cada um representando uma de suas bases nitrogenadas: adenina (A), citosina (C), guanina (G) ou timina (T).

Porém, realizar uma busca sem otimização alguma em uma sequência do DNA, que possui milhões de caracteres, pode ser muito custoso! O que fazer então para otimizar?

Há vários algoritmos que otimizam a busca, normalmente realizando um pré-processamento do padrão ou do texto antes. No momento, vamos explorar uma ideia simples, mas que pode ajudar tremendamente nossas cientistas na busca por padrões.

A ideia é, antes de realizar a busca propriamente dita, guardar a informação, para cada caractere do texto, se ele se encontra no padrão ou não. Isso ajudaria a busca "saltar" comparações quando um caractere não se encontra no padrão. Por exemplo, se tivermos um texto ACATACAGACAC e estivermos procurando o padrão ACAC. Em uma busca inocente (sem otimização), teríamos o seguinte deslocamento do padrão no processo de busca sobre o texto.

```
Texto:  A C A T A C G A C A C
Padrão: A C A C (compara A com A, depois C com C, depois A com A, depois C com T. Não casou! C é diferente de T)
          A (compara A com C. Não casou. A é diferente de C)
            A C (compara A com A, depois C com T. Não casou. C é diferente de T)
              A (não casou. A é diferente de T)
                A C A (não casou. A é diferente de G)
                  A (não casou. A é diferente de C)
                    A (não casou. A é diferente de G)
                      A C A C (casou!)
```

Porém, podemos já saber que T não se encontra no padrão e fazer um salto e recomeçar a busca logo após o T. A busca com esse novo mecanismo poderia ser assim:

```
Texto:  A C A T A C G A C A C
Padrão: A C A C (compara A com A, depois C com C, depois A com A, depois C com T. Não casou. C é diferente de T)
                (como não há T no padrão, podemos saltar)
                A C A (não casou. A é diferente de G)
                      (como não há G no padrão, podemos saltar)
                      A C A C (casou!)​
```
Ajude a ciência brasileira implementando uma busca por padrão sobre um texto usando a ideia descrita acima. Seu programa deve ler duas linhas da entrada-padrão. A primeira contém o texto sobre o qual o padrão será procurado, enquanto a segunda linha contém o padrão. Seu programa deve enviar para a saída padrão o processo do busca ocorrido, apresentando o caractere do texto que está sendo comparado a cada iteração e apresentando o texto "não" quando os caracteres do texto e do padrão forem diferentes e o texto "sim" quando houver o casamento completo do padrão.

A linha final da saída é informando se não houve casamento ("Não achei o padrão") ou se houve. Nesse caso, apresenta o índice no texto em que o casamento se encontra ("Achei o padrão no índice X").

Obs: Existem algoritmos de busca por padrão bem mais sofisticados do que a ideia apresentada aqui, mas alguns deles usam recursos similares, como o "índice da última ocorrência" dos caracteres do texto no padrão para realizar os saltos.

Obs: Nos testes, é garantido que nenhum texto será maior que 50 caracteres. 