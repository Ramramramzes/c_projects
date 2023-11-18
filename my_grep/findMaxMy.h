#ifndef FINDMAX_H
#define FINDMAX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findStrSize(int argc,char *argv[]){
  int maxLength = 0;
  int maxCounter = 0;
    for (int i = 1; i < argc; i++){
      FILE *file = fopen(argv[i], "r");
      char ch;
      if(file){
        while((ch = fgetc(file)) != EOF){
        if(ch != '\n'){
          maxCounter++;
        }
        if(ch == '\n'){
          maxCounter = 0;
        }
        if(maxLength < maxCounter){
          maxLength = maxCounter;
        }
      }
    }
  }

  return maxLength + 10;

}

#endif