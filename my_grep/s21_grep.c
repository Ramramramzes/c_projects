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
  
  //* Основная раскидка по массивам files и patterns
  for (int i = 1; i < argc; i++){
    if(!flags.allFlags && patterns[0] == NULL && argv[i][0] != '-'){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen++;
      continue;
    }
    if(flags.allFlags && !flags.e && argv[i][0] != '-'){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen++;
      continue;
    }
    if(flags.e && argv[i][0] != '-' && argv[i-1][(int)strlen(argv[i-1]) - 1] == 'e'){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen++;
      continue;
    }
    if(argv[i][0] != '-' && patternsLen != 0 && strstr(patterns[patternsLen - 1],argv[i]) == NULL){
      allFiles[filesLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(allFiles[filesLen], argv[i]);
      filesLen++;
      continue;
    }
  }


  grepPrint(flags,argc,argv,patterns,patternsLen,allFiles,filesLen);
  // for (int i = 0; i < patternsLen; i++){
  //   printf("Pat - %s\n",patterns[i]);
  // }
  // for (int i = 0; i < filesLen; i++){
  //   printf("Files - %s\n",allFiles[i]);
  // }

  // printf("%d",flags.e);
}