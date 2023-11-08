//* добавляем SIMPLE_PRINT в предпроцессор 🛠️
#ifndef SIMPLE_PRINT
#define SIMPLE_PRINT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "findWord.h"

void simplePrint(int argc,char *argv[]){
//* Добавим фунцию для поиска поиска слова, которое нужно найти (идет сразу после флага, превое значение без '-')
  char* foundWord = findWord(argc,argv);

  printf("%s",foundWord);
  free(foundWord);
}

#endif