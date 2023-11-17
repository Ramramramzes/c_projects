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
  //* БЕЗ ФЛАГОВ, поиск слова 
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
    //* Находим искомое слово если нет e и f
    if(!flags.e && !flags.f){
      for (int i = 1; i < argc; i++){
        if(argv[i][0] != '-' && searchWord == NULL){
          searchWord = argv[i];
        }//! Добавить сюда обработку error, добавить массив ошибок для вывода
      }
    }
    //* Ищем файлы в которых будет проиходить поиск
    for (int i = 1; i < argc; i++){
      if(argv[i][0] != '-' && argv[i] != searchWord){
        //* проверим есть ли слово уже в массиве
        bool isInfiles = false;
        for (int j = 0; j < fromComCount; j++) {
          if (strcmp(argv[i], filesFromCom[j]) == 0) {
            isInfiles = true;
            break;
          }
        }
        FILE *file = fopen(argv[i],"r");
        if(file && isInfiles == false){
          filesFromCom[fromComCount] = argv[i];
          fromComCount++;
        }
      }
    }
  }

  for (int i = 0; i < fromComCount ; i++){
    printf("%s\n",filesFromCom[i]);
  }
  // for (int i = 0; i < flags.fileSearchCount ; i++){
  //   printf("%s\n",flags.fileSearchWords[i]);
  // }
  // for (int i = 0; i < flags.eCounter ; i++){
  //   printf("%s\n",flags.eArgArr[i]);
  // }
  // printf("\n%s",searchWord);
}




