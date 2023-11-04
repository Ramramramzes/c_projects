#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "baseCat.h"


int main(int argc, char *argv[]){
  //! argv[0] - массив содержащий ./test text.txt (нужен для флагов)
  // printf("%s\n",argv[0]);
  //! argv - кол-во значений ./test text.txt (2) с флагами (3)
  // printf("%d - вывод заглушка чтобы код не крашился\n",argc);

//todo Добавить в отдельную функцию чекфлагс для обработки    (' - ' это символ " - " это строка)
  for(int i = 1; i < argc; i++){
    if(argv[i][0] == '-'){
      printf("%s", argv[i]);
    }
  }




  //! Вывод cat всех файлов
  // for (int i = 1; i < argc; i++){
  //   baseCat(argv[i]);
  // }
  
  

  return 0;
}

