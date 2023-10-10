#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool processMessage(char message[200], int indexes[200], const char S[40]) {
  for(int i = 0; i < 200; i++) {
    if(message[i] == '\0' || message[i] == '\n') {
      indexes[i] = -1;
      return true;
    }

    bool detected = false;
    for(int c = 0; c < 40; c++) {
      if(S[c] == message[i]) {
        detected = true;
        indexes[i] = c;
        break;
      };
    }

    if(!detected) {
      return false;
    };
  };

  return true;
};

void encode(int indexes[200], const char S[40], int keys[4], char encondedMessage[200]) {
  int key = 0;
  for(int i = 0; i < 200; i++) {
    int oldIndex = indexes[i];

    if(oldIndex == -1) {
      encondedMessage[i] = '\0';
      break;
    };

    int newIndex = (oldIndex + keys[key]) % 40;
    key = (key + 1) % 4;

    encondedMessage[i] = S[newIndex];
  };
};

int main() {
  char encondedMessage[200];
  char message[200];
  int keys[4];
  const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

  char strkeys[7];

  fgets(strkeys, sizeof(strkeys), stdin);

  if(strlen(strkeys) > 5) {
    printf("Chave invalida!");
    return 0;
  };

  for(int i = 0; i < 4; i++) {
    keys[i] = strkeys[i] - '0';
  };
  
  fflush(stdin);
  fgets(message, sizeof(message), stdin);

  int indexes[200];

  if(processMessage(message, indexes, S)) {
    encode(indexes, S, keys, encondedMessage);
    printf("%s", encondedMessage);
  } else {
    printf("Caractere invalido na entrada!");
  };

  return 0;
};