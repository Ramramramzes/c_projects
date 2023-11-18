#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "regex.h"

#include "flagChecker.h"
#include "print.h"
#include "printFunc.h"

int main(int argc, char *argv[]) {
  Flags flags = flagChecker(argc,argv);
  int maxStrSize = findStrSize(argc,argv);
  // printf("%d",maxStrSize);
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
  // basePrint(searchWord,filesFromCom,fromComCount,maxStrSize);


//! Вывод grep с флагом -i
      char line[maxStrSize];

      for (int k = 0; k < fromComCount; k++){
        FILE *file = fopen(filesFromCom[k],"r");

        int regexFlags = 0;
        regex_t regex;

        if(flags.i){
          regexFlags |= REG_ICASE;
        }

        if(!flags.e && !flags.f){
          regcomp(&regex, searchWord, regexFlags);
        }

        int strNumber = 0;
        int strCounter = 0;
        while (fgets(line,maxStrSize,file)){ //! Исправить ошибку пустых строк(убрать вывод)
          regmatch_t pmatch[1];
          bool wasPrint = false;
          bool flagV = false;
          strNumber++;
          for (int l = 0; l < flags.eCounter; l++){
            regcomp(&regex, flags.eArgArr[l], regexFlags);
            if(!flags.v){
              if (regexec(&regex, line, 1, pmatch, 0) == 0) {
                strCounter++;
                if(wasPrint){
                  continue;
                }else{
                  if(l == flags.eCounter-1){
                    myMainPrint(flags,strNumber,line,filesFromCom[k],fromComCount);
                    wasPrint = true;
                  }else{
                    myMainPrint(flags,strNumber,line,filesFromCom[k],fromComCount);
                    wasPrint = true;
                  }
                }
              }
            }else if(flags.v){
              if (regexec(&regex, line, 1, pmatch, 0) == 0) {
                strCounter++;
                flagV = true;
              }
            }
          }

          if(!flagV && flags.v){
            myMainPrint(flags,strNumber,line,filesFromCom[k],fromComCount);
          }



        }//! конец цикла while
        
          printf("%d",strCounter);
        fclose(file);
      }
  




  //! Функции для декомпозиции
  // printFile(argc,argv,flags,filesFromCom,fromComCount,searchWord);

}




