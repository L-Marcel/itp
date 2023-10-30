#include <stdio.h>
#include <stdbool.h>

int get_range(
  int n, 
  int cells[n], 
  int distance, 
  int user, 
  int *left_index, 
  int *right_index
) {
  int cells_in_range = 0;
  for(int i = 0; i < n; i++) {
    bool in_range = 
      cells[i] + distance >= user &&
      cells[i] - distance <= user;
      
    if(
      in_range && cells_in_range == 0
    ) {
      *left_index = i;
      cells_in_range++;
    } else if(in_range && cells_in_range > 0) {
      cells_in_range++;
    } else if(!in_range && cells_in_range > 0) {
      *right_index = (i - 1);
      break;
    };
  };

  return cells_in_range;
};

int main() {
  int n, distance, user;
  scanf("%d %d %d", &n, &distance, &user);

  //o enunciado diz que sempre
  //vem na ordem crescente
  int cells[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &cells[i]);
  };

  int left_index;
  int right_index;

  int cells_in_range = get_range(
    n,
    cells,
    distance,
    user,
    &left_index,
    &right_index
  );

  if(cells_in_range == 0) {
    printf("USUARIO DESCONECTADO");
    return 0;
  };

  for(int i = left_index; i <= right_index; i++) {
    printf("%d ", cells[i]);
  };

  return 0;
};