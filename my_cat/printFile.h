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
    bool emptyLine = false;
    int lineCount = 1;
    int temp = 2; //* Не смог иначе обойти 🙈
//! ДОБАВИТЬ САМОУНИЧТОЖАЮЩИЕСЯ ФЛАГИ ТИПА -b -n (срабатывает -b только) проверить 🚨🚨🚨🚨🚨
    //* Поштучно сравниваем каждый символ, добавим проверку каждого флага в while
    while((ch = fgetc(file)) != EOF){
      //* Обработка флагов 🇷🇺
/*🚩*/if(flagsObj.s == 1){
        if(ch == '\n'){
          if(temp == 0 && emptyLine && newRow){
            continue;
          }
          temp--;
          emptyLine = true;
        }
      }
/*🚩*/if(flagsObj.b == 1){
        //* Циклами добавляю пробелы при использовании -b в cat выводится с пробелами 
        if(newRow && ch != '\n'){
          fprintf(stdout,"     %d  ",lineCount);
          lineCount++;
        }else if(newRow){
          for (int k = 0; k < 8; k++){
            fputc(' ', stdout);
          }
          
        }
      }
/*🚩*/if(flagsObj.n == 1){
        //* Циклами добавляю пробелы при использовании -b в cat выводится с пробелами 
        if(newRow){
          fprintf(stdout,"     %d  ",lineCount);
          lineCount++;
        }
      }
/*🚩*/if(flagsObj.e == 1){
        if(ch == '\n'){
          fputc('$', stdout);
        }
      }
      newRow = (ch == '\n');
      fputc(ch, stdout);
    }
  }
  return 0;
}
#endif
