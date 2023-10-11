# Reflexão vertical de imagem (mirror) 2

Elabore um programa para realizar a reflexão horizontal de uma imagem. Para isso, você deve necessariamente implementar uma função que vai realizar a reflexão. Essa função deve receber como parâmetro de entrada uma imagem e como parâmetro de saída uma outra imagem. A função deve realizar uma reflexão nos valores dos pixels da imagem de entrada em torno de um eixo horizontal localizado no centro da imagem (reflexão vertical), armazenando o resultado no parâmetro de saída.

Preste bastante atenção em como a reflexão é realizada a partir dos exemplos.

As imagens são de um tipo definido a partir de um struct chamado Img que contém a altura, largura e os valores de pixel da imagem.

Utilize essa assinatura para a função:

```c
Img reflete(Img img_in, Img img_out);
```

Limites:

​1 ≤ lagura ≤ 201
​1 ≤ altura≤201
​0 ≤ matriz[i][j] ≤ 255

# Tipo de entrada

Na primeira, linha dois números inteiros para especificar as dimensões da matriz, n e m. Nas n​ linhas seguintes, m​ inteiros separados por espaço indicando o nível de brilho de cada pixel, totalizando n⋅m valores.

# Tipo de saída

Saídas esperada: devem ser impressas as dimensões da imagem, altura e largura, em uma linha seguidas de nnn​ linhas cada uma com mmm​​ colunas com os níveis de brilho da imagem.

# Entrada / Saída

```
Entrada:
5 5
255 255 0 0 255
255 255 0 255 0
0 0 0 0 0
0 255 0 0 255
0 0 0 255 255

Saída:
5 5
0  0  0  255  255
0  255  0  0  255
0  0  0  0  0
0  255  0  0  255
0  0  0  255  255
```
```
Entrada:
5 5
255 0 255 255 0
0 0 255 255 255
255 255 255 255 255
0 255 255 0 255
0 0 255 255 255

Saída:
5 5
0  0  255  255  255
0  255  255  0  255
255  255  255  255  255
0  255  255  0  255
0  0  255  255  255
```