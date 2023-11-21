#include <stdio.h>
#include <math.h>

unsigned long long to_binary(int number) {
  unsigned long long calc_binary(int number, int place) {
    int binary = number % 2;

    unsigned long long result = binary * pow(10, place);

    if(number < 2) {
      return result;
    };
    
    return result + calc_binary(number / 2, place + 1);
  };

  return calc_binary(number, 0);
};

int main() {
  int number;
  scanf("%d", &number);
  printf("%llu", to_binary(number));
  return 0;
};