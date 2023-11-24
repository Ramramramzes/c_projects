#include "myHeader.h"

void simplePrint(char *argv[]) {
  FILE *file = fopen(argv[1], "r");
  int ch;
  //* Печатаем просто весь файл
  while ((ch = fgetc(file)) != EOF) {
    fputc(ch, stdout);
  }
}