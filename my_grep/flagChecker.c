#include "myHeader.h"

//* Создаем массив символов флагов
char *wordsArr[] = {"e", "i", "v", "c", "l", "n", "h", "s", "f", "o"};

//* Создаем функцию которая на выходе выдаст структуру с результатами флагов
Flags flagChecker(int argc, char *argv[]) {
  Flags flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false};

  //* Обработка флагов 🇷🇺
  for (int i = 1; i < argc; i++) {
    if (strstr(argv[i], "e") != NULL && argv[i][strlen(argv[i]) - 1] != 'e') {
      continue;
    }
    for (int j = 1; j < (int)strlen(argv[i]); j++) {
      if (argv[i][0] == '-') {
        switch (argv[i][j]) {
          case 'e':
            flags.e = 1;
            break;
          case 'i':
            flags.i = 1;
            break;
          case 'v':
            flags.v = 1;
            break;
          case 'c':
            flags.c = 1;
            break;
          case 'l':
            flags.l = 1;
            break;
          case 'n':
            flags.n = 1;
            break;
          case 'h':
            flags.h = 1;
            break;
          case 's':
            flags.s = 1;
            break;
          case 'f':
            flags.f = 1;
            break;
          case 'o':
            flags.o = 1;
            break;
          case '?':
            break;
        }
      }
    }
  }

  if (flags.e == 0 && flags.i == 0 && flags.v == 0 && flags.c == 0 &&
      flags.l == 0 && flags.n == 0 && flags.h == 0 && flags.s == 0 &&
      flags.f == 0 && flags.o == 0) {
    flags.allFlags = false;
  } else {
    flags.allFlags = true;
  }

  return flags;
}
