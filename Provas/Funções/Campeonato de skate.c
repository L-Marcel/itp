#include <stdio.h>

int calc_score(int x, int y, int z) {
  int un_scores[3] = {x, y, z};
  int scores[3] = {-1, -1, -1};

  if(x == y || y == z) {
    return y;
  } else if(x == z) {
    return x;
  };

  for(int i = 0; i < 3; i++) {
    int bigger = -1;
    for(int j = 0; j < 3; j++) {
      int unused = 
        un_scores[j] != scores[1] &&
        un_scores[j] != scores[2] &&
        un_scores[j] != scores[3];

      if((unused && un_scores[j] > bigger)) {
        bigger = un_scores[j];
      }
    };

    scores[i] = bigger;
  };

  return scores[2];
};

void get_scores(int scores[9]) {
  for(int i = 0; i < 9; i++) {
    scanf("%d", &scores[i]);
  };
};

void get_days_scores(int scores[9], int days_score[3]) {
  for(int i = 0; i < 3; i++) {
    days_score[i] = calc_score(scores[i * 3], scores[i*3 + 1], scores[i*3 + 2]);
  };
};

int get_final_scores(int scores[3]) {
  return calc_score(scores[0], scores[1], scores[2]);
};

int main() {
  int A[9], B[9];

  get_scores(A);
  get_scores(B);

  int day_A[3], day_B[3];

  get_days_scores(A, day_A);
  get_days_scores(B, day_B);

  int score_A = get_final_scores(day_A);
  int score_B = get_final_scores(day_B);

  if(score_A == score_B) {
    printf("empate");
  } else if(score_A > score_B) {
    printf("A");
  } else {
    printf("B");
  };

  return 0;
};