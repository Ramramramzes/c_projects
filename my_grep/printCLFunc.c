#include "myHeader.h"

void myCLprint(Flags flags,int strCounter,char* filename,int fileArrCount){
  if(flags.c && flags.l){
    if(fileArrCount > 1){
      printf("%s:1",filename);
      printf("%s\n",filename);
    }else{
      printf("1\n");
      printf("%s\n",filename);
    }
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