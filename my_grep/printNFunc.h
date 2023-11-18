#ifndef PRINTMY_H
#define PRINTMY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void myMainPrint(Flags flags,int strNumber,char* str,char* filename,int fileArrCount){
  if(fileArrCount > 1 && !flags.h){
    printf("%s:",filename);
  }
  if(flags.n){
    printf("%d:",strNumber);
  }
  printf("%s",str);
}

#endif