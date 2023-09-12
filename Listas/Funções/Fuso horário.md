# Fuso horário

Joseph é um empresário que vive viajando a negócios. Sempre que chega em um novo país, ele precisa ajustar as horas de seu relógio devido ao fuso horário. Em sua última viagem, Joseph esqueceu de modificar as horas de seu relógio e acabou perdendo uma reunião importante.

Para que esteja melhor preparado das próximas vezes, Joseph pediu que você criasse um programa que o ajude a saber o horário de chegada no seu destino. Para isso, crie um programa que recebe a hora do relógio na partida S (0 <= S <= 23), o tempo de viagem T (1 <= T <= 12) e a diferença de horário entre o destino e a sua localização atual F (-5 <= F <= 5). Crie uma função que recebe S, T e F como parâmetros de entrada e deve imprimir a hora de partida e chegada do relógio de Joseph.

Por exemplo, se Joseph sair às 10 horas para uma viagem que dura 4 horas, com destino para uma zona com fuso horário que possui uma hora extra, em relação ao ponto de partida, a hora de chegada será 10 + 4 + 1, com isso seu relógio deve apresentar 15 horas em sua chegada. Note que caso a hora calculada seja 24, seu programa deve imprimir 0 (zero).