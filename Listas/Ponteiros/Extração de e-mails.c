#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char** emails;
  int length;
} EmailsList;

EmailsList* createEmailsList() {
  EmailsList* list = malloc(sizeof(EmailsList));
  list -> length = 0;
  return list;
};

//tem uma função do ctype que faz isso tbm
int get_index(char symbol, char* email) {
  for(int i = 0; i < 100; i++) {
    if(symbol == email[i]) {
      return i;
    };
  };

  return -1;
};

int main() {
  EmailsList* list = createEmailsList();

  bool keep_running = true;
  while (keep_running) {
    char* email = malloc(sizeof(char) * 100);
    scanf("%s", email);

    if(strcmp(email, "FIM") == 0) {
      keep_running = false;
    } else {
      list -> length++;
      list -> emails = realloc(list -> emails, sizeof(char*) * list -> length);
      *(list -> emails + list -> length - 1) = email;
    };  
  };

  for(int i = 0; i < list -> length; i++) {
    char* email =  *(list -> emails + i);
    int fst_div_index = get_index('@', email);

    //acho que isso seria melhor
    //strtok(email, "@");
    //mas ai foge do enunciado

    strcpy(email, email + fst_div_index + 1);

    int snd_div_index = get_index('.', email);
    *(email + snd_div_index) = '\0';
    printf("%s\n", email);
  };
};