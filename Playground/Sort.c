#include <stdio.h>

void sort(int size, int vector[size]) {
  for(int start = 0; start < size; start++) {
    int smaller = vector[start];
    for(int i = start; i < size; i++) {
      if(vector[i] < smaller) {
        int old_smaller = smaller;
        smaller = vector[i];
        vector[i] = old_smaller;
      };
    };

    vector[start] = smaller;
  };
};

int main() {
  int n;
  scanf("%d", &n);
  getchar();

  int vector[n];

  for(int i = 0; i < n; i++) {
    scanf("%d", &vector[i]);
    getchar();
  };

  sort(n, vector);
  
  printf("A = ");
  if(n <= 0) printf("Ø");
  else printf("{");

  for(int i = 0; i < n; i++) {
    printf("%d", vector[i]);

    if(i == n - 1) printf("}");
    else printf(", ");
  };

  return 0;
};