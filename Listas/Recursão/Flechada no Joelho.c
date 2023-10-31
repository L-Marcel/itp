#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  char name[20];
  int value;
  int weight;
} Item;

typedef struct {
  int length;
  int max_weight;
  int weight;
  int value;
  Item* items;
} Bag;

Item create_item() {
  Item* item = malloc(sizeof(Item));
  
  scanf("%s %d %d", item -> name, &(item -> value), &(item -> weight));
  getchar();

  return *item;
};

Bag create_bag(int max_weight) {
  Bag* bag = malloc(sizeof(Bag));
  bag -> length = 0;
  bag -> max_weight = max_weight;
  bag -> weight = 0;
  bag -> items = malloc(0);
  bag -> value = 0;

  return *bag;
};

void print_bag(Bag bag) {
  if(bag.length == 0) {
    printf("Nada para carregar...");
    return;
  };

  printf("Inventario final:\n");
  for(int i = 0; i < bag.length; i++) {
    printf("Item: %s\n", bag.items[i].name);
  };
  printf("Valor total: %d", bag.value);
};

bool add_in_bag(Bag* bag, Item item) {
  if(bag -> weight + item.weight > bag -> max_weight) {
    return false;
  };

  bag -> length++;
  bag -> weight += item.weight;
  bag -> items = realloc(bag -> items, sizeof(Item) * bag -> length);
  bag -> items[bag -> length - 1] = item;
  bag -> value += item.value;

  return true;
};

Bag copy_bag(Bag bag) {
  Bag copy = create_bag(bag.max_weight);

  for(int i = 0; i < bag.length; i++) {
    add_in_bag(&copy, bag.items[i]);
  };

  return copy;
};

Item* copy_items(int items_amount, Item items[items_amount], int ignore) {
  Item* copy = malloc(sizeof(Item) * (items_amount - 1));

  int k = 0;
  for(int i = 0; i < items_amount; i++) {
    if(i != ignore) {
      copy[k] = items[i];
      k++;
    };
  };

  return copy;
};

Bag get_best_bag(
  Bag bag,
  int items_amount, 
  Item items[items_amount]
) {
  Bag best = bag;

  for(int i = 0; i < items_amount; i++) {
    Bag copy = copy_bag(bag);
   
    if(add_in_bag(&copy, items[i])) {
      copy = get_best_bag(copy, items_amount - 1, copy_items(items_amount, items, i));
      if(copy.value > best.value) {
        best = copy_bag(copy);
      };
    };
  };

  return best;
};

int main() {
  int items_amount, max_weight;
  scanf("%d %d", &items_amount, &max_weight);
  getchar();

  Item items[items_amount];
  for(int i = 0; i < items_amount; i++) {
    items[i] = create_item();
  };

  Bag bag = create_bag(max_weight);
  Bag best_bag = get_best_bag(bag, items_amount, items);

  print_bag(best_bag);
};