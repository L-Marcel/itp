#include <stdio.h>

void populate(int vector[], int size) {
  for(int i = 0; i < size; i++) {
    scanf("%d", &vector[i]);
    fflush(stdin);
  };
};

void sum(int A[], int B[], int C[], int size, int D[]) {
  for(int i = 0; i < size; i++) {
    D[i] = A[i] + B[i] + C[i];
  };
};

void print_vector(int vector[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  };
};

int main() {
  int size;
  scanf("%d", &size);
  fflush(stdin);

  int A[size], B[size], C[size], D[size];
  populate(A, size);
  populate(B, size);
  populate(C, size);

  sum(A, B, C, size, D);

  print_vector(D, size);

  return 0;
};