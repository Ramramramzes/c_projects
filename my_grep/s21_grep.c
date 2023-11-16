#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "flagChecker.h"

int main(int argc, char *argv[]) {
  Flags flags = flagChecker(argc,argv);

  //* Если флагов нет, первый эллемент будет искомым остальное все обрабатывается как файлы, если нет то в эррор(мб вынести)
  bool noFlag = true;
  for (int i = 1; i < argc; i++){
    if(argv[i][0] == '-'){
      noFlag = false;
    }
  }

  char** filesFromCom = NULL;
  int fromComCount = 0;
  char* searchWord = NULL;
  //* Если флагов нет
  if(noFlag){
    searchWord = argv[1];
    filesFromCom =(char**)calloc(argc-2,sizeof(char*));
    for (int i = argc-(argc-2); i < argc; i++){
      filesFromCom[fromComCount] = argv[i];
      fromComCount++;
    }
  //* Если флаги есть
  }else{
    filesFromCom =(char**)calloc(argc,sizeof(char*));
    if(!flags.e && !flags.f){
      for (int i = 1; i < argc; i++){
        if(argv[i][0] != '-' && searchWord == NULL){
          searchWord = argv[i];
        }//! Добавить сюда обработку error, добавить массив ошибок для вывода
      }
    }
    for (int i = 1; i < argc; i++){
      if(argv[i][0] != '-' && argv[i] != searchWord){
        filesFromCom[fromComCount] = argv[i];
        fromComCount++;
      }
    }
  }
  // printf("%d\n",flags.fileSearchCount);
  // printf("%d\n",flags.eCounter);
  // printf("%s\n",flags.eArgArr[0]);

  for (int i = 0; i < fromComCount ; i++){
    printf("%s",filesFromCom[i]);
  }
  printf("\n%s",searchWord);
}




