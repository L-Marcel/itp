#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  double values[];
} vector;

vector* createVector(int size) {
  vector* vec = malloc(sizeof(vector) + (sizeof(double) * size));
  vec -> size = size;
  return vec;
};

vector* sumVectors(vector *p, vector *q) {
  int size = p -> size;
  vector* result = createVector(size);
  
  for(int i = 0; i < size; i++) {
    result -> values[i] = (p -> values[i] + q -> values[i]);
  };

  return result;
};

double internalProdVectors(vector *p, vector *q) {
  double result = 0;
  int size = p -> size;

  for(int i = 0; i < size; i++) {
    result += (p -> values[i] * q -> values[i]);
  };

  return result;
};

int main() {
  int size;
  scanf("%d", &size);

  vector *p = createVector(size);
  vector *q = createVector(size);

  for(int i = 0; i < size * 2; i++) {
    double nextValue;
    scanf("%lf", &nextValue);

    if(i < size) {
      p -> values[i % size] = nextValue;
    } else {
      q -> values[i % size] = nextValue;
    };
  };

  vector *sumResult = sumVectors(p, q);

  double internalProdResult = internalProdVectors(p, q);

  for(int i = 0; i < size; i++) {
    printf("%.2lf ", sumResult -> values[i]);
  };

  printf("\n%.2lf", internalProdResult);
  return 0;
};