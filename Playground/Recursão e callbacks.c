#include <stdio.h>

void revert(int x, void (*next)()) {
  if(x <= 0 && next != NULL) {
    next();
    return;
  } else if(x <= 0) {
    return;
  };

  void callback() {
    printf("%d\n", x);

    if(next != NULL) {
      next();
    };
  };

  revert(x - 1, callback);
};

void count(int x, void (*next)()) {
  if(x <= 0 && next != NULL) {
    next();
    return;
  } else if(x <= 0) {
    return;
  };

  void callback() {
    if(next != NULL) {
      next();
    };

    printf("%d\n", x);
  };

  count(x - 1, callback);
};

int main() {
  count(5, NULL);
  printf("------\n");
  revert(5, NULL);
  return 0;
};