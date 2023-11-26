#include "myHeader.h"

int patternLen = 1000;  //? Длина шаблона
int patternCountMax = 10;  //? Максимальное количество шаблонов
int patternCounter = 0;  //? Счетчик шаблонов
int outputFlag = 0;  //? Флаг вывода

int main(int argc, char* argv[]) {
  char* patterns[patternCountMax];
  Flags flags = flagsChecker(argc, argv, patterns);

  //* Вычисление начального индекса для анализа аргументов командной строки
  int i = (patternCounter == 0 && !flags.f) ? optind + 1 : optind;

  //* Выбор соответствующей функции в зависимости от наличия флага -f
  flags.f ? fFunc(patterns, flags) : hasNoEF(argv, patterns, flags);
  
  flags.e = 1;
  mainPrint(i, argc, argv, flags, patterns); 
  

  for (int i = 0; i < patternCounter; i++) {
    free(patterns[i]);
    patterns[i] = NULL;
  }

  if (flags.f) fclose(flags.flagFile);
  if (outputFlag) printf("\n");
  return 0;
}

//* Анализатор флагов
Flags flagsChecker(int argc, char* argv[], char* patterns[]) {
  Flags flags = {0};
  int ch;
  while ((ch = getopt_long(argc, argv, "e:nihvosclf:", NULL, NULL)) != -1) {
    switch (ch) {
      case 'e':
        flags.e = 1;
        char* pattern = malloc(patternLen * sizeof(char));  // Выделение памяти для хранения регулярного выражения после -e
        memcpy(pattern, optarg, patternLen * sizeof(char));  // Копирование строки, следующей за -e (наш шаблон), в выделенную память
        patterns[patternCounter] = pattern;
        patternCounter++;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'i':
        flags.i = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'f':
        flags.f = 1;
        flags.flagFile = fopen(optarg, "r");
        if (flags.flagFile == NULL) {
          if (outputFlag) printf("\n");
          outputFlag = 1;
          fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
          exit(1);
        }
        break;
      case 'l':
        flags.l = 1;
        break;
      case '?':
        if (outputFlag) printf("\n");
        fprintf(stderr, "Передана неизвестная опция!\n");
        outputFlag = 1;
        exit(1);
    }
  }
  return flags;
}

//* Функция вывода результатов
void mainPrint(int i, int argc, char* argv[], Flags flags, char* patterns[]) { 
  int matchLine = 0;
  int matchCount = 0;
  int filesCounter = argc - i;
  
  char* matched = (char*)malloc(patternLen * sizeof(char));  

  for (; i < argc; i++) {
    int copyFiles = 0;  
    FILE* file = fopen(argv[i], "r");
    
    //* Обработка случая отсутствия файла и флага -s
    if (file == NULL && flags.s) {
      continue;
    } else if (file == NULL) {
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
      continue;
    }
    
    int lineNum = 1;
    char line[patternLen];

    //* Чтение строк из файла
    while (fgets(line, sizeof(line), file) != NULL) {
      matchLine = 0;
      int len = strlen(line);

      //* Удаление символа новой строки, если он есть
      if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';

      regex_t regex;

      for (int j = 0; j < patternCounter; j++) {
        if (flags.i) {
          if (regcomp(&regex, patterns[j], REG_ICASE) != 0) {
            fprintf(stderr, "Ошибка компиляции");
            exit(1);
          }
        } else {
          if (regcomp(&regex, patterns[j], 0) != 0) {
            fprintf(stderr, "Ошибка компиляции");
            exit(1);
          }
        }

        if (flags.e) {
          if (eFunc(line, regex, matched, flags)) matchLine++;
        }
      }

      //* Проверка условий для вывода строки vcn
      if ((flags.v && matchLine == patternCounter) ||
          (!flags.v && matchLine > 0)) {
        copyFiles = 1;

        if (!flags.c && !flags.l) {
          if (flags.n) {
            if (outputFlag) printf("\n");
            outputFlag = 1;
            (filesCounter == 1 || flags.h)
                ? printf("%d:%s", lineNum, line)
                : printf("%s:%d:%s", argv[i], lineNum, line);
          } else {
            if (outputFlag) printf("\n");
            outputFlag = 1;
            (filesCounter == 1 || flags.h)
                ? printf("%s", line)
                : printf("%s:%s", argv[i], line);
          }
        }
        flags.l == 1 ? matchCount = 1 : matchCount++;
      }
      lineNum++;
    }

    //* Вывод результатов подсчета или имени файла (в случае флага -l)
    if (flags.c) {
      if (outputFlag) printf("\n");
      outputFlag = 1;
      (filesCounter == 1 || flags.h)
          ? printf("%d", matchCount)
          : printf("%s:%d", argv[i], matchCount);
    }

    if (flags.l && (copyFiles == 1)) {
      if (outputFlag) printf("\n");
      outputFlag = 1;
      printf("%s", argv[i]);
    }
    matchCount = 0;
    fclose(file);
  }
  free(matched);
}

//* Функция проверки соответствия строки регулярному выражению
int eFunc(char* line, regex_t regPat, char* matched, Flags flags){
  regmatch_t match;
  if (regexec(&regPat, line, 1, &match, 0) == 0) {
    if (!flags.v) {
      int start = match.rm_so;
      int end = match.rm_eo;
      strncpy(matched, line + start, end - start);
      matched[end - start] = '\0';
    }
    regfree(&regPat);
    return !flags.v;
  }
  regfree(&regPat);
  return flags.v;
}

//* Функция чтения шаблонов из файла
void fFunc(char* patterns[], Flags flags) {
  char line[patternLen];
  while (fgets(line, sizeof(line), flags.flagFile) != NULL) {
    int len = strlen(line);

    //* Удаление символа новой строки, если он есть
    if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';

    //* Выделение памяти для хранения шаблона и копирование его из файла
    patterns[patternCounter] = malloc(patternLen * sizeof(char));
    memcpy(patterns[patternCounter], line, patternLen * sizeof(char));
    patternCounter++;
  }
}

//* Функция обработки случая отсутствия флагов -e и -f
void hasNoEF(char* argv[], char* patterns[], Flags flags) { 
  if (!flags.e && !flags.f) {
    char* pattern = malloc(patternLen * sizeof(char));
    memcpy(pattern, argv[optind], patternLen * sizeof(char));
    patterns[patternCounter] = pattern;
    patternCounter++;
  }
}
