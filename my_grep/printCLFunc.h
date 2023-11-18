#ifndef PRINTCL_H
#define PRINTCL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void myCLprint(Flags flags,int strCounter,char* filename,int fileArrCount){
  if(flags.c && flags.l){
    printf("%s:1\n",filename);
    printf("%s\n",filename);
  }else{
    if(flags.c){
      if(fileArrCount > 1){
        printf("%s:%d\n",filename,strCounter);
      }else{
        printf("%d\n",strCounter);
      }
    }
    if(flags.l){
      printf("%s\n",filename);
    }
  }
}

#endif