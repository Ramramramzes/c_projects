#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
//todo opt - символ текущей опции
//todo optarg - указатель на аргумент текущей опции
//todo optopt - символ неизвестной опции
//todo optind - индекс следующего аргумента при очередном вызове getopt - указывает на НЕ ОПЦИЮ (АРГУМЕНТ)

int main(int argc, char *argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "eivcln")) != -1) {
    switch(opt) {
      case 'e':
        printf("Выбран %c\n", opt);
      break;
      case 'i':
        printf("Выбран %c\n", opt);
      break;
      case 'v':
        printf("Выбран %c\n", opt);
      break;
      case 'c':
        printf("Выбран %c\n", opt);
      break;
      case 'l':
        printf("Выбран %c\n", opt);
      break;
      case 'n':
        printf("Выбран %c\n", opt);
      break;
      case '?':
      printf("Неизвестный флаг: %c\n", opt);
      break;
    }
  }

  for (int i = optind; i < argc; i++){
    FILE *file = fopen(argv[i], "r");
    if(file == NULL){
      printf("Файла с именем %s не существует\n",argv[i]);
    }else{
      fclose(file);
      printf("argument: %s\n", argv[i]);
    }
  }
    
  exit(0);
}



