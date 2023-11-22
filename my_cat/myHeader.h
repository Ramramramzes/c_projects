//* Подключение предпроцессора myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* Создаем структуру с переменными флагов 0 - 1
typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int err;
} Flags;

Flags flagChecker(int argc, char *argv[]);
void printFile(Flags flagsObj, int argc, char *argv[]);
void simplePrint(char *argv[]);
#endif
