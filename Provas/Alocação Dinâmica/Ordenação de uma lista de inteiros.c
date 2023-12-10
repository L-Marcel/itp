#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int length;
  int *array;
} List;

List* create_list() {
  List* list = (List*) malloc(sizeof(List));
  list -> length = 0;
  list -> array = malloc(0);

  return list;
};

void add_in_list(List* list, int number) {
  list -> length++;
  list -> array = (int*) realloc(list -> array, sizeof(int) * list -> length);
  list -> array[list -> length - 1] = number;
};

bool already_in_list(List* list, int number) {
  for(int i = 0; i < list -> length; i++) {
    if(list -> array[i] == number) {
      return true;
    };
  };

  return false;
};

void print_sorted(List* list) {
  List* sorted_list_indexes = create_list();

  int *smaller = (int*) malloc(sizeof(int));
  for(int i = 0; i < list -> length; i++) {
    smaller = NULL;
    int index = 0;

    for(int j = 0; j < list -> length; j++) {
      int number = list -> array[j];
      if((smaller == NULL || number < *smaller) && !already_in_list(sorted_list_indexes, j)) {
        smaller = list -> array + j;
        index = j;
      };
    };
    
    printf("%d ", *smaller);
    add_in_list(sorted_list_indexes, index);
  };
};

int main() {
  List* list = create_list();
  
  char line[100];
  scanf("%[0-9- ][^\n]", line);
  
  char* char_number = strtok(line, " ");

  while(char_number != NULL) {
    int number;
    sscanf(char_number, "%d", &number);
    add_in_list(list, number);

    char_number = strtok(NULL, " ");
  };

  print_sorted(list);
  return 0;
};