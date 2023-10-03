#include <stdio.h>
#include <stdlib.h>

void populate(int rows, int columns, int map[rows][columns]) {
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < columns; c++) {
      scanf("%d", &map[r][c]);
    };
    fflush(stdin);
  };
};

void calcZones(
  int rows, 
  int columns, 
  int map[rows][columns], 
  int zones[rows - 2][columns - 2],
  int target
) {
  for(int r = 0; r < rows - 2; r++) {
    for(int c = 0; c < columns - 2; c++) {
      int count = 0;

      for(int dr = 0; dr < 3; dr++) {
        for(int dc = 0; dc < 3; dc++) {
          count += map[r + dr][c + dc];
        };
      };

      zones[r][c] = abs(target - count);
    };
  };
};

void printBestZone(
  int rows, 
  int columns, 
  int zones[rows - 2][columns - 2]
) {
  int best[3] = {zones[0][0],0,0};

  for(int r = 0; r < rows - 2; r++) {
    for(int c = 0; c < columns - 2; c++) {
      int diff = zones[r][c];

      if(diff < best[0]) {
        best[0] = diff;
        best[1] = r;
        best[2] = c;
      };
    };
  };

  printf("A melhor area para exploracao eh %d %d com valor %d", best[1] + 1, best[2] + 1, best[0]);
};

int main() {
  int r, c, s;
  scanf("%d %d %d", &r, &c, &s);
  fflush(stdin);

  int map[r][c];
  int zones[r - 2][c - 2];
  populate(r, c, map);
  calcZones(r, c, map, zones, s);
  printBestZone(r ,c, zones);

  return 0;
};