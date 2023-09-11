#include <stdio.h>
#include <stdlib.h>

double fib(int position) {
  double pre = 0;
  double number = 1;

  for(int i = 1; i < position; i++) {
    double old = number;
    number += pre;
    pre = old;
  };

  return number;
};

int main() {
  int position;
  scanf("%d", &position);
  printf("%.f", fib(position));
  return 0;
};