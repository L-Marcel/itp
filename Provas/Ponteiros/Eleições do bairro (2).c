#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int id;
  char name[30];
  int votes;
} Party; 

Party create_party() {
  Party party;
  party.votes = 0;

  scanf("%d %s[^\n]", &party.id, party.name);

  return party;
};

int get_party_index(
  int num_parties,
  Party parties[num_parties],
  int id
) {
  for(int i = 0; i < num_parties; i++) {
    if(parties[i].id == id) {
      return i;
    };
  };

  return -1;
};

int compute_votes(
  int num_votes, int votes[num_votes],
  int num_parties, Party parties[num_parties],
  Party *most_voted, Party *second_most_voted
) {
  int valid_votes = 0;

  for(int i = 0; i < num_votes; i++) {
    int party_index = get_party_index(num_parties, parties, votes[i]);

    if(party_index != -1) {
      valid_votes++;
      parties[party_index].votes++;
    };
  };

  *most_voted = parties[0];
  *second_most_voted = parties[0];
  for(int i = 0; i < num_parties; i++) {
    if(parties[i].votes >= most_voted -> votes) {
      *most_voted = parties[i];
    };
  };

  for(int i = 0; i < num_parties; i++) {
    if(
      parties[i].id != most_voted -> id && 
      parties[i].votes >= second_most_voted -> votes
    ) {
      *second_most_voted = parties[i];
    };
  };

  return valid_votes;
};

int main() {
  int num_parties;
  scanf("%d", &num_parties);

  Party parties[num_parties];
  for(int i = 0; i < num_parties; i++) {
    parties[i] = create_party();
  };

  int num_votes;
  scanf("%d", &num_votes);

  int votes[num_votes];
  for(int i = 0; i < num_votes; i++) {
    scanf("%d", &votes[i]);
  };

  Party *most_voted = malloc(sizeof(Party));
  Party *second_most_voted = malloc(sizeof(Party));

  int valid_votes = compute_votes(
    num_votes, votes, 
    num_parties, parties, 
    most_voted, second_most_voted
  );

  printf(
    "VENCEDOR: %s (%d votos = %.2f%%)\nVICE: %s (%d votos = %.2f%%)",
    most_voted -> name,
    most_voted -> votes,
    (most_voted -> votes / (valid_votes * 1.0)) * 100.0,
    second_most_voted -> name,
    second_most_voted -> votes,
    (second_most_voted -> votes / (valid_votes * 1.0)) * 100.0
  );

  return 0;
};