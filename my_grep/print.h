//* добавляем PRINT_H в предпроцессор 🛠️
#ifndef PRINT_H
#define PRINT_H
#include "printNFunc.h"

int basePrint(Flags flags,char *searchWord,char*filesFromCom[],int fromComCount,int maxStrSize,bool noflag){
  int strCount = 0;
  int strNumber = 0;
  if (searchWord != NULL && filesFromCom != NULL) {
    char line[maxStrSize];
    for (int k = 0; k < fromComCount; k++){
      FILE *file = fopen(filesFromCom[k],"r");
      while (fgets(line,maxStrSize,file)){
        strNumber++;
        if(strstr(line, searchWord) != NULL){
          strCount += 1;
          if(noflag){
            printf("%s", line);
          } else {
            myMainPrint(flags,strNumber,line,filesFromCom[k],fromComCount);
          }
        }
      }
      fclose(file);
    }
  }

  return strCount;
}



#endif