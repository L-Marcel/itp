#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int code;
  char description[30];
  float price;
} Products;

int main() {
  int amountOfProducts;
  scanf("%d", &amountOfProducts);

  Products products[amountOfProducts];

  for(int i = 0; i < amountOfProducts; i++) {
    scanf("%d", &products[i].code);
    
    getchar();
    fgets(products[i].description, 30, stdin);
    
    scanf("%f", &products[i].price);
  };

  float cost = 0;
  while(true) {
    int code, amount;
    scanf("%d", &code);

    if(code == 0) {
      break;
    };

    scanf("%d", &amount);
    for(int i = 0; i < amountOfProducts; i++) {
      if(products[i].code == code) {
        cost += (products[i].price * amount);
        break;
      };
    };
  };

  printf("%.2f", cost);
  return 0;
};