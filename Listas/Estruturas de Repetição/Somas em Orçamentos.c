#include <stdio.h>

int main() {
  int amount = 0;
  float price = 0;

  while(1) {
    int input_amount;
    float input_price;
    scanf("%d", &input_amount);
    
    if(input_amount == -1) {
      break;
    };

    scanf("%f", &input_price);
    amount += input_amount;
    price += (input_price * input_amount);
  };

  printf("%d %.2f", amount, price);
  return 0;
};