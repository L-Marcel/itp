# Cálculo de média aritmética e ponderada

Antigamente, o cálculo da média na UFRN era calculado através da média ponderada, com pesos 4, 5 e 6: 

Média Ponderada = ((Nota1 * 4) + (Nota2 * 5) + (Nota3 * 6)) / 15

Exemplo, se um aluno tirou as notas 8.00, 7.00 e 6.00, sua média é 6.87.((8.00 x 4) + (7.00 * 5) + (6.00 *6)) / 15 = 6.87.  Atualmente, o cálculo da média na UFRN é uma média aritmética das três notas obtidas em cada unidade, o que daria uma média 7.00:

​Média Aritmética = (Nota1 + Nota2 + Nota3) / 3​

Escreva um programa que implemente uma função que retorne o cálculo da média desejada e possua o seguinte cabeçalho:

float calculaMedia(char tipo, float n1, float n2, float n3)

onde tipo é pode ser 'A' para o cálculo da média aritmética ou 'P' para o cálculo da média ponderada com os pesos 4, 5 e 6, e n1, n2 e n3 são as notas das três unidades. A função main() deve pedir primeiro o tipo de média a ser calculada seguida das três notas e exibir o cálculo da média com duas casas decimais. 