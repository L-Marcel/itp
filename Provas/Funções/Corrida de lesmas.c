#include <stdio.h>

int level(int speed) {
  if(speed < 10) {
    return 1;
  } else if(speed < 20) {
    return 2;
  } else {
    return 3;
  };
};

int main() {
  int amount;
  scanf("%d", &amount);

  int bigger_level = 1;
  for(int i = 0; i < amount; i++) {
    int speed;
    scanf("%d", &speed);

    int current_level = level(speed);
    if(bigger_level < current_level) {
      bigger_level = current_level;
    };
  };

  printf("Level %d", bigger_level);

  return 0;
};