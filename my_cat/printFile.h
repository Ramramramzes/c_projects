#ifndef PRINT_FILE_H
#define PRINT_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "flagChecker.h"



int printFile(Flags flagsObj, int argc, char *argv[]){ 
  //* Пропускаем ./a.out и -флаги начинаем с 2
  for(int i = 2; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    char ch;
    bool newRow = true;
    bool firstIter = true;
    int lineCount = 1;
//! ДОБАВИТЬ САМОУНИЧТОЖАЮЩИЕСЯ ФЛАГИ ТИПА -b -n (срабатывает -b только) проверить 🚨🚨🚨🚨🚨
    //* Поштучно сравниваем каждый символ, добавим проверку каждого флага в while
    while((ch = fgetc(file)) != EOF){
      //* Обработка флагов 🇷🇺
/*🚩*/if(flagsObj.b == 1){
        //* Циклами добавляю пробелы при использовании -b в cat выводится с пробелами 
        if(firstIter && newRow){
          for (int k = 0; k < 5; k++){
            fputc(' ',stdout);
          }
          fprintf(stdout,"%d",lineCount);
          for (int k = 0; k < 2; k++){
            fputc(' ',stdout);
          }
          lineCount++;
        }else if(newRow){
          for (int k = 0; k < 5; k++){
            fputc(' ',stdout);
          }
          if(ch != '\n'){
            fprintf(stdout,"%d",lineCount);
            lineCount++;
          }
          for (int k = 0; k < 2; k++){
            fputc(' ',stdout);
          }
        }
        fputc(ch, stdout);
        newRow = (ch == '\n');
        firstIter = false;
      }
/*🚩*/if(flagsObj.e == 1 && ch == '\n'){
          fputc('$', stdout);
          fputc('\n', stdout);
      }else if(flagsObj.e == 1){
        fputc(ch, stdout);
      }

/*🚩*/if(flagsObj.n == 1){
        //* Циклами добавляю пробелы при использовании -b в cat выводится с пробелами 
        if(firstIter && newRow){
          for (int k = 0; k < 5; k++){
            fputc(' ',stdout);
          }
          fprintf(stdout,"%d",lineCount);
          for (int k = 0; k < 2; k++){
            fputc(' ',stdout);
          }
          lineCount++;
        }else if(newRow){
          for (int k = 0; k < 5; k++){
            fputc(' ',stdout);
          }
          fprintf(stdout,"%d",lineCount);
          for (int k = 0; k < 2; k++){
            fputc(' ',stdout);
          }
          lineCount++;
        }else if(newRow && ch == '\n'){
          for (int k = 0; k < 8; k++){
            fputc(' ',stdout);
          }
        }
        
        fputc(ch, stdout);
        newRow = (ch == '\n');
        firstIter = false;
      }
    }
  }
  return 0;
}

#endif
