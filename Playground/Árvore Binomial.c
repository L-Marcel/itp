#include <stdio.h>
#include <stdlib.h>

int factorial(int a) {
  if(a <= 0) return 1;
  return a * factorial(a - 1);
};

int combinations(int a, int b) {
  return factorial(a)/(factorial(b) * factorial(a - b));
};

void tree(int node, int start) {
  if(node < start) return;

  for(int i = 0; i <= start; i++) {
    printf("%d ", combinations(start, i));
  };

  printf("\n");
  tree(node, start + 1);
};

int main() {
  int n;
  scanf("%d", &n);
  getchar();

  tree(n, 0);

  return 0;
};