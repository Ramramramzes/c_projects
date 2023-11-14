//* добавляем PRINTFUNC_H в предпроцессор 🛠️
#ifndef PRINTFUNC_H
#define PRINTFUNC_H
#include "regex.h"

void printFunc(int argc, char *argv[],int maxFileString,char *searchWord, Flags flags,char *err[],int errSize) {
  char **searchFiles = (char**)malloc(argc * sizeof(char*));
  int lineNumArr[argc];
  for (int i = 0; i < argc; i++){
    FILE *file = fopen(argv[i],"r");
    //* Компиляция регулярного выражения
    
    int regexFlags = flags.i ? REG_ICASE : 0;
    
    // ! ------------->>> НАЧИНАЮ
    if(flags.n){
      maxFileString += 20;
    }

    char line[maxFileString];
    //todo добавим такой же while для -v только != 0
    int lineNum = 0;
    int lineCount = 0;



      while (fgets(line,maxFileString+strlen(argv[i]),file)){
        lineCount++;
        bool eflag = true;

        int boolCount = flags.e ? flags.eCounter : 1;

        regmatch_t pmatch[1];
        regex_t regex;

        for (int k = 0; k < boolCount; k++){
          if(boolCount == 1){
            regcomp(&regex, searchWord, regexFlags);
            if(regexec(&regex, line, 1, pmatch, 0) == 0){
              printf("%s", line);
            }

            int matchResult = flags.v ? regexec(&regex, line, 1, pmatch, 0) != 0 : regexec(&regex, line, 1, pmatch, 0) == 0;
            if(matchResult){
              //* Считаем строки совпадения
              lineNum++;
              // printf("%d - кол-во строк совпавших\n",lineNum);
              //* Добавляем файл в котором находим совпадения searchFiles;
              searchFiles[i] = argv[i];

              if(flags.n && !flags.c){
                argc > 1 ? printf("%s:%d:%s",argv[i],lineCount,line) : printf("%d:%s",lineCount,line);
              }

              //* без -h
              if (flags.i && !flags.h && !flags.c && !flags.l && !flags.n) {
                argc > 1 ? printf("%s:%s", argv[i], line) : printf("%s",line);
              }

              //* с -h
              if (flags.i && flags.h && !flags.c && !flags.l && !flags.n) {
                printf("%s", line);
              }
              
              if(!flags.i && !flags.c && !flags.l && !flags.n){
                printf("%s",line);
              }
            }
          }else{

              
            for (int j = 0; j < flags.eCounter; j++){
              regcomp(&regex, flags.eArgArr[j], regexFlags);
              if(regexec(&regex, line, 1, pmatch, 0) == 0){
                if(eflag){
                  eflag = false;
                  printf("%s", line);
                }
              }
            }
          }

        }








        if (flags.i) {
          regexFlags |= REG_ICASE;
        }


      }





    //* Добавляем перенос на следующую строку при переходе в новый файл
    if(flags.v && i != argc-1 && !flags.c && !flags.l){
      printf("\n");
    }

    //* Закрытие файла и освобождение ресурсов
    fclose(file);
    //todo needArg[] - массив с файлами
    //todo flags - флаги
    //todo searchWord - шаблон (без -е пока работаю)
    lineNumArr[i] = lineNum;

  }

  //! Файлы в которых найдено все
  //* без -h
  if(flags.l && flags.c && !flags.h){
    for (int i = 0; i < argc; i++){
      printf("%s:1\n",argv[i]);
      printf("%s\n",searchFiles[i]);
    }
  }else if(flags.l && flags.c && flags.h){
        for (int i = 0; i < argc; i++){
      printf("1\n");
      printf("%s\n",searchFiles[i]);
    }
  }else{
    if(flags.l){
      for (int i = 0; i < argc; i++){
        if(searchFiles[i] != NULL){
          printf("%s\n",searchFiles[i]);
        }
      }
    }
    //* без -h
    if(flags.c && !flags.h){
      for (int i = 0; i < argc; i++){
        printf("%s:%d\n",argv[i],lineNumArr[i]);
      }
    }
    //* c -h
    if(flags.c && flags.h){
      for (int i = 0; i < argc; i++){
        printf("%d\n",lineNumArr[i]);
      }
    }
  }

  if(!flags.s && !flags.v){
    for (int i = 0; i < errSize; i++){
      printf("grep: %s: Нет такого файла или директории\n",err[i]);
    }
  }else if(!flags.s && flags.v){
    printf("\n");
    for (int i = 0; i < errSize; i++){
      printf("grep: %s: Нет такого файла или директории\n",err[i]);
    }
  }

}

#endif