#include <stdio.h>

void print_results(float students[][2], int size) {
  int count_results[3] = {0,0,0};

  printf("Aprovados: ");
  for(int i = 0; i < size; i++) {
    float points = students[i][1];
    float id = students[i][0];

    if(points >= 7.0) {
      printf(count_results[0] == 0? "%.f (%.1f)":", %.f (%.1f)", id, points);
      count_results[0]++;
    };
  };

  printf("\nRecuperação: ");
  for(int i = 0; i < size; i++) {
    float points = students[i][1];
    float id = students[i][0];

    if(points < 7.0 && points >= 5.0) {
      printf(count_results[1] == 0? "%.f (%.1f)":", %.f (%.1f)", id, points);
      count_results[1]++;
    };
  };

  printf("\nReprovados: ");
  for(int i = 0; i < size; i++) {
    float points = students[i][1];
    float id = students[i][0];

    if(points < 5.0) {
      printf(count_results[2] == 0? "%.f (%.1f)":", %.f (%.1f)", id, points);
      count_results[2]++;
    };
  };
};

void load_grade(float students[][2], int size) {
  for(int i = 0; i < size; i++) {
    scanf("%f - %f", &students[i][0], &students[i][1]);
    fflush(stdin);
  };
};

int main() {
  int size;
  scanf("%d", &size);

  float students[size][2];
  load_grade(students, size);

  print_results(students, size);

  return 0;
};