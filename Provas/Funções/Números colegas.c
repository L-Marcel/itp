#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int div_sum(int x) {
  int count = 0;

  for(int i = 1; i < x - 1; i++) {
    if(x % i == 0) {
      count += i;
    };
  };
  
  return count;
};

bool is_friends(int x, int y) {
  return 
    abs(div_sum(x) - y) <= 2 && 
    abs(div_sum(y) - x) <= 2;
};

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  is_friends(x, y)? printf("S"):printf("N");
  return 0;
};