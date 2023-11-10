#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
//todo opt - символ текущей опции
//todo optarg - указатель на аргумент текущей опции
//todo optopt - символ неизвестной опции
//todo optind - индекс следующего аргумента при очередном вызове getopt - указывает на НЕ ОПЦИЮ (АРГУМЕНТ)

#include "findMax.h"
#include "flagChecker.h"

int main(int argc, char *argv[]) {
  Flags flags = flagChecker(argc,argv);
  
  //* Обработка аргументов (файлов) 📁
  char **needArg = NULL; //* Создаем указатель на указатели (массив строк)
  int needArgCount = 0; //* Переменная для подсчета аргументов
  for (int i = optind; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    if(file == NULL){
      printf("Файла с именем %s не существует\n",argv[i]);
    }else{
      needArgCount++;
      needArg = (char **)realloc(needArg, needArgCount * sizeof(char *));
      needArg[needArgCount - 1] = strdup(argv[i]);  // Копируем строку в массив
      fclose(file);
      printf("argument: %s\n", argv[i]);
    }
  }

  int maxFileString = findStrSize(needArgCount,needArg);
  
  printf("Максимальная длинна строки файлов - %d",maxFileString);
  


  free(needArg);
  exit(EXIT_SUCCESS);
}



