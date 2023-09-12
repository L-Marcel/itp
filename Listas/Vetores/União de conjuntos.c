#include <stdio.h>
#include <stdbool.h>

bool in(int x, int X[], int size_x) {
  for(int i = 0; i < size_x; i++) {
    if(X[i] == x) {
      return true;
    };
  };

  return false;
};

void populate(int X[], int size_x) {
  for(int i = 0; i < size_x; i++) {
    scanf("%d", &X[i]);
  };
  fflush(stdin);
};

void print_join(int A[], int B[], int size_a, int size_b) {
  int max_join_size = size_a + size_b;
  int join[max_join_size];
  
  int count = 0;

  for(int i = 0; i < size_a; i++) {
    if(!in(A[i], join, max_join_size)) {
      printf("%d ", A[i]);
      join[count] = A[i];
      count++;
    };
  };

  for(int i = 0; i < size_b; i++) {
    if(!in(B[i], join, max_join_size)) {
      printf("%d ", B[i]);
      join[count] = B[i];
      count++;
    };
  };
};

int main() {
  int size_a, size_b;
  scanf("%d %d", &size_a, &size_b);
  fflush(stdin);
  
  int A[size_a], B[size_b];
  
  populate(A, size_a);
  populate(B, size_b);

  print_join(A, B, size_a, size_b);

  return 0;
};