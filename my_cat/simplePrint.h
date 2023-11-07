#ifndef SIMPLE_PRINT_H
#define SIMPLE_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "flagChecker.h"



//todo ДОПИСАТЬ КОММЕНТАРИИ К КАЖДОМУ ВЕЗДЕ 💬
void simplePrint(int argc, char *argv[]){
  for(int i = 1; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    char ch;
    while((ch = fgetc(file)) != EOF){
      fputc(ch, stdout);
    }
  }
}
#endif
