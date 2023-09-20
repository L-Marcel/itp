#include <stdio.h>

void populate(int rows, int columns, int map[rows][columns]) {
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      scanf("%d", &map[r][c]);
    };
    fflush(stdin);
  };
};

int greenZones(int rows, int columns, int map[rows][columns]) {
  int count = 0;

  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      if(map[r][c] == 2) {
        int diff[2] = {-1, 1};
        for(int i = 0; i < 2; i++) {
          if(map[r + diff[i]][c] == 1) {
            map[r + diff[i]][c] = 0;
            count++;
          };
        };

        for(int i = 0; i < 2; i++) {
          if(map[r][c + diff[i]] == 1) {
            map[r][c + diff[i]] = 0;
            count++;
          };
        };
      };
    };
  };

  return count;
};

int zonesWithoutPrinker(int rows, int columns, int map[rows][columns]) {
  int count = 0;

  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      if(map[r][c] == 1) {
        count++;
      };
    };
  };

  return count;
};

int main() {
  int row, column;
  scanf("%d %d", &row, &column);

  int map[row][column];
  
  populate(row, column, map);
  int total = greenZones(row, column, map);
  int rest = zonesWithoutPrinker(row, column, map);

  printf("%d %d", total, rest);

  return 0;
};