#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int length;
  float* values;
} vector;

bool can_ignore_value(int num_values, float values[num_values], float value) {
  int count = 0;

  for(int i = 0; i < num_values; i++) {
    if(values[i] == value) {
      count++;
    };
  };

  return count >= 2 || count == 0;
};

vector create_vector(int num_values, float values[num_values]) {
  vector* vector_ptr = malloc(sizeof(vector));
  vector_ptr -> length = 0;
  vector_ptr -> values = malloc(0);

  for(int i = 0; i < num_values; i++) {
    if(!can_ignore_value(num_values, values, values[i])) {
      vector_ptr -> length++;
      vector_ptr -> values = realloc(vector_ptr -> values, sizeof(float) * vector_ptr -> length);
      vector_ptr -> values[vector_ptr -> length - 1] = values[i];
    };
  };

  vector created_vector = *vector_ptr;
  free(vector_ptr);
  return created_vector;
};

int main() {
  int num_values;
  scanf("%d", &num_values);

  float values[num_values];
  for(int i = 0; i < num_values; i++) {
    scanf("%f", &values[i]);
  };

  vector vec = create_vector(num_values, values);

  printf("[");
  for(int i = 0; i < vec.length; i++) {
    bool last_char = i == vec.length - 1;
    printf("%.4f%s", *(vec.values + i), last_char? "":", ");
  };
  printf("]");

  return 0;
};