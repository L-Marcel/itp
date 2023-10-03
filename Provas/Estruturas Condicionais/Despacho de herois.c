#include <stdio.h>

int main() {
  int amount, hero, monster;
  int win = 0;

  scanf("%d %d %d", &amount, &hero, &monster);

  switch (monster)
  {
    case 1:
      if(hero >= 2 || amount >= 3) {
        win = 1;
      };
      break;
    case 2:
      if(hero >= 3 || (amount >= 3 && hero == 2)) {
        win = 1;
      };
      break;
    case 3:
      if(hero >= 4 || (amount >= 3 && hero == 3)) {
        win = 1;
      };
      break;
    case 4:
      if(hero == 5 || (amount >= 4 && hero == 3)) {
        win = 1;
      };
      break;
    default:
      if(hero == 5) {
        win = 1;
      };
      break;
  }
  
  if(win == 1 && amount >= 1) {
    printf("Heróis vencerão!");
  } else {
    printf("Melhor chamar Saitama!");
  };
  
  return 0;
};