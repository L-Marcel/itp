#include <stdio.h>
#include <string.h>

int main() {
  int lines;
  char letter;

  scanf("%d %c", &lines, &letter);
  lines--;

  for(int i = 0; i < lines; i++) {
    for(int j = 0; j < lines; j++) {
      if(i == j || i == (lines - j - 1)) {
        printf("%c", letter);
      } else {
        printf(" ");
      };
    };
    printf("\n");
  };

  return 0;
};