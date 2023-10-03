#include <stdio.h>
#include <stdbool.h>

bool have_winner(int vectors[][2], int size, int winner) {
  for(int i = 0; i < size; i++) {
    if(vectors[i][1] == winner) {
      return true;
    };
  };

  return false;
};

int bet(int vectors[][2], int size) {
  int value = 0;

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < 2; j++) {
      scanf("%d", &vectors[i][j]);
      if(j == 0) {
        value += vectors[i][0];
      };
    };
    fflush(stdin);
  };

  return value;
};

int result(int vectors[][2], int size, int winner, int amount) {
  int bet_by_winners = 0;
  int rest = amount;

  for(int i = 0; i < size; i++) {
    if(winner == vectors[i][1]) {
      bet_by_winners += vectors[i][0];
      amount -= vectors[i][0];
    };
  };
  
  for(int i = 0; i < size; i++) {
    if(winner == vectors[i][1]) {
      float gain = (1.0 * vectors[i][0] / bet_by_winners) * amount;
      vectors[i][0] += gain;
      printf("Apostador %d: R$ %d\n", i + 1, vectors[i][0]);
      rest -= vectors[i][0];
    };
  };

  return rest;
};

int debt(int vectors[][2], int size, int amount) {
  int bet = 0;
  int rest = amount;

  for(int i = 0; i < size; i++) {
    bet += vectors[i][0];
  };

  for(int i = 0; i < size; i++) {
    float result = ((1.0 * vectors[i][0] / bet) * amount);
    vectors[i][0] = result;
    printf("Apostador %d: R$ %d\n", i + 1, vectors[i][0]);
    rest -= vectors[i][0];
  };

  return rest;
};

int main() {
  int size;
  scanf("%d", &size);

  int persons[size][2];
  int amount = bet(persons, size);

  int winner;
  scanf("%d", &winner);
  printf("Total: R$ %d\n", amount);
  int food = 0;

  food = amount / 10;
  amount -= food;

  if(have_winner(persons, size, winner)) {
    food += result(persons, size, winner, amount);
  } else {
    food += debt(persons, size, amount);
  };

  printf("Bebidas e petiscos: R$ %d", food);
  return 0;
};