#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//todo Удалить и не выебываться 😂
#include "simplePrint.h"
#include "flagChecker.h"
#include "printFile.h"




int main(int argc, char *argv[]){
  //! argv[0] - массив содержащий ./test text.txt (нужен для флагов)   🚨
  // printf("%s\n",argv[0]);
  //! argv - кол-во значений ./test text.txt (2) с флагами (3)   🚨
  // printf("%d - вывод заглушка чтобы код не крашился\n",argc);
  Flags flags = flagChecker(argc,argv);
  //! ДОБАВИТЬ ОБРАБОТКУ ОШИБОК БАХНУТЬ BREAK 🚨🚨🚨🚨🚨

/*🏳️*/if(
  flags.s == 0 &&
  flags.b == 0 &&
  flags.n == 0 &&
  flags.e == 0 &&
  flags.t == 0 &&
  flags.err == 0 
){
  simplePrint(argv);
}


    printFile(flags,argc,argv);

  
  

  return 0;
}

