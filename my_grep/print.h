//* добавляем PRINT_H в предпроцессор 🛠️
#ifndef PRINT_H
#define PRINT_H

void basePrint(char *searchWord,char*filesFromCom[],int fromComCount,int maxStrSize){
  if (searchWord != NULL && filesFromCom != NULL) {
    char line[maxStrSize];
    for (int k = 0; k < fromComCount; k++){
      FILE *file = fopen(filesFromCom[k],"r");
      while (fgets(line,maxStrSize,file)){
        if(strstr(line, searchWord) != NULL){
          printf("%s",line);
        }
      }
      fclose(file);
    }
  }
}



#endif