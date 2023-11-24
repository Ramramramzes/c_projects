#include "myHeader.h"

int peekc(FILE *file) {
  int nextCh = getc(file);
  ungetc(nextCh, file);
  return nextCh;
}

//* Фунция добавялет символы в stdout
void printFile(Flags flagsObj, int argc, char *argv[]) {
  //* Пропускаем ./a.out и -флаги начинаем с 2
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      FILE *file = fopen(argv[i], "r");
      if (file == NULL) {
        printf("Файл не найден");
        break;
      }
      int ch;
      int nextCh;
      int circles = 0;
      bool newRow = true;
      bool skip = false;
      int lineCount = 1;
      //* Поштучно сравниваем каждый символ, добавим проверку каждого флага в
      for (ch = getc(file); ch != EOF; ch = getc(file)) {
        nextCh = peekc(file);
        
        //* Обработка флагов 🇷🇺
        /*🚩*/ if (flagsObj.s == 1) {
          //* Использую переменную circles для вычисления момента где будут идти
          // 3 \n подряд чтобы схлопнуть строку
          if (ch == '\n' && newRow) {
            circles++;
            if (circles >= 2) {
              continue;
            }
          } else if (ch == '\n' && !newRow) {
            circles = 0;
          }
        }
        /*🚩*/ if (flagsObj.b == 1) {
          //* Циклами добавляю пробелы при использовании -b в cat выводится с
          // пробелами
          if (newRow && ch != '\n') {
            fprintf(stdout, "%6d	",
                    lineCount);  //! 🚨 После %d идет → TAB
            lineCount++;
          } else if (newRow && flagsObj.e) {
            printf("      	");  //! 🚨 После %d идет → TAB
          }

          if(nextCh == '\n' && !skip && !flagsObj.e){
            if(flagsObj.v || flagsObj.t){
              fputc('^', stdout);
              fputc('M', stdout);
              skip = true;
            }
          }
        }
        /*🚩*/ if (flagsObj.n == 1 && flagsObj.b != 1) {
          //* Циклами добавляю пробелы при использовании -b в cat выводится с
          // пробелами
          if (newRow) {
            fprintf(stdout, "%6d	",
                    lineCount);  //! 🚨 После %d идет → TAB
            lineCount++;
          }
          if(nextCh == '\n' && !skip && !flagsObj.e){
            if(flagsObj.v || flagsObj.t){
              fputc('^', stdout);
              fputc('M', stdout);
              skip = true;
            }
          }
        }
        /*🚩*/ if (flagsObj.t == 1) {
          if (ch == '	') {
            fputc('^', stdout);
            fputc('I', stdout);
            //* скипаем вывод
            skip = true;
          }
          if(nextCh == '\n' && !skip && !flagsObj.e){
            if(flagsObj.v || flagsObj.t){
              fputc('^', stdout);
              fputc('M', stdout);
              skip = true;
            }
          }
        }
        /*🚩*/ if (flagsObj.e == 1) {
          if(nextCh == '\n'){
            fputc('^', stdout);
            fputc('M', stdout);
            fputc('$', stdout);
            skip = true;
          }
        }
        //* Каждую итерацию проверяем newRow является ли новой строкой
        newRow = (ch == '\n');
        //* Каждую итерацию выводим в символ в stdout
        if(!skip){
          fputc(ch, stdout);
        }
        skip = false;
      }
    }
  }
}
