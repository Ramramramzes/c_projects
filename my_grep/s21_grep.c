#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "regex.h"

#include "flagChecker.h"
// #include "printFile.h"

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





//! Обычный вывод grep без флагов
  if (searchWord != NULL && filesFromCom != NULL) {
    int maxStrSize = findStrSize(argc,argv);
    char line[maxStrSize];

    for (int k = 0; k < fromComCount; k++){
      FILE *file = fopen(filesFromCom[k],"r");
      while (fgets(line,maxStrSize,file)){
        if(strstr(line, searchWord) != NULL){
          printf("%s",line);
        }
      }
      fclose(file);
    }
  }


//! Вывод grep с флагом -i
    if(flags.i){
      int maxStrSize = findStrSize(argc,argv);
      char line[maxStrSize];

      for (int k = 0; k < fromComCount; k++){
        FILE *file = fopen(filesFromCom[k],"r");

        int regexFlags = 0;
        regex_t regex;
        regexFlags |= REG_ICASE;

        if (regcomp(&regex, searchWord, regexFlags) != 0) {
          fprintf(stderr, "Ошибка компиляции регулярного выражения\n");
          exit(EXIT_FAILURE);
        }


        while (fgets(line,maxStrSize,file)){
          regmatch_t pmatch[1];
          if (regexec(&regex, line, 1, pmatch, 0) == 0) {
              printf("%s", line);
          }
        }

        fclose(file);
      }
    }
  




  //! Функции для декомпозиции
  // printFile(argc,argv,flags,filesFromCom,fromComCount,searchWord);

}




