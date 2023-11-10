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
#include "printFunc.h"

int main(int argc, char *argv[]) {
  Flags flags = flagChecker(argc,argv);
  printf("%d",flags.e); //! Чтобы не крашилось
  //* Поиск искомого слова
    char *searchWord = NULL;
    for (int i = optind; i < argc; i++) {
        if (argv[i][0] != '-') {
            searchWord = argv[i];
            optind += 1;
            break;
        }
    }
  
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
      // printf("argument: %s\n", argv[i]); //* Печать аргументов
    }
  }

  int maxFileString = findStrSize(needArgCount,needArg);
  //!------------------------------------------------------------------------|
  printFunc(argc,argv,maxFileString,searchWord); //! Основная функция вывода |
  //!------------------------------------------------------------------------|
  // printf("Максимальная длинна строки файлов - %d\n",maxFileString); //! Вывод максимальной длины строки
  // printf("Слово для поиска - %s\n",searchWord); //! Вывод слова для поиска
  

  //* Освобождаем выделенную память
  for (int i = 0; i < needArgCount; i++) {
      free(needArg[i]);
  }

  free(needArg);
  exit(EXIT_SUCCESS);
}



