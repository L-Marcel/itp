#include <stdio.h>
#include <stdbool.h>

void populate(int length, int vector[length]) {
  for(int i = 0; i < length; i++) {
    vector[i] = 0;
  };
};

bool alreadyExists(int length, int vector[length], int value) {
  for(int i = 0; i < length; i++) {
    if(vector[i] == value) {
      return true;
    };
  };
  
  return false;
};

int countUniques(int length, int database[length]) {
  int count = 0;
  int listToCompare[length];
  populate(length, listToCompare);

  bool zeroCount = false;
  for(int i = 0; i < length; i++) {
    if(!alreadyExists(length, listToCompare, database[i])) {
      listToCompare[count] = database[i];
      count++;
    } else if(!zeroCount && database[i] == 0) {
      zeroCount = true;
      count++;
    };
  };

  return count;
};

void filterClients(int length, int total, int database[length], int clients[total]) {
  int index = 0;
  for(int i = 0; i < length; i++) {
    if(!alreadyExists(total, clients, database[i])) {
      clients[index] = database[i];
      index++;
    };
  };
};

void sort(int length, int vector[length]) {
  int sorted[length];
  populate(length, sorted);

  bool zeroCount = false;
  int count = 0;
  for(int i = 0; i < length; i++) {
    int min = vector[i];
    for(int j = 0; j < length; j++) {
      if((!alreadyExists(length, sorted, vector[j]) || (!zeroCount && vector[j] == 0)) && vector[j] < min) {
        min = vector[j];
        if(vector[j] == 0) {
          zeroCount = true;
        };
      } else if(alreadyExists(length, sorted, min)) {
        min = vector[j];
      };
    };

    sorted[i] = min;
  };

  for(int i = 0; i < length; i++) {
    vector[i] = sorted[i];
  };
};

int main() {
  int length;
  scanf("%d", &length);

  int database[length];
  for(int i = 0; i < length; i++) {
    scanf("%d", &database[i]);
  };

  int numberOfClients = countUniques(length, database);
  int clients[numberOfClients];

  populate(numberOfClients, clients);
  filterClients(length, numberOfClients, database, clients);
  sort(numberOfClients, clients);

  for(int i = 0; i < numberOfClients; i++) {
    printf("%d ", clients[i]);
  };

  return 0;
};