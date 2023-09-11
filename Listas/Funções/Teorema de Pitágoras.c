#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int mdc(int x, int y, int z) {
  int small = x < (y < z? y:z)? x:(y < z? y:z);

  for(int i = small; i > 1; i--) {
    if(x % i == 0 && y % i == 0 && z % i == 0) {
      return i;
    };
  };

  return 1;
};

bool check_pit(int h, int x, int y) {
  return pow(h, 2.0) == pow(x, 2.0) + pow(y, 2.0);
};

void triple(int x, int y, int z) {
  bool pit = 
    x > (y > z? y:z)? 
      check_pit(x, y, z):
      (y > z? 
        check_pit(y, x, z):
        check_pit(z, x, y)
      );

  bool has_triangle = 
    x < y + z && //4 < 5 + 6
    y < z + x && //5 < 4 + 6
    z < y + x && //6 < 4 + 5
    x > 0 && 
    y > 0 && 
    z > 0 &&
    pit? true:false;

  if(has_triangle && mdc(x, y, z) == 1) {
    printf("tripla pitagorica primitiva");
  } else if(has_triangle) {
    printf("tripla pitagorica");
  } else {
    printf("tripla");
  };
};

int main() {
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  triple(x, y, z);
  return 0;
};