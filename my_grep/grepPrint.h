//* добавляем GREPPRINT_H в предпроцессор 🛠️
#ifndef GREPPRINT_H
#define GREPPRINT_H

#include "findMaxMy.h"
#include "regex.h"

void grepPrint(Flags flags,int argc, char *argv[],char* patterns[],int patternsLen,char *files[],int filesLen){
  for (int i = 0; i < filesLen; i++){
    FILE *file = fopen(files[i],"r");
      if (file == NULL) {
        //! добавить ошибку -s флага 
        perror(files[i]);
        continue;
      }

    regex_t regex;
    regmatch_t pmatch[1];
    int maxFileString = findStrSize(argc,argv);
    int regexFlags = flags.i ? REG_ICASE : 0;
    char line[maxFileString];
    bool wasPrinted = false;
    int flagV = 0;

    //todo int strCounter = 0;
    int strNumber = 0;
    while (fgets(line, sizeof(line) ,file)){
      strNumber++;
      flagV = 0;
      char prevLine[maxFileString];

      for (int j = 0; j < patternsLen; j++){
        regcomp(&regex, patterns[j], regexFlags);

        if(!flags.v){
          if(regexec(&regex, line, 1, pmatch, 0) == 0){
            if(wasPrinted && strcmp(line, prevLine) == 0){
              continue;
            }else{
              myMainPrint(flags,strNumber,line,files[i],filesLen);
              wasPrinted = true;
            }
          }
        }else{
          if(regexec(&regex, line, 1, pmatch, 0) != 0){
            flagV++;
          }
        }
        strcpy(prevLine, line);
        regfree(&regex);
      }

      if(flagV != patternsLen-1 && flags.v && flagV != 0){
        myMainPrint(flags,strNumber,line,files[i],filesLen);
      }

    }

    fclose(file);
  }


  printf("\n");

}


#endif