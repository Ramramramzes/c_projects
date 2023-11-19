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

    while (fgets(line, sizeof(line) ,file)){
      for (int j = 0; j < patternsLen; j++){
        regcomp(&regex, patterns[j], regexFlags);
        if(regexec(&regex, line, 1, pmatch, 0) == 0){
          printf("%s", line);
        }
        regfree(&regex);
      }
    }
    fclose(file);
  }
}


#endif