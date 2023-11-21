#include <stdio.h>
#include <stdbool.h>

enum move {
  LEFT,
  RIGHT,
  UP,
  DOWN,
  NONE
};

int moves(int r, int c, int map[r][c], int i, int j, enum move last_move) {
  int count = 0;
  
  if(map[i][j] == '.') {
    map[i][j] = 'x';
    count++;
  }; 
   
  //left
  if(
    j > 0 && 
    last_move != RIGHT && 
    (
      map[i][j - 1] == '.' || 
      map[i][j - 1] == ' '
    )
  ) {
    count += moves(r, c, map, i, j - 1, LEFT);
  };

  //right
  if(
    j < c - 1 && 
    last_move != LEFT &&
    (
      map[i][j + 1] == '.' || 
      map[i][j + 1] == ' '
    )
  ) {
    count += moves(r, c, map, i, j + 1, RIGHT);
  };

  //up
  if(
    i > 0 && 
    last_move != DOWN &&
    (
      map[i - 1][j] == '.' || 
      map[i - 1][j] == ' '
    )
  ) {
    count += moves(r, c, map, i - 1, j, UP);
  };

  //down
  if(
    i < r - 1 && 
    last_move != UP &&
    (
      map[i + 1][j] == '.' || 
      map[i + 1][j] == ' '
    )
  ) {
    count += moves(r, c, map, i + 1, j, DOWN);
  }; 

  return count;
};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  int y, x;
  getchar();
  int map[r][c];
  int start[2];

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      char value = getchar();
      map[i][j] = value;

      if(value == 'C') {
        y = i;
        x= j;
      };
    };
    getchar();
  };

  int points = moves(r, c, map, y, x, NONE);
  
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(map[i][j] == 'x') {
        map[i][j] = ' ';
      };
    };
  };

  printf("Total de bolinhas devoradas: %d\n", points);
  printf("Mapa final:\n");
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf("%c", map[i][j]);
    };
    printf("\n");
  };

  return 0;
};