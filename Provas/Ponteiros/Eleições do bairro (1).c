#include <stdio.h>

int count(int n, int votes[n], int concurrent) {
  int count = 0;

  for(int i = 0; i < n; i++) {
    if(votes[i] == concurrent) {
      count++;
    };  
  };

  return count;
};

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
  for(int i = 1; i <= 10; i++) {
    if(count(n, votes, i) >= count(n, votes, *most_voted)) {
      *most_voted = i;
    }
  };
  
  for(int i = 1; i <= 10; i++) {
    if(i != *most_voted && count(n, votes, i) >= count(n, votes, *second_most_voted)) {
      *second_most_voted = i;
    }
  };
};

int main() {
  int n;
  scanf("%d", &n);

  int votes[n];

  if(n <= 0) {
    printf("É necessário que pelo menos uma pessoa vote!");
    return 0;
  };

  for(int i = 0; i < n; i++) {
    scanf("%d", &votes[i]);
    if(votes[i] <= 0 || votes[i] > 10) {
      printf("Chapa inválida!");
      return 0;
    };
  };

  int most_voted = 1;
  int second_most_voted = 1;
  compute_votes(n, votes, &most_voted, &second_most_voted);
  printf("%d %d", most_voted, second_most_voted);

  return 0;
};