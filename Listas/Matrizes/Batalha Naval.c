#include <stdio.h>
#include <stdbool.h>

bool horizontal(int spaces, int ship[spaces][2]) {
  int first = ship[0][0];

  for(int s = 0; s < spaces; s++) {
    if(ship[s][0] != first) {
      return false;
    };
  };

  return true;
};

void populateShip(int spaces, int ship[spaces][2]) {
  for(int s = 0; s < spaces; s++) {
    scanf("%d %d", &ship[s][0], &ship[s][1]);
    fflush(stdin);
  };
};

bool printShip(int spaces, int ship[spaces][2], int row, int column) {
  for(int s = 0; s < spaces; s++) {
    char hor_position = horizontal(spaces, ship);
    
    if(ship[s][0] == row && ship[s][1] == column) {
      printf(
        spaces == 1?
          "*":
          !hor_position? 
            (s == 0? 
              "^":
              s == spaces - 1?
                "v":
                "|"
            ):
            (s == 0? 
              "<":
              s == spaces - 1?
                ">":
                "="
            )
      );

      return true;
    };
  };

  return false;
};

int main() {
  int canoe[1][2] = {{0 , 0}};
  int ship[2][2] = {{0, 0}, {0, 0}};
  int frigate[3][2] = {{0, 0}, {0, 0}, {0, 0}};
  int destroyer[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

  populateShip(1, canoe);
  populateShip(2, ship);
  populateShip(3, frigate);
  populateShip(4, destroyer);

  for(int r = 0; r < 10; r++) {
    for(int c = 0; c < 10; c++) {
      bool shipPrinted = 
        printShip(1, canoe, r, c)
        || printShip(2, ship, r, c)
        || printShip(3, frigate, r, c)
        || printShip(4, destroyer, r, c);

      if(!shipPrinted) {
        printf("~");
      };
    };
    printf("\n");
  };

  return 0;
};