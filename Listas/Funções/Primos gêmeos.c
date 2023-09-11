#include <stdio.h>
#include <stdbool.h>

bool prime(int x) {
  if(x == 1) {
    return false;
  };

  for(int i = 2; i < x - 1; i++) {
    if(x % i == 0) {
      return false;
    };
  };

  return true;
};

int main() {
  int x;
  scanf("%d", &x);

  bool has_twin_primes = prime(x) && prime(x + 2);

  if(has_twin_primes) {
    printf("Numero forma par de gemeos");
  } else {
    printf("Numero nao forma par de gemeos");
  };

  return 0;
};