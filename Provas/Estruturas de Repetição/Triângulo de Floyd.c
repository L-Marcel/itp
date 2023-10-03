#include <stdio.h>

int main() {
  int lines;
  scanf("%d", &lines);

  if(lines <= 0) {
    printf("Você entrou com %d, tente de novo na próxima", lines);
    return 0;
  };

  int number = 1;
  int numbers_to_print = 1;

  for(int l = 0; l < lines; l++) {
    for(int c = 0; c < numbers_to_print; c++) {
      printf("%2d", number);
      number++;

      if(c < numbers_to_print) {
        printf(" ");
      };
    };
    numbers_to_print++;
    printf("\n");
  };

  return 0;
};