#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//todo Удалить и не выебываться 😂
// #include "fileSize.h"
#include "flagChecker.h"
#include "printFile.h"




int main(int argc, char *argv[]){
  //! argv[0] - массив содержащий ./test text.txt (нужен для флагов)   🚨
  // printf("%s\n",argv[0]);
  //! argv - кол-во значений ./test text.txt (2) с флагами (3)   🚨
  // printf("%d - вывод заглушка чтобы код не крашился\n",argc);
  Flags flags = flagChecker(argc,argv);


    //* flagChecker(argc,argv) используем без flags 
    printFile(flags,argc,argv);

  
  

  return 0;
}

