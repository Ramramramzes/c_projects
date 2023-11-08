//* добавляем FIND_WORD в предпроцессор 🛠️
#ifndef FIND_WORD
#define FIND_WORD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* findWord(int argc,char *argv[]){
//* Добавим фунцию для поиска поиска слова, которое нужно найти (идет сразу после флага, превое значение без '-')
  char *word = NULL;
  bool isNotFlag = false;
  for (int i = 1; i < argc; i++){
    if(argv[i][0] != '-' && isNotFlag == false){
      isNotFlag = true;
      word = strdup(argv[i]);
    }
  }
  return word;
}


#endif