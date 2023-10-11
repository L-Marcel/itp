#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Nota de esclarecimento

// Sim, tinha como fazer de forma bem mais
// simples... Eu que aproveitei para treinar
// ponteiros & lista encadeada já que não vale
// ponto algum essa questão

typedef struct {
  char name[30];
  float price;
  int amount;
  struct Item *next;
} Item;

typedef struct {
  int length;
  Item *first;
} ItemsList;

ItemsList createList() {
  ItemsList list;
  list.length = 0;
  list.first = NULL;
  return list;
};

void addInList(ItemsList *list, Item item) {
  Item *next = (Item*) malloc(sizeof(Item));
  next -> amount = item.amount;
  strcpy(item.name, next -> name);
  next -> price = item.price;
  next -> next = NULL;

  Item *current = list -> first;
  if(current == NULL) {
    list -> first = next;
  } else {
    while (current -> next != NULL) {
      current = (Item*) current -> next;
    };
    
    current -> next = (struct Item*) next;
  };

  list -> length++;
};

float getCost(ItemsList *list) {
  float cost = 0;

  Item *current = list -> first;
  for(int _ = 0; _ < list -> length; _++) {
    cost += (current -> price) * (current -> amount);
    current = (Item*) current -> next;
  };

  return cost;
};

int main() {
  ItemsList list = createList();

  while(true) {
    Item item;
    scanf("%s", item.name);
    scanf("%f", &item.price);
    scanf("%d", &item.amount);

    addInList(&list, item);

    int option;
    scanf("%d", &option);
    getchar();

    if(option != 1) {
      break;
    };
  };

  float cost = getCost(&list);
  int numberOfPeople;

  scanf("%d", &numberOfPeople);

  printf("Valor: R$ %.2f\nDivisão R$ %.2f para cada participante.", cost, cost / numberOfPeople);
  return 0;
};