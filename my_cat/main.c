#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "baseCat.h"
#include "flagChecker.h"



int main(int argc, char *argv[]){
  //! argv[0] - массив содержащий ./test text.txt (нужен для флагов)
  // printf("%s\n",argv[0]);
  //! argv - кол-во значений ./test text.txt (2) с флагами (3)
  // printf("%d - вывод заглушка чтобы код не крашился\n",argc);

  Flags flags = flagChecker(argc,argv);
  int flagsArr[] = {flags.b,flags.e,flags.n,flags.s,flags.t,flags.err};

  for(int i = 0; i <= 5; i++){
    printf("%d",flagsArr[i]);
  }
  





  //! Вывод cat всех файлов
  // for (int i = 1; i < argc; i++){
  //   baseCat(argv[i]);
  // }
  
  

  return 0;
}

