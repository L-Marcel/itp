#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estou curtindo alocação
//de memória! :D

typedef struct {
  char name[30];
} Worker;

typedef struct {
  int length;
  Worker** workers;
} WorkersList;

WorkersList* createList() {
  WorkersList* list = malloc(sizeof(WorkersList));
  list -> length = 0;
  list -> workers = calloc(0, sizeof(Worker*));
  return list;
};

Worker* createWorker(char name[30]) {
  Worker* worker = malloc(sizeof(Worker));
  strcpy(worker -> name, name);
  return worker;
};

void expand(WorkersList* list) {
  list -> length++;
  list -> workers = realloc(list -> workers, sizeof(Worker*) * (list -> length));
};

void reduce(WorkersList* list) {
  list -> length--;
  list -> workers = realloc(list -> workers, sizeof(Worker*) * (list -> length));
};

int workerAlreadyInList(WorkersList* list, char name[30]) {
  for(int i = 0; i < list -> length; i++) {
    if(strcmp(list -> workers[i] -> name, name) == 0) {
      return i;
    };
  };

  return -1;
};

void addWorkerInList(WorkersList* list, char name[30]) {
  if(workerAlreadyInList(list, name) == -1) {
    expand(list);
    list -> workers[list -> length - 1] = createWorker(name);
  };
};

void removeWorkerInList(WorkersList* list, char name[30]) {
  int index = workerAlreadyInList(list, name);

  if(index != -1) {
    for(int j = index; j < list -> length - 1; j++) {
      list -> workers[j] = list -> workers[j + 1];
    };

    reduce(list);
  };
};

void printWorkers(WorkersList* list) {
  printf("Atualmente trabalhando:\n");
  for(int i = 0; i < list -> length; i++) {
    printf("%s\n", list -> workers[i] -> name);
  };
  printf("\n");
};

int main() {
  WorkersList* list = createList();
  int operations;
  scanf("%d", &operations);

  for(int _ = 0; _ < operations; _++) {
    getchar();

    char line[40];
    scanf("%[^\n]", line);

    char* operation = strtok(line, " ");
    
    if(strcmp(line, "INSERIR") == 0) {
      char* name = strtok(NULL, " ");
      addWorkerInList(list, name);
    } else if(strcmp(operation, "REMOVER") == 0) {
      char* name = strtok(NULL, " ");
      removeWorkerInList(list, name);
    } else if(strcmp(operation, "IMPRIMIR") == 0) {
      printWorkers(list);
    } else {
      operations++;
      printf("\nInsira um comando disponível!\n\n");
    };
  };

  return 0;
};