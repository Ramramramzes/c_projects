//* Подключение предпроцессора myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <regex.h>

typedef struct {
  int e;
  int n;
  int i;
  int h;
  int v;
  int s;
  int c;
  int f;
  int l;
  FILE *flagFile;
}Flags;


Flags flagsChecker(int argc, char* argv[], char* patterns[]);
void mainPrint(int i, int argc, char* argv[], Flags flags, char* patterns[]);
int eFunc(char* line, regex_t regPat, char* match, Flags flags);
void fFunc(char* patterns[],Flags flags);
void hasNoEF(char* argv[], char* patterns[], Flags flags);

#endif
