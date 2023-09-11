#include <stdio.h>
#include <math.h>

int main() {
  float average = 0;
  float harmonic_average = 0;
  float geometric_average = 1;

  for(int i = 0; i < 10; i++) {
    float current_number;
    scanf("%f", &current_number);
    average += current_number;
    geometric_average *= current_number;
    harmonic_average += (1/current_number);
  };

  harmonic_average = 10/harmonic_average;
  geometric_average = pow(geometric_average, 0.1);
  average = average/10;

  float harmonic_error = (harmonic_average - average)/average;
  float geometric_error = (geometric_average - average)/average;
  float error = ((harmonic_error + geometric_error)/2)*100;

  printf(
    "Média aritmética é %.2f\nMédia harmônica é %.2f\nMédia geométrica é %.2f\nErro médio é %.2f %%",
    average,
    harmonic_average,
    geometric_average,
    error
  );
  return 0;
};