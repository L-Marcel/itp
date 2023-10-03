#include <stdio.h>
#include <math.h>

int main() {
  float max;
  scanf("%f", &max);

  int amount = 0;
  while(1) {
    float input;
    scanf("%f", &input);
    if(input == -1) {
      break;
    };

    if(input <= max) {
      amount++;
    };
  };

  float rounds = ceil(amount / 8.0);
  printf("%d %.f", amount, rounds);

  return 0;
};