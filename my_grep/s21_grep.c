#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "regex.h"

#include "flagChecker.h"
#include "print.h"
#include "printNFunc.h"
#include "printCLFunc.h"

int main(int argc, char *argv[]) {
  Flags flags = flagChecker(argc,argv);
  char ** patterns = (char **)calloc(argc ,sizeof(char*));
  char ** allFiles = (char **)calloc(argc ,sizeof(char*));
  int patternsLen = 0;
  int filesLen = 0;

  for (int i = 1; i < argc; i++){
    int prevLen = i > 1 ? (int)strlen(argv[i - 1]) : 0;
    if(flags.e && argv[i][0] != '-' && argv[i-1][prevLen -1] == 'e'){
      patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
      strcpy(patterns[patternsLen], argv[i]);
      patternsLen++;
    }
    if(!flags.e && argv[i][0] != '-'){
      FILE *file = fopen(argv[i], "r");
      if(!file){
        patterns[patternsLen] = (char *)malloc((int)strlen(argv[i]) + 1);
        strcpy(patterns[patternsLen], argv[i]);
        patternsLen++;
      }

    }

    if(argv[i][0] != '-'){
      FILE *file = fopen(argv[i], "r");
      if(file){
        allFiles[filesLen] = (char *)malloc((int)strlen(argv[i]) + 1);
        strcpy(allFiles[filesLen], argv[i]);
        filesLen++;
      }
    }
    
  }

  for (int i = 0; i < patternsLen; i++){
    printf("Pat - %s\n",patterns[i]);
  }
  for (int i = 0; i < filesLen; i++){
    printf("File - %s\n",allFiles[i]);
  }

  printf("%d",flags.e);
}




