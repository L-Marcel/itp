#include <stdio.h>

int count_in(int element, int vector[][2], int size) {
  int bigger = 0;
  for(int i = 0; i < size; i++) {
    if(vector[i][0] == element && vector[i][1] > bigger) {
      bigger = vector[i][1];
    };
  };

  return bigger + 1;
};

void populate(int vector[][2], int size) {
  for(int i = 0; i < size; i++) {
    int next_number;
    scanf("%d", &next_number);

    int count = count_in(next_number, vector, size);

    vector[i][0] = next_number;
    vector[i][1] = count;
  };
};

void print_bigger(int vector[][2], int size) {
  int bigger[2] = {vector[0][0], 0};

  for(int i = 0; i < size; i++) {
    if(
      (vector[i][0] >= bigger[0] && bigger[1] == 0) ||
      (vector[i][0] >= bigger[0] && vector[i][1] >= 2)
    ) {
      bigger[0] = vector[i][0];
      bigger[1] = vector[i][1];
      printf("%d - %d\n", vector[i][0], vector[i][1]);
    };
  };

  printf("%d", bigger[0]);
};

int main() {
  int size;
  scanf("%d", &size);
 
  int vector[size][2];

  populate(vector, size);
  print_bigger(vector, size);

  return 0;
};