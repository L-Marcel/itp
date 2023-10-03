#include <stdio.h>

int main() {
  int teams_amount;
  int sportsmen = 0;
  scanf("%d", &teams_amount);
  fflush(stdin);

  int launch = 0; 
  int race = 0; 
  int jump = 0;
  
  for(int t = 0; t < teams_amount; t++) {
    int can_continue = 1;
    while(can_continue == 1) {
      char input;
      scanf("%c", &input);

      sportsmen++;
      switch(input) {
        case '\n':
        case ' ':
          sportsmen--;
          break;
        case 'C':
          race++;
          break;
        case 'S':
          jump++;
          break;
        case 'L':
          launch++;
          break;
        case 'F':
          sportsmen--;
          can_continue = 0;
          break;
        default:
          break;
      };
    };
    fflush(stdin);
  };

  printf("%d %d %d %d", race, jump, launch, sportsmen);
  return 0;
};