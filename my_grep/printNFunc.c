#include "myHeader.h"

void myMainPrint(Flags flags,int strNumber,char* str,char* filename,int fileArrCount){
  if(fileArrCount > 1 && !flags.h){
    printf("%s:",filename);
  }
  if(flags.n){
    printf("%d:",strNumber);
  }
  printf("%s",str);
}