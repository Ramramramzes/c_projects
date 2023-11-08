//* добавляем FIND_STRSIZE в предпроцессор 🛠️
#ifndef FIND_STRSIZE
#define FIND_STRSIZE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findStrSize(int argc,char *argv[],int needNum){
  int maxLength = 0;
  int maxCounter = 0;
  for (int i = needNum+1; i < argc; i++){
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