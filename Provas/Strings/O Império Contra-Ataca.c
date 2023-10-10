#include <stdio.h>
#include <stdbool.h>

const char S[]=
  {'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z','.',',','?',' '};

int wordToIndex(char word) {
  for(int k = 0; k < 40; k++) {
    if(word == S[k]) {
      return k;
    };
  };
  
  return -1;
};

void calcKpIndexes(char KP[28], int KPI[28]) {
  for(int i = 0; i < 28; i++) {
    KPI[i] = wordToIndex(KP[i]);
  };
};

void decryptMessage(char C[200], int K[4]) {
  for(int i = 0; i < 200; i++) {
    if(C[i] == '\n' || C[i] == '\0') {
      break;
    } else {
      int oldIndex = wordToIndex(C[i]);
      int newIndex = oldIndex - K[i % 4];
      newIndex = newIndex < 0? 40 + newIndex:newIndex;

      C[i] = S[newIndex];
    };
  };

  printf("%d%d%d%d\n%s", K[0], K[1], K[2], K[3], C);
};

void decrypt(char C[200], char KP[28], int K[4]) {
  int kpIndexes[28];
  calcKpIndexes(KP, kpIndexes);

  bool end = false;
  for(int i = 0; i < 173; i++) {
    bool firstGroupIsChecked = false;
    bool decrypted = true;
    
    if(C[i] == '\n' || C[i] == '\0') {
      break;
    };

    for(int k = 0; k < 27; k++) {
      int base = k % 4;
      firstGroupIsChecked = (base == 0 && k > 0) || firstGroupIsChecked;

      if(C[i + k] == '\n' || C[i + k] == '\0') {
        end = true;
        break;
      };

      int gap = wordToIndex(C[i + k]) - kpIndexes[k];
      gap = gap < 0? 40 + gap:gap;

      int index = (i + base) % 4;

      if(!firstGroupIsChecked) {
        K[index] = gap;
      } else if(K[index] != gap) {
        decrypted = false;
        break;
      };
    };

    if(end) {
      break;
    } else if(decrypted) {
      return decryptMessage(C, K);
    };
  };

  printf("Mensagem nao e da Resistencia!");
};

int main() {
  const char KP[28] = "QUE A FORCA ESTEJA COM VOCE";
  
  int K[4] = {0};
  char C[200];

  fgets(C, sizeof(C), stdin);
  decrypt(C, KP, K);

  return 0;
};