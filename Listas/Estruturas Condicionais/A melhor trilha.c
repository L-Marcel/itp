#include <stdio.h>

int main() {
  int trails, health;
  scanf("%d", &trails);

  if(trails < 5) {
    printf("Iniciante");
  } else if(trails < 20) {
    scanf("%d", &health);
    health == 0? printf("Iniciante"):printf("Intermediário");
  } else {
    scanf("%d", &health);
    health == 0? printf("Intermediário"):printf("Avançado");
  };

  return 0;
};