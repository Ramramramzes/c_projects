#include "myHeader.h"

//* Создаем массив символов флагов
char *wordsArr[] = {"b", "e", "n", "s", "t", "v"};

//* Создаем функцию которая на выходе выдаст структуру с результатами флагов
Flags flagChecker(int argc, char *argv[]) {
  Flags flags = {0, 0, 0, 0, 0, 0, 0};

  for (int i = 1; i < argc; i++) {
    //* Проверка на верное введение флага, если 1 символ то err
    if (strlen(argv[i]) < 2) {
      flags.err = 1;
      flags.b = 0;
      flags.e = 0;
      flags.n = 0;
      flags.s = 0;
      flags.t = 0;
      flags.v = 0;
      printf("Недопустимые значения флага");
      break;
    }
    //* Флаг начинается с - и имеет размер 2 символа то есть одиночный флаг типа
    //"-b"
    if (argv[i][0] == '-' && strlen(argv[i]) == 2) {
      //* При совпадении добавляем в структуру 1
      switch (argv[i][1]) {
        case 'E':
          flags.e = 1;
          break;
        case 'T':
          flags.t = 1;
          break;
        case 'b':
          flags.b = 1;
          break;
        case 'e':
          flags.e = 1;
          break;
        case 'n':
          flags.n = 1;
          break;
        case 's':
          flags.s = 1;
          break;
        case 't':
          flags.t = 1;
          break;
        case 'v':
          flags.v = 1;
          break;
        default:
          flags.err = 1;
          flags.b = 0;
          flags.e = 0;
          flags.n = 0;
          flags.s = 0;
          flags.t = 0;
          flags.v = 0;
          printf("Недопустимые значения флага");
          break;
      }
    }
    //* Флаг начинается с - и имеет размер больше 2 символов
    if (argv[i][0] == '-' && strlen(argv[i]) > 2) {
      //* Сначала проверим GNU команды
      if (strcmp(argv[i], "--number-nonblank") == 0) {
        flags.b = 1;
        continue;
      }
      if (strcmp(argv[i], "--number") == 0) {
        flags.n = 1;
        continue;
      }
      if (strcmp(argv[i], "--squeeze-blank") == 0) {
        flags.s = 1;
        continue;
      }
      //* Затем проверяем парные флаги типа "-bsen"
      for (int j = 1; j < (int)strlen(argv[i]); j++) {
        if (flags.err == 0) {
          switch (argv[i][j]) {
            case 'b':
              flags.b = 1;
              continue;
            case 'e':
              flags.e = 1;
              continue;
            case 'E':
              flags.e = 1;
              continue;
            case 'n':
              flags.n = 1;
              continue;
            case 's':
              flags.s = 1;
              continue;
            case 't':
              flags.t = 1;
              continue;
            case 'T':
              flags.t = 1;
              continue;
            case 'v':
              flags.v = 1;
              continue;
            default:
              flags.err = 1;
              flags.b = 0;
              flags.e = 0;
              flags.n = 0;
              flags.s = 0;
              flags.t = 0;
              flags.v = 0;
              printf("Недопустимые значения флага");
              break;
          }
        }
      }
    }
  }
  return flags;
}