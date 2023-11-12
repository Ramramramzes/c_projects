//* добавляем PRINTFUNC_H в предпроцессор 🛠️
#ifndef PRINTFUNC_H
#define PRINTFUNC_H
#include "regex.h"

void printFunc(int argc, char *argv[],int maxFileString,char *searchWord, Flags flags) {
  char **searchFiles = (char**)malloc(argc * sizeof(char*));
  int lineNumArr[argc];
  for (int i = 0; i < argc; i++){
    FILE *file = fopen(argv[i],"r");
    if(file == NULL){
      printf("Файла %s не существует\n",argv[i]);
      break;
    }else{
      //* Компиляция регулярного выражения
      regex_t regex;
      int regexFlags = flags.i ? REG_ICASE : 0;
      
      if (regcomp(&regex, searchWord, regexFlags) != 0) {
          fprintf(stderr, "Ошибка компиляции регулярного выражения\n");
          exit(EXIT_FAILURE);
      }

      if(flags.n){
        maxFileString += 20;
      }

      char line[maxFileString];
      //todo добавим такой же while для -v только != 0
      int lineNum = 0;
      int lineCount = 0;
      // char **searchFiles = (char**)malloc(argc * sizeof(char*));


        while (fgets(line,maxFileString+strlen(argv[i]),file)){
          lineCount++;
          regmatch_t pmatch[1];

          if (flags.i) {
            regexFlags |= REG_ICASE;
          }
          if(!flags.v){
            //* Если флага -v НЕТ
            if (regexec(&regex, line, 1, pmatch, 0) == 0) {
              //* Считаем строки совпадения
              lineNum++;
              // printf("%d - кол-во строк совпавших\n",lineNum);
              //* Добавляем файл в котором находим совпадения searchFiles;
              searchFiles[i] = argv[i];

              if(flags.n && !flags.c){
                printf("%s:%d:%s",argv[i],lineCount,line);
              }

              //* без -h
              if (flags.i && !flags.h && !flags.c && !flags.l && !flags.n) {
                printf("%s:%s", argv[i], line);
              }
              //* с -h
              if (flags.i && flags.h && !flags.c && !flags.l && !flags.n) {
                printf("%s", line);
              }
              
            }
          }else{
            //* Если флаг -v 
            if (regexec(&regex, line, 1, pmatch, 0) != 0) {
              //* Считаем строки совпадения
              lineNum++;
              // printf("%d - кол-во строк совпавших\n",lineNum);
              //* Добавляем файл в котором находим совпадения searchFiles;
              searchFiles[i] = argv[i];

              if(flags.n && !flags.c){
                printf("%s:%d:%s",argv[i],lineCount,line);
              }
              //* без -h
              if (flags.i && !flags.h && !flags.c && !flags.l && !flags.n) {
                printf("%s:%s", argv[i], line);
              }
              //* с -h
              if (flags.i && flags.h && !flags.c && !flags.l && !flags.n) {
                printf("%s", line);
              }

              if (flags.v && !flags.i && !flags.c && !flags.l && !flags.n) {
                printf("%s:%s", argv[i], line);
              }
            }
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

      // printf("<%d>",lineCount);//! lineCount - это строки файл
    }
    //! Вывод идет в конце каждого файла
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
}

#endif