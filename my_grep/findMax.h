#ifndef FINDMAX_H
#define FINDMAX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findStrSize(int argc,char *argv[]){
  int maxLength = 0;
  int maxCounter = 0;
    for (int i = 0; i < argc; i++){
      FILE *file = fopen(argv[i], "r");
      char ch;
    while((ch = fgetc(file)) != EOF){
      if(ch != '\n'){
        maxCounter++;
        if(maxLength < maxCounter){
          maxLength = maxCounter;
        }
      }else if(ch == '\n'){
        maxCounter = 0;
      }
    }
  }

  return maxLength;
}

#endif