//* добавляем PRINTFUNC_H в предпроцессор 🛠️
#ifndef PRINTFUNC_H
#define PRINTFUNC_H
#include "regex.h"

void printFunc(int argc, char *argv[],int maxFileString,char *searchWord, Flags flags) {
  char **searchFiles = (char**)malloc(argc * sizeof(char*));
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
      if (flags.i && !flags.v) {
        regexFlags |= REG_ICASE;
        //* Плюсуем еще к строке название файла, а то не помещается вывод
        while (fgets(line,maxFileString+strlen(argv[i]),file)){
          lineCount++;
          regmatch_t pmatch[1];
          if (regexec(&regex, line, 1, pmatch, 0) == 0) {
            //!  Данные которые тут вобью нужно использовать 3 раза -i / -v / -iv / без -iv
            //* Считаем строки совпадения
            lineNum++;
            printf("%d - кол-во строк совпавших\n",lineNum);
            //* Добавляем файл в котором находим совпадения searchFiles;
            searchFiles[i] = argv[i];
            //* Вывод строки файла если совпало
            printf("%d: - номер совпавшей строки\n",lineCount);
          }
        }
      }
      
      if (flags.i && flags.v) {
        regexFlags |= REG_ICASE;
        //* Плюсуем еще к строке название файла, а то не помещается вывод
        while (fgets(line,maxFileString+strlen(argv[i]),file)){
          regmatch_t pmatch[1];
          if (regexec(&regex, line, 1, pmatch, 0) != 0) {
              printf("%s:%s", argv[i], line);
          }
        }
      }

      //* Добавляем перенос на следующую строку при переходе в новый файл
      printf("\n");

      //* Закрытие файла и освобождение ресурсов
      fclose(file);
      //todo needArg[] - массив с файлами
      //todo flags - флаги
      //todo searchWord - шаблон (без -е пока работаю)


    // printf("<%d>",lineCount);//! lineCount - это строки файл
    }
    //! Вывод идет в конце каждого файла
  }

  
  for (int i = 0; i < argc; i++){
    if(searchFiles[i] != NULL){
      printf("%s\n",searchFiles[i]);
    }
  }
}

#endif