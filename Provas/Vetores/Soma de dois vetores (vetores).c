#include <stdio.h>

void sum(int A[], int B[], int C[], int size) {
  for(int i = 0; i < size; i++) {
    A[i] = B[i] + C[i];
  };
};

void populate(int vector[], int size) {
  for(int i = 0; i < size; i++) {
    scanf("%d", &vector[i]);
  };
  fflush(stdin);
};

int main() {
  int size;
  scanf("%d", &size);

  if(size > 10) {
    printf("Muitos elementos");
    return 0;
  };

  int A[size], B[size], C[size];

  populate(B, size);
  populate(C, size);

  sum(A, B, C, size);

  for(int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  };

  return 0;
};