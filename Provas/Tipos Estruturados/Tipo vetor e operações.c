#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  double values[];
} vector;

void *alloc(int size) {
  return malloc(sizeof(vector) + (sizeof(double) * size));
};

vector* sumVectors(int size, vector *p, vector *q) {
  vector* result = alloc(size);
  result -> size = size;
  
  for(int i = 0; i < size; i++) {
    result -> values[i] = (p -> values[i] + q -> values[i]);
  };

  return result;
};

double internalProdVectors(int size, vector *p, vector *q) {
  double result = 0;

  for(int i = 0; i < size; i++) {
    result += (p -> values[i] * q -> values[i]);
  };

  return result;
};

int main() {
  int size;
  scanf("%d", &size);

  vector *p = alloc(size);
  p -> size = size;

  vector *q = alloc(size);
  q -> size = size;

  for(int i = 0; i < size * 2; i++) {
    double nextValue;
    scanf("%lf", &nextValue);

    if(i < size) {
      p -> values[i % size] = nextValue;
    } else {
      q -> values[i % size] = nextValue;
    };
  };

  vector *sumResult = sumVectors(size, p, q);

  double internalProdResult = internalProdVectors(size, p, q);

  for(int i = 0; i < size; i++) {
    printf("%.2lf ", sumResult -> values[i]);
  };

  printf("\n%.2lf", internalProdResult);
  return 0;
};