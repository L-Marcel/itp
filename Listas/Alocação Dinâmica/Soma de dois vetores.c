#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int length;
  int* values;
} Vector;

Vector create_vector() {
  Vector* vector = malloc(sizeof(Vector));
  vector -> length = 0;
  vector -> values = (int*) malloc(0);

  return *vector;
};

void add_in_vector(Vector* vector, int value) {
  vector -> length++;
  vector -> values = realloc(vector -> values, sizeof(int) * vector -> length);
  vector -> values[vector -> length - 1] = value;
};

void load_line(Vector* vector) {
  char line[100];
  
  scanf("%[0-9- ][^\n]", line);
  getchar();

  char* piece = strtok(line, " ");
  while(piece != NULL) {
    int* value = malloc(sizeof(int));
    sscanf(piece, "%d", value);
    add_in_vector(vector, *value);
    piece = strtok(NULL, " ");
  };
};

void sum(Vector* a, Vector* b, Vector* result) {
  for(int i = 0; i < a -> length; i++) {
    add_in_vector(result, a -> values[i] + b -> values[i]);
  };
};

void print_vector(Vector* a) {
  for(int i = 0; i < a -> length; i++) {
    printf("%d ", a -> values[i]);
  };
};

int main() {
  Vector a = create_vector();
  Vector b = create_vector();
  Vector c = create_vector();

  load_line(&a);
  load_line(&b);

  if(a.length != b.length) {
    printf("Vetores de tamanhos diferentes!");
    return 0;
  };
  
  sum(&a, &b, &c);
  print_vector(&c);

  return 0;
};