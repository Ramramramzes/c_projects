#ifndef FLAG_CHECKER_H
#define FLAG_CHECKER_H

typedef struct{
  int b;
  int e;
  int n;
  int s;
  int t;
  int err;
} Flags;

char *wordsArr[] = {"b","e","n","s","t"};


Flags flagChecker(int argc,char *argv[]){
  Flags flags = {0,0,0,0,0,0};
  // char arr[1024];
  for(int i = 1; i < argc; i++){
    if(strlen(argv[i]) < 2){
      flags.err = 1;
      flags.b = 0;
      flags.e = 0;
      flags.n = 0;
      flags.s = 0;
      flags.t = 0;
      printf("Недопустимые значения флага");
      break;
    }   
    if(argv[i][0] == '-' && strlen(argv[i]) == 2){
      switch (argv[i][1]){
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
      default:
        flags.err = 1;
        flags.b = 0;
        flags.e = 0;
        flags.n = 0;
        flags.s = 0;
        flags.t = 0;
        printf("Недопустимые значения флага");
        break;
      }
    }
    if(argv[i][0] == '-' && strlen(argv[i]) > 2){
      for (int j = 1; j < (int)strlen(argv[i]); j++){
        if(flags.err == 0){
          switch (argv[i][j]){
          case 'b':
            flags.b = 1;
            continue;
          case 'e':
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
          default:
            flags.err = 1;
            flags.b = 0;
            flags.e = 0;
            flags.n = 0;
            flags.s = 0;
            flags.t = 0;
            printf("Недопустимые значения флага");
            break;
          }
        }
      }
    }

  }
  return flags;
}

#endif