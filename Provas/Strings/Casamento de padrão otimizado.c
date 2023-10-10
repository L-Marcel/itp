#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool charInTarget(char c, char T[50]) {
  bool exists = false;
  for(int k = 0; k < 50; k++) {
    bool end = T[k] == '\0';

    if(end) {
      break;
    };

    if(c == T[k]) {
      exists = true;
    }
  };
  return exists;
};

void compare(char S[50], char T[50], int ss, int st) {
  for(int i = 0; i < ss; i++) {
    bool matched = true;
    for(int k = 0; k < st; k++) {
      if(ss - i < st || !matched) {
        matched = false;
        break;
      };

      if(S[i + k] != T[k]) {
        matched = false;
        printf("%c não\n", S[i + k]);
        if(!charInTarget(S[i + k], T)) {
          i = i + k;
        };
      } else {
        printf("%c ", S[i + k]);
      };
    };

    if(matched) {
      printf("sim\n");
      printf("Achei o padrão no índice %d", i);
      return;
    };
  };

  printf("Não achei o padrão");
};

int main() {
  char sequence[50], target[50];
  int ss, st;
  
  scanf("%s[^\n]", sequence);
  scanf("%s[^\n]", target);

  ss = strlen(sequence);
  st = strlen(target);

  compare(sequence, target, ss, st);

  return 0;
};