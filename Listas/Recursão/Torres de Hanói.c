#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Admito, esse foi muita gambiarra em cima de gambiarra

typedef struct {
  int from;
  int to;
  int pin;
} Move;

typedef struct {
  int length;
  Move* moves;
} MoveList;

MoveList create_moves() {
  MoveList* moves = malloc(sizeof(MoveList));
  moves -> length = 0;
  moves -> moves = malloc(0);

  return *moves;
};

int** populate_sticks(int pins) {
  int** sticks = malloc(sizeof(int*) * 3);
  for(int i = 0; i < 3; i++) {
    *(sticks + i) = malloc(sizeof(int) * pins);
    for(int j = 0; j < pins; j++) {
      if(i == 0) {
        *(*(sticks + i) + j) = j + 1;
      } else {
        *(*(sticks + i) + j) = 0;
      };
    };
  };

  return sticks;
};

void print_sticks(int pins, int** sticks) {
  printf("\n=====\n");
  for(int i = 0; i < pins; i++) {
    printf("%d %d %d\n", *(*(sticks) + i), *(*(sticks + 1) + i), *(*(sticks + 2) + i));
  };
  printf("\n");
};

MoveList update_moves_list(MoveList moves_list, Move move) {
  MoveList* updated_moves_list = malloc(sizeof(MoveList));
  updated_moves_list -> length = moves_list.length + 1;
  updated_moves_list -> moves = malloc(sizeof(Move) * (moves_list.length + 1));
  
  for(int i = 0; i < moves_list.length; i++) {
    updated_moves_list -> moves[i] = moves_list.moves[i];
  };

  updated_moves_list -> moves[moves_list.length] = move;
  return *updated_moves_list;
};

int get_first_pin(int pins, int* stick) {
  for(int i = 0; i < pins; i++) {
    if(*(stick + i) != 0) {
      return *(stick + i);
    };
  };

  return 0;
};

void remove_first_pin(int pins, int stick, int** sticks) {
  for(int i = 0; i < pins; i++) {
    if(*(*(sticks + stick) + i) != 0) {
      *(*(sticks + stick) + i) = 0;
      break;
    };
  };
};

void put_pin(int pins, int stick, int** sticks, int pin) {
  for(int i = pins - 1; i >= 0; i--) {
    if(*(*(sticks + stick) + i) == 0) {
      *(*(sticks + stick) + i) = pin;
      break;
    };
  };
};

bool completed(int** sticks) {
  if(*(*(sticks + 2)) == 1) {
    return true;
  };

  return false;
};

bool in_order(int pins, int stick, int** sticks) {
  for(int i = pins - 1; i >= 0; i--) {
    int pin = *(*(sticks + stick) + i);
    if(pin != i + 1 && pin != 0) {
      return false;
    } else if(pin == 0) {
      return true;
    };
  };

  return true;
};

bool can_move_pin(
  int pins, 
  int stick, 
  int to, 
  int** sticks,
  MoveList move_list
) {
  int pin = get_first_pin(pins, sticks[stick]);

  if(pin == 0 || to == stick) {
    return false;
  };

  int first_in_stick = get_first_pin(pins, sticks[to]);
  if(first_in_stick < pin && first_in_stick != 0) {
    return false;
  };

  Move last_move = move_list.moves[move_list.length - 1];
  if(last_move.pin == pin) {
    return false;
  };

  if(stick == 2 && in_order(pins, 2, sticks)) {
    return false;
  };

  return true;
};

Move move_pin(int pins, int stick, int to, int** sticks) {
  int pin = get_first_pin(pins, sticks[stick]);
  remove_first_pin(pins, stick, sticks);
  put_pin(pins, to, sticks, pin);
  //print_sticks(pins, sticks);

  Move move = {stick, to, pin};
  return move;
};

int calc_max_moves(int pins) {
  if(pins == 0) {
    return 0;
  } else {
    return (calc_max_moves(pins - 1) * 2) + 1;
  };
};

bool try_resolve(int pins, int** sticks, MoveList move_list) {
  int max = calc_max_moves(pins);

  if(move_list.length >= max) {
    return false;
  };

  int** sticks_copy = malloc(sizeof(int*) * 3);

  for(int i = 0; i < 3; i++) {
    *(sticks_copy + i) = malloc(sizeof(int) * pins);
    for(int j = 0; j < pins; j++) {
      *(*(sticks_copy + i) + j) = *(*(sticks + i) + j);
    };
  };

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(can_move_pin(pins, i, j, sticks_copy, move_list)) {
        Move move = move_pin(pins, i, j, sticks_copy);
        MoveList copy = update_moves_list(move_list, move);

        if(completed(sticks_copy) && calc_max_moves(pins) >= copy.length) {
          for(int i = 0; i < copy.length; i++) {
            Move move = copy.moves[i];
            printf("Move o disco em %d para %d\n", move.from + 1, move.to + 1);
          };
          printf("Total de movimentos: %d", copy.length);
          return true;
        };

        if(try_resolve(pins, sticks_copy, copy)) {
          return true;
        };

        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < pins; j++) {
            *(*(sticks_copy + i) + j) = *(*(sticks + i) + j);
          };
        };
      };
    };
  };

  free(sticks_copy);
  return false;
};


int main() {
  int pins;
  scanf("%d", &pins);

  int** sticks = populate_sticks(pins);

  if(pins == 0) {
    printf("Total de movimentos: 0");
    return;
  };

  MoveList move_list = create_moves();
  try_resolve(pins, sticks, move_list);

  return 0;
};