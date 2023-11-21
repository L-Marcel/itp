#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const char numbers[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool completed(char** matrix) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(*(*(matrix + i) + j) == '*') {
        return false;
      };
    };
  };

  return true;
};

bool available(char** matrix, char value, int y, int x) {
  int group = ((y / 3) * 3) + (x / 3);
  for(int i = 3 * (group / 3); i < 3 * ((group / 3) + 1); i++) {
    for(int j = 3 * (group % 3); j < 3 * ((group % 3) + 1); j++) {
      if(*(*(matrix + i) + j) == value) {
        return false;
      };
    };
  };

  for(int k = 0; k < 9; k++) {
    if(*(*(matrix + k) + x) == value || *(*(matrix + y) + k) == value) {
      return false;
    };
  };

  return true;
};

char** copy_matrix(char **matrix) {
  char** copy = malloc(sizeof(char*) * 9);

  for(int i = 0; i < 9; i++) {
    *(copy + i) = malloc(sizeof(char) * 9);

    for(int j = 0; j < 9; j++) {
      *(*(copy + i) + j) = *(*(matrix + i) + j);
    };
  };

  return copy;
};

bool try_complete(char **matrix) {
  char **copy = copy_matrix(matrix);

  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      bool some = false;
      if(*(*(matrix + i) + j) == '*') {
        for(int k = 0; k < 9; k++) {
          if(available(copy, numbers[k], i, j)) {
            some = true;
            *(*(copy + i) + j) = numbers[k];

            if(completed(copy)) {
              for(int t = 0; t < 9; t++) {
                for(int r = 0; r < 9; r++) {
                  printf("%c", *(*(copy + t) + r));
                };
                printf("\n");
              };
              return true;
            } else if(try_complete(copy)) {
              return true;
            };

            *(*(copy + i) + j) = '*';
            some = false;
          };
        };

        if(!some) {
          return false;
        };
      };
    };
  };

  return false;
};

int main() {
  char **matrix = malloc(sizeof(char*) * 9);;

  for(int i = 0; i < 9; i++) {
    *(matrix + i) = malloc(sizeof(char) * 9);
    for(int j = 0; j < 9; j++) {
      *(*(matrix + i) + j) = getchar();
    };
    getchar();
  };

  if(!try_complete(matrix)) {
    printf("Não tem solução!");
  };

  return 0;
};