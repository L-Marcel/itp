#include <stdio.h>
#include <string.h>

int main() {
  char type;
  float temperature;

  float c, f, k;
  scanf("%f %c", &temperature, &type);

  if(type == 'C') {
    c = temperature;
    k = c + 273.15;
    f = (c * 1.8) + 32;
  } else if(type == 'K') {
    k = temperature;
    c = k - 273.15;
    f = (c * 1.8) + 32;
  } else {
    f = temperature;
    c = (f - 32) / 1.8;
    k = c + 273.15;
  };

  printf("Celsius: %.2f\nFarenheit: %.2f\nKelvin: %.2f", c, f, k);

  return 0;
};