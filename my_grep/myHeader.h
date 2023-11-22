//* Подключение предпроцессора myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "regex.h"

//* Создаем структуру с переменными флагов 0 - 1
typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  bool allFlags;
} Flags;

int findStrSize(int argc, char* argv[]);
Flags flagChecker(int argc, char* argv[]);
void grepPrint(Flags flags, int argc, char* argv[], char* patterns[],
               int patternsLen, char* files[], int filesLen);
void myCLprint(Flags flags, int strCounter, char* filename, int fileArrCount);
void myMainPrint(Flags flags, int strNumber, char* str, char* filename,
                 int fileArrCount);

#endif
