#include <stdio.h>
#include <stdbool.h>

bool is_cool(int vector[], int size) {
  for(int i = 1; i < size; i++) {
    if((vector[i] - vector[i - 1]) % 2 != 0) {
      return false;
    };
  };

  return true;
};

void populate(int vector[], int size) {
  for(int i = 0; i < size; i++) {
    scanf("%d", &vector[i]);
    fflush(stdin);
  };
};

int main() {
  int size;
  scanf("%d", &size);
  fflush(stdin);

  int vector[size];
  populate(vector, size);

  is_cool(vector, size)? 
    printf("Legal"):
    printf("Chato");

  return 0;
};