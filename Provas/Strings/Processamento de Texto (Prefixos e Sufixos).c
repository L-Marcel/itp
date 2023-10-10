#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void removeSuffix(
  int ss, 
  char suffixes[ss][100], 
  char word[100]
) {
  int size = strlen(word);
  for(int i = 0; i < ss; i++) {
    int susize = strlen(suffixes[i]);
    for(int d = 0; d <= susize; d++) {
      if(suffixes[i][susize - d] != word[size - d] || susize > size) {
        break;
      } else if(d == susize) {
        word[size - d] = '\0';
        return;
      };
    };
  };
};

void removePrefix(
  int sp, 
  char prefixes[sp][100], 
  char word[100]
) {
  int size = strlen(word);
  for(int i = 0; i < sp; i++) {
    int presize = strlen(prefixes[i]);
    for(int w = 0; w < presize; w++) {
      if(prefixes[i][w] != word[w] || presize > size) {
        break;
      } else if(w == presize - 1) {
        for(int k = 0; k < size; k++) {
          if(k >= size - presize) {
            word[k] = '\0';
            return;
          } else {
            word[k] = word[w + k + 1];
          };
        };
      };
    };
  };
};

void process(
  int sp, 
  char prefixes[sp][100], 
  int ss, 
  char suffixes[ss][100],
  void (*callback)()
) {
  char word[100];
  scanf("%s[^\n]", word);
  fflush(stdin);

  if(strcmp(word, "-1") == 0) {
    if(callback != NULL) {
      callback();
    };
    
    return;
  };

  void next() {
    if(callback != NULL) {
      callback();
    };

    removePrefix(sp, prefixes, word);
    removeSuffix(ss, suffixes, word);
    if(strcmp(word, "") != 0) {
      printf("%s\n", word);
    };
  };

  process(sp, prefixes, ss, suffixes, next);
};

int main() {
  int sp, ss;

  scanf("%d", &sp);
  
  char prefixes[sp][100];

  for(int i = 0; i < sp; i++) {
    scanf("%s[^\n]", prefixes[i]);
  };

  scanf("%d", &ss);
  
  char suffixes[ss][100];

  for(int i = 0; i < ss; i++) {
    scanf("%s[^\n]", suffixes[i]);
  };

  process(sp, prefixes, ss, suffixes, NULL);
  
  return 0;
};