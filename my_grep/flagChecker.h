//* добавляем FLAG_CHECKER_H в предпроцессор 🛠️
#ifndef FLAG_CHECKER_H
#define FLAG_CHECKER_H
#include "findMaxMy.h"

//* Создаем структуру с переменными флагов 0 - 1
typedef struct{
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} Flags;

//* Создаем массив символов флагов 
char *wordsArr[] = {"e","i","v","c","l","n","h","s","f","o"};

//* Создаем функцию которая на выходе выдаст структуру с результатами флагов
Flags flagChecker(int argc,char *argv[]){
  Flags flags = {0,0, 0, 0, 0, 0, 0, 0, 0, 0}; 


  //* Обработка флагов 🇷🇺
  for (int i = 1; i < argc; i++){
      for (int j = 1; j < (int)strlen(argv[i]); j++){
        if(argv[i][0] == '-'){
          switch(argv[i][j]) {
            case 'e':
              flags.e = 1;
              break;
            case 'i':
              flags.i = 1;
              break;
            case 'v':
              flags.v = 1;
              break;
            case 'c':
              flags.c = 1;
              break;
            case 'l':
              flags.l = 1;
              break;
            case 'n':
              flags.n = 1;
              break;
            case 'h':
              flags.h = 1;
              break;
            case 's':
              flags.s = 1;
              break;
            case 'f':
              flags.f = 1;
              break;
            case 'o':
              flags.o = 1;
              break;
            case '?':
              break;
          }
        }
      }
    }
  
  return flags;
}

#endif