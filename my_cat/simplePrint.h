#ifndef SIMPLE_PRINT_H
#define SIMPLE_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "flagChecker.h"



//todo ДОПИСАТЬ КОММЕНТАРИИ К КАЖДОМУ ВЕЗДЕ 💬
void simplePrint(char *argv[]){
  FILE *file = fopen(argv[1], "r");
  char ch;
  while((ch = fgetc(file)) != EOF){
    fputc(ch, stdout);
  }
}
#endif
