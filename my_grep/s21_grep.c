#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "regex.h"
//* Старые версии
#include "flagChecker.h"
#include "print.h"
#include "printNFunc.h"
#include "printCLFunc.h"
//* Новые версии
#include "grepPrint.h"

int main(int argc, char *argv[]) {
  Flags flags = flagChecker(argc,argv);
  char ** patterns = (char **)calloc(argc ,sizeof(char*));
  char ** allFiles = (char **)calloc(argc ,sizeof(char*));
  int patternsLen = 0;
  int filesLen = 0;

  //* Проверка на наличие флагов
  bool allFlags = false;
  for (int i = 1; i < argc; i++){
    if(argv[i][0] == '-'){
      allFlags = true;
      break;
    }
  }

  //* Основная раскидка по массивам files и patterns
  for (int i = 1; i < argc; i++){
    int prevLen = i > 1 ? (int)strlen(argv[i - 1]) : 0;
    if(!allFlags){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen = 1;
    }
    if(allFlags && !flags.e && argv[i][0] != '-'){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen = 1;
    }
    if(flags.e && argv[i][0] != '-' && argv[i-1][prevLen -1] == 'e' && flags.e){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen++;
    }
    if(argv[i][0] != '-' && strstr(patterns[patternsLen - 1],argv[i]) == 0){
      allFiles[filesLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(allFiles[filesLen], argv[i]);
      filesLen++;
    }
  }


  grepPrint(flags,argc,argv,patterns,patternsLen,allFiles,filesLen);
  // for (int i = 0; i < patternsLen; i++){
  //   printf("Pat - %s\n",patterns[i]);
  // }
  

  // printf("%d",flags.e);
}