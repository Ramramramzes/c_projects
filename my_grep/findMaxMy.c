#include "myHeader.h"

int findStrSize(int argc, char *argv[]) {
  int maxLength = 0;
  int currentLength = 0;
  int ch;
  for (int i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file) {
      while ((ch = fgetc(file)) != EOF) {
        if (ch != '\n' && ch != ' ') {
          currentLength++;
        } else {
          if (currentLength > maxLength) {
            maxLength = currentLength;
          }
          currentLength = 0;
        }
      }
      if (file) {
        fclose(file);
      }
    }
  }
  //* Проверка последней строки, если она самая длинная
  if (currentLength > maxLength) {
    maxLength = currentLength;
  }
  return maxLength+1000;
}
