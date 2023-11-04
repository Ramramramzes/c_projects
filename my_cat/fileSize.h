//* Создаем структуру для вывода функции rowCount, будет выплевывать объект
typedef struct{
  int rows;
  int size;
}FileStats;

//* Функция будет возвращать объект
FileStats rowCount(char *fileName){
  FILE *file = fopen(fileName,"rt");
  char ch;
  FileStats stats = {1,0};
  //* Cчитаем все символы кроме \n и все строки
  while((ch = fgetc(file)) != EOF){
    if(ch != '\n'){
      stats.size++;
    }
    if(ch == '\n'){
      stats.rows++;
    }
  }

  fclose(file);
  return stats;
}