#include <stdio.h>

int main() {
  int burguers[5] = {12, 23, 31, 28, 15};
  int id, money;

  scanf("%d %d", &id, &money);

  int rest = money - burguers[id - 1];

  if(rest < 0) {
    printf("Saldo insuficiente! Falta %d reais", rest * -1);
  } else if(rest > 0) {
    printf("Troco = %d reais", rest);
  } else {
    printf("Deu certim!");
  };

  return 0;
};