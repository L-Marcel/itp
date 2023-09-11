#include <stdio.h>

int main() {
  int a, b, c;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if(
    (b + c) > a &&
    (a + c) > b &&
    (a + b) > c &&
    a > 0 &&
    b > 0 &&
    c > 0
  ) {
    printf("possivel");
  } else {
    printf("impossivel");
  };

  return 0;
};