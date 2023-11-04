#include "fileSize.h"

void baseCat(char *fileName){
  FILE *file = fopen(fileName,"rt");
  if(file != NULL){
    int fileRows = rowCount(fileName).rows;
    int size = rowCount(fileName).size;
    //* Выделяю память исходя из кол. всех символов в файле
    char *forMemory = (char *)malloc(size * sizeof(char));

    for (; fileRows > 0; fileRows--){
        //* мы сохраняем строку в forMemory чтобы далее вывести ее 
        fgets(forMemory,size,file);
        printf("%s",forMemory);
      }
    free(forMemory);
    fclose(file);
  }
}