//* добавляем PRINT_FILE_H в предпроцессор 🛠️
#ifndef PRINT_FILE_H
#define PRINT_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "flagChecker.h"

//* Фунция добавялет символы в stdout
void printFile(Flags flagsObj, int argc, char *argv[]){
  //* Пропускаем ./a.out и -флаги начинаем с 2
  for(int i = 2; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    char ch;
    int circles = 0;
    bool newRow = true;
    int lineCount = 1;
    //* Поштучно сравниваем каждый символ, добавим проверку каждого флага в while
    while((ch = fgetc(file)) != EOF){
    //* Обработка флагов 🇷🇺
/*🚩*/if(flagsObj.s == 1){
//* Использую переменную circles для вычисления момента где будут идти 3 \n подряд чтобы схлопнуть строку
        if(ch == '\n' && newRow){
          circles++;
          if(circles >= 2){
            continue;
          }
        }
      }
/*🚩*/if(flagsObj.b == 1){
        //* Циклами добавляю пробелы при использовании -b в cat выводится с пробелами 
        if(newRow && ch != '\n'){
          fprintf(stdout,"     %d	",lineCount);//!🚨 После %d идет → TAB 
          lineCount++;
        }else if(newRow){
          for (int k = 0; k < 8; k++){
            fputc(' ', stdout);
          }
          
        }
      }
/*🚩*/if(flagsObj.n == 1 && flagsObj.b != 1){
        //* Циклами добавляю пробелы при использовании -b в cat выводится с пробелами 
        if(newRow){
          fprintf(stdout,"     %d	",lineCount);//!🚨 После %d идет → TAB 
          lineCount++;
        }
      }
/*🚩*/if(flagsObj.e == 1){
        //* Просто добавляем $ после каждого \n
        if(ch == '\n'){
          fputc('$', stdout);
        }
      }
/*🚩*/if(flagsObj.t == 1){
  //!🚨 CH == → TAB 
  //* Находим TAB и заменяем его двумя символами
  if(ch == '	'){
    fputc('^',stdout);
    fputc('I',stdout);
    //* Заменяем ch на пустоту
    ch = '\0';
  }
}
      //* Каждую итерацию проверяем newRow является ли новой строкой
      newRow = (ch == '\n');
      //* Каждую итерацию выводим в символ в stdout
      fputc(ch, stdout);
    }
  }

}
#endif
