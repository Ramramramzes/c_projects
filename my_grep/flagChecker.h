//* добавляем FLAG_CHECKER_H в предпроцессор 🛠️
#ifndef FLAG_CHECKER_H
#define FLAG_CHECKER_H
#include "findMax.h"

//* Создаем структуру с переменными флагов 0 - 1
typedef struct{
  int e;
  char **eArgArr;
  char **fileSearchWords;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int eCounter;
  int fileSearchCount;
} Flags;

//* Создаем массив символов флагов 
char *wordsArr[] = {"e","i","v","c","l","n","h","s","f","o"};


//* Создаем функцию которая на выходе выдаст структуру с результатами флагов
Flags flagChecker(int argc,char *argv[]){
  Flags flags = {0, NULL,NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
  int eLength = 0;

  for (int i = 0; i < argc; i++){
    if(strchr(argv[i],'-') && strchr(argv[i],'e')) {
      eLength++;
    }
  }

  flags.eArgArr = (char**)calloc(eLength, sizeof(char*));

  //* Обработка флагов 🇷🇺
  for (int i = 1; i < argc; i++){
    bool eflagBool = false;
    //* Флаги идут по одному 1️⃣    
    if(argv[i][0] == '-' && strlen(argv[i]) == 2){
      if(argv[i][1] == 'f'){
        FILE *file = fopen(argv[i+1],"r");
        //* Выделяем максимальное значение для буфера исходя из всех файлов 
        char line[findStrSize(argc,argv)];
        while(fgets(line,sizeof(line),file)){
          flags.fileSearchCount++;
          flags.fileSearchWords = (char **)realloc(flags.fileSearchWords, flags.fileSearchCount * sizeof(char *));
          flags.fileSearchWords[flags.fileSearchCount - 1] = strdup(line);
        }
      }
      switch(argv[i][1]) {
        case 'e':
          if(!eflagBool){
            flags.e = 1;
            flags.eArgArr[flags.eCounter] = strdup(argv[i+1]);
            i++;
            flags.eCounter++;
            eflagBool = true;
          }
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
    //* Флаги идут пачкой 💯
    if(argv[i][0] == '-' && strlen(argv[i]) != 2){
      if(strchr(argv[i],'e') && i < argc ){
        if(!eflagBool){
          flags.e = 1;
          flags.eArgArr[flags.eCounter] = strdup(argv[i+1]);
          flags.eCounter++;
          eflagBool = true;
        }
      }
      //*------------ Обработка события -ef добавить break где-нибудь для прерывания
      bool eBlock = false;
      bool fBlock = false;
      for (int j = 1; j < (int)strlen(argv[i]); j++){
        if(argv[i][j] == 'e'){
          eBlock = true;
        }
        if(argv[i][j] == 'f'){
          fBlock = true;
        }
        if(eBlock && fBlock){
          printf("Не может быть и f и e в одном флаге");
        }
        //*---------------------------------------------------------------------------
        switch(argv[i][j]) {
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


  if(flags.e && flags.f){
    flags.eArgArr = (char **)realloc(flags.eArgArr,flags.fileSearchCount * sizeof(char *));
    for (int i = 0; i < flags.fileSearchCount; i++){
      flags.eArgArr[flags.eCounter + i] = flags.fileSearchWords[i];
    }
    flags.eCounter += flags.fileSearchCount;
  }
  
  return flags;
}

#endif