//* добавляем PRINTFUNC_H в предпроцессор 🛠️
#ifndef PRINTFUNC_H
#define PRINTFUNC_H
#include "regex.h"

void printFunc(int argc, char *argv[],int maxFileString,char *searchWord, Flags flags) {
  for (int i = 0; i < argc; i++){
    FILE *file = fopen(argv[i],"r");
    if(file == NULL){
      printf("Файла %s не существует\n",argv[i]);
      break;
    }else{
      //* Компиляция регулярного выражения
      regex_t regex;
      int regexFlags = 0;


      if (regcomp(&regex, searchWord, regexFlags) != 0) {
          fprintf(stderr, "Ошибка компиляции регулярного выражения\n");
          exit(EXIT_FAILURE);
      }
      char line[maxFileString];
    //todo добавим такой же while для -v только != 0
      if (flags.i && !flags.v) {
        regexFlags |= REG_ICASE;
        //* Плюсуем еще к строке название файла, а то не помещается вывод
        while (fgets(line,maxFileString+strlen(argv[i]),file)){
          regmatch_t pmatch[1];
          if (regexec(&regex, line, 1, pmatch, 0) == 0) {
              printf("%s:%s", argv[i], line);
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



    }
  }
  
}

#endif