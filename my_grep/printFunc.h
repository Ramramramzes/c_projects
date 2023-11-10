//* добавляем PRINTFUNC_H в предпроцессор 🛠️
#ifndef PRINTFUNC_H
#define PRINTFUNC_H

void printFunc(int argc, char *argv[],int maxFileString,char *searchWord) {
  for (int i = 2; i < argc; i++){
    FILE *file = fopen(argv[i],"r");
    if(file == NULL){
      printf("Файла %s  не существует",argv[i]);
    }else{
      char line[maxFileString];
      while(fgets(line,sizeof(line),file) != NULL){
        if(strstr(line,searchWord)){
          printf("%s",line);
        }
      }
      //todo тут добавить проверки if flag.e == .... 



    }
  }
  
}

#endif