# MDC e MMC recursivos

Implemente a função `calc_mdc_mmc (int x, int y, int *mdc, int *mmc)` que recebe como parâmetros de entrada dois números inteiros `x`` e `y` e calcula tanto o Máximo Divisor Comum (MDC) quanto o Mínimo Múltiplo Comum (MMC) entre eles, retornando seus valores nos parâmetros mdc e mmc, respectivamente. 

Esta função deve fazer chamadas a uma função auxiliar recursiva para calcular o MDC. Depois que calcular o MDC, use a relação abaixo para calcular o MMC da seguinte forma:

> MMC (x, y) = (x * y) / MDC(x, y)

Após implementar a função calc_mdc_mmc, implemente a função main, de modo que esta leia do usuário dois números inteiros e exiba na tela o MDC e o MMC entre os dois números, de acordo com o resultado da função.