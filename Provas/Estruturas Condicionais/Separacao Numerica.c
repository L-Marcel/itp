#include <stdio.h>

int main() {
  int digits[6] = {-1,-1,-1,-1,-1,-1};
  int number;

  scanf("%d", &number);
  
  int index = 5;
  while(number != 0) {
    int digit = number % 10;
    digits[index] = digit;
    index--;
    number = (number - digit) / 10;
  };

  for(int i = 0; i < 6; i++) {
    if(digits[i] != -1) {
      printf("%d\n", digits[i]);
    };
  };

  return 0;
};