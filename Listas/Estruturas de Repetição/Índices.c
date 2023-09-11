#include <stdio.h>

int main() {
  int amount;
  scanf("%d", &amount);

  int count = 0;
  float average = 0;
  while(amount > 0) {
    float input;
    scanf("%f", &input);

    if(input != -1) {
      count++;
      average += input;
    };

    amount--;
  };

  if(count == 0) {
    printf("A competicao nao possui dados historicos!");
    return 0;
  };

  average = average/count;
  printf("%.2f", average);
  return 0;
};