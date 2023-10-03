#include <stdio.h>
#include <stdbool.h>

void populate(int rows, int columns, int map[rows][columns]) {
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      scanf("%d", &map[r][c]);
    };
    fflush(stdin);
  };
};

bool checkBomb(int rows, int columns, int map[rows][columns], int row, int column) {
  int diff[3] = {-1, 0, 1};

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int r = row + diff[i];
      int c = column + diff[j];

      if((diff[i] == 0 && diff[j] == 0) || r < 0 || r >= rows || c < 0 || c >= columns) {
        continue;
      };

      if(map[r][c] >= map[row][column]) {
        return false;
      };
    };
  };

  return true;
};

bool scan(int rows, int columns, int map[rows][columns], int jedi[2]) {
  bool jedi_is_alive = true;
  int count = 1;

  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      bool have_bomb = checkBomb(rows, columns, map, r, c);

      if(have_bomb) {
        printf("Local %d: %d %d\n", count, r + 1, c + 1);
        count++;
        if(r == jedi[0] && c == jedi[1]) {
          jedi_is_alive = false;
        };
      };
    };
  };

  return jedi_is_alive;
};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  fflush(stdin);

  int jedi[2];
  scanf("%d %d", &jedi[0], &jedi[1]);
  fflush(stdin);
  jedi[0]--;
  jedi[1]--;

  int map[r][c];
  populate(r, c, map);

  if(scan(r, c, map, jedi)) {
    printf("Ao resgate!");
  } else {
    printf("Descanse na Força...");
  };

  return 0;
};