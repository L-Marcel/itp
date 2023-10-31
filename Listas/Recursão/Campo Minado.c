#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* charrep(char c, int n) {
  char* result = malloc(sizeof(char) * (n + 1));
  for(int i = 0; i < n; i++) {
    result[i] = c;
  }; 
  result[n] = '\0';
  return result;
};

void populate_board(int r, int c, char board[r][c]) {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      board[i][j] = '*';
    };
  };
};

void print_board(int r, int c, char board[r][c]) {
  char* div = charrep('=', c + 2);
  printf("%s\n", div);
  free(div);
  
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf("%c", board[i][j]);
    };
    printf("\n");
  };
};

int get_cell_number(
  int number_of_bombs, 
  int bombs[number_of_bombs][2],
  int r, int c,
  int y, int x
) {
  int count = 0;
  int combinations[3] = {0,1,-1};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < number_of_bombs; k++) {
        int vx = x + combinations[i];
        int vy = y + combinations[j];

        if(vx < 0 || vx > c - 1 || vy < 0 || vy > r - 1) {
          break;
        };

        int by = bombs[k][0];
        int bx = bombs[k][1];

        if(bx == vx && by == vy) {
          count++;
        };
      };
    };
  };

  return count;
};

char int_to_char(int value) {
  char c[2];
  sprintf(c, "%d", value);
  return c[0];
};

bool has_bomb(
  int number_of_bombs, int bombs[number_of_bombs][2],
  int y, int x
) {
  for(int i = 0; i < number_of_bombs; i++) {
    if(y == bombs[i][0] && x == bombs[i][1]) {
      return true;
    };
  };

  return false;
};

void click(  
  int number_of_bombs, 
  int bombs[number_of_bombs][2], 
  int r, int c, char board[r][c],
  int y, int x
) {
  int cell_number = get_cell_number(number_of_bombs, bombs, r, c, y, x);

  board[y][x] = int_to_char(cell_number);
  if(cell_number == 0) {
    int combinations[3] = {0,1,-1};
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < number_of_bombs; k++) {
          int vx = x + combinations[i];
          int vy = y + combinations[j];

          if(vx < 0 || vx > c - 1 || vy < 0 || vy > r - 1) {
            break;
          };

          if(board[vy][vx] == '*') {
            click(number_of_bombs, bombs, r, c, board, vy, vx);
          };
        };
      };
    };
  };
};

void reveal_board(
  int number_of_bombs, int bombs[number_of_bombs][2],
  int r, int c, char board[r][c]
) {
  for(int i = 0; i < number_of_bombs; i++) {
    int y = bombs[i][0];
    int x = bombs[i][1];
    if(board[y][x] != 'X') {
      board[y][x] = 'B';
    };
  };

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < r; j++) {
      if(board[i][j] == '*') {
        board[i][j] = int_to_char(get_cell_number(number_of_bombs, bombs, r, c, i, j));
      };
    };
  };

  print_board(r, c, board);
};

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  getchar();

  char board[r][c];
  populate_board(r, c, board);

  int bombs_amount;
  scanf("%d", &bombs_amount);
  getchar();
  int bombs[bombs_amount][2];

  for(int i = 0; i < bombs_amount; i++) {
    int y, x;
    scanf("%d %d", &y, &x);
    getchar();

    bombs[i][0] = y - 1;
    bombs[i][1] = x - 1;
  };

  int number_of_actions;
  scanf("%d", &number_of_actions);
  getchar();

  for(int i = 0; i < number_of_actions; i++) {
    char action[10];
    int y, x;
    scanf("%s %d %d", action, &y, &x);
    getchar();
    y = y - 1;
    x = x - 1;

    if(strcmp(action, "Clica") == 0) {
      if(has_bomb(bombs_amount, bombs, y, x)) {
        board[y][x] = 'X';
        printf("CABUUUUM!\nGame Over....\n");
        reveal_board(bombs_amount, bombs, r, c, board);
        return 0;
      };
      
      click(bombs_amount, bombs, r, c, board, y, x);
    } else if(strcmp(action, "Marca") == 0) {
      board[y][x] = 'B';
    };

    print_board(r, c, board);
  };

  printf("Você sobreviveu!\n");
  reveal_board(bombs_amount, bombs, r, c, board);
  return 0;
};