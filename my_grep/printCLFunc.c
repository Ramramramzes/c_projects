#include "myHeader.h"

void myCLprint(Flags flags, int strCounter, char* filename, int fileArrCount) {
  if (flags.c && flags.l) {
    if (fileArrCount > 1) {
      printf("%s:1\n", filename);
      printf("%s\n", filename);
    } else if(fileArrCount == 1) {
      printf("1\n");
      printf("%s\n", filename);
    }
  } else {
    if (flags.c) {
      if (fileArrCount > 1) {
        printf("%s:%d\n", filename, strCounter);
      } else {
        printf("%d\n", strCounter);
      }
    }
    if (flags.l) {
      if (fileArrCount > 1) {
        printf("%s:\n", filename);
      }else{
        printf("%s\n", filename);
      }
    }
  }
}