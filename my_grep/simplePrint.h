//* добавляем SIMPLE_PRINT в предпроцессор 🛠️
#ifndef SIMPLE_PRINT
#define SIMPLE_PRINT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "findWord.h"
#include "findStrSize.h"

void simplePrint(int argc,char *argv[]){
//* Добавим фунцию для поиска поиска слова, которое нужно найти (идет сразу после флага, превое значение без '-')
  char* foundWord = findWord(argc,argv);
  bool coincidence = false;
  int needNum = 0;
  //* Находим индекс нашего текстового содержимого NeedNum;
  for (int i = 1; i < argc; i++){
    for (int j = 0; j < (int)strlen(argv[i]); j++){
      if(foundWord[j] == argv[i][j] && argv[i][0] != '-'){
        coincidence = true;
      }else{
        coincidence = false;
      }
    }
    if(coincidence){
      needNum = i;
      break;
    }
  }

  printf("%d",findStrSize(argc,argv,needNum)); //! Находим максимальную длину строки для создания буфера

//! Исправить ошибку сравнения *foundWord 
  // for (int i = needNum+1; i < argc; i++){
  //   FILE *file = fopen(argv[i], "r");

  //   char line[findStrSize(argc,argv,needNum)];  // Максимальная длина строки
  //   while (fgets(line, sizeof(line), file) != NULL) {
  //       if (strstr(line, findWord) != NULL) {
  //           printf("%s", line);
  //       }
  //   }
  // }
  
  

  free(foundWord);
}

#endif