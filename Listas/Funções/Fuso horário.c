#include <stdio.h>
#include <stdbool.h>

int timezone(int start, int duration, int diff) {
  int total = (start + duration + diff);
  return total < 0? 24 - ((-total) % 24) : total % 24;
};

int main() {
  int start, duration, diff;

  scanf("%d", &start);
  scanf("%d", &duration);
  scanf("%d", &diff);

  int end = timezone(start, duration, diff);

  printf("Hora de saída: %d\nHora de chegada: %d", start, end);

  return 0;
};