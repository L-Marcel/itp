#include <stdio.h>

void draw(int width, int height, int flag[height][width], int initial) {
  int _initial;

  for(int h = 0; h < height; h++) {
    _initial = initial;
    for(int w = 0; w < width; w++) {
      if(w % (width / 3) == 0) {
        _initial++;
      };

      flag[h][w] = _initial;
    }; 
  };
};

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor) {
  int current_rect = -1;
  int rect = 
    cor == 'G'? 0:
    cor == 'Y'? 1:
    2;
  int value = 0;
  
  for(int h = 0; h < altura; h++) {
    current_rect = -1;

    for(int w = 0; w < largura; w++) {
      if(w % (largura / 3) == 0) {
        current_rect++;
      };

      if(current_rect == rect) {
        value += bandeira[h][w];
      };
    }; 
  };

  return value;
};

int main() {
  int width, initial;
  char color;

  scanf("%d %d %c", &width, &initial, &color);
  int height = (width / 3) * 2;

  int flag[height][width];
  draw(width, height, flag, initial);
  printf("%d", calcular_aposta(width, height, flag, color));

  return 0;
};