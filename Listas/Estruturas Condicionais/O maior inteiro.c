#include <stdio.h>

int main() {
  int numbers[4];
  scanf("%d %d %d %d", 
    &numbers[0], 
    &numbers[1], 
    &numbers[2], 
    &numbers[3]
  );

  int bigger = numbers[0];
  for(int i = 0; i < 4; i++) {
    if(numbers[i] > bigger) {
      bigger = numbers[i];
    };
  };

  printf("Maior: %d", bigger);
  return 0;
};