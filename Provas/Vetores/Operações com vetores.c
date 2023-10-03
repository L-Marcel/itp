#include <stdio.h>

void populate(int vector[3]) {
  for(int i = 0; i < 3; i++) {
    scanf("%d", &vector[i]);
  };
  fflush(stdin);
};

void calc(int A[3], int B[3], int C[3], int D[3]) {
  for(int i = 0; i < 3; i++) {
    A[i] = B[i] + C[i] - (5 * D[i]);
  };
};

int main() {
  int A[3], B[3], C[3], D[3];

  populate(B);
  populate(C);
  populate(D);

  calc(A, B, C, D);

  printf("A = [%d,%d,%d]", A[0], A[1], A[2]);

  return 0;
};