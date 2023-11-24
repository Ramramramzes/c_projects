#include "myHeader.h"

void grepPrint(Flags flags, int argc, char *argv[], char *patterns[],
               int patternsLen, char *files[], int filesLen) {
  for (int i = 0; i < filesLen; i++) {
    FILE *file = fopen(files[i], "r");
    if (file == NULL) {
      perror(files[i]);
      continue;
    }
    regex_t regex;
    regmatch_t pmatch[1];
    int maxFileString = findStrSize(argc, argv);
    int regexFlags = flags.i ? REG_ICASE : 0;
    char line[maxFileString];
    int flagV = 0;
    int strNumber = 0;
    int strCounter = 0;

    while (fgets(line, sizeof(line), file)) {
      strNumber++;
      flagV = 0;
      char prevLine[maxFileString];
      strcpy(prevLine, "");
      for (int j = 0; j < patternsLen; j++) {
        regcomp(&regex, patterns[j], regexFlags);
        if (!flags.v) {
          if (regexec(&regex, line, 1, pmatch, 0) == 0) {
            strCounter++;
            if (!flags.c && !flags.l) {
              myMainPrint(flags, strNumber, line, files[i], filesLen);
            }
          }
        } else {
          if (regexec(&regex, line, 1, pmatch, 0) != 0) {
            flagV++;
          }
        }
        strcpy(prevLine, line);
        regfree(&regex);
      }

      if (flagV != patternsLen - 1 && flags.v && flagV != 0) {
        strCounter++;
        if (!flags.c && !flags.l) {
          myMainPrint(flags, strNumber, line, files[i], filesLen);
        }
      }
    }
    if (flags.c || flags.l) {
      myCLprint(flags, strCounter, files[i], filesLen);
    }

    fclose(file);
  }
}