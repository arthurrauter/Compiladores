#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"
#include "y.tab.c"

extern int running;
extern FILE* yyin;
void initMe(void);

int main(int argc, char** argv)
  {
  FILE *gold = 0;
  
  if (argc < 3)
    {
    printf("call: ./etapa1 input.txt output.txt \n");
    exit(1);
    }
  if (0==(yyin = fopen(argv[1],"r")))
    {
    printf("Esse tal de arquivo %s não tem como abrir... \n",argv[1]);
    exit(1);
    }
  if (0==(gold = fopen(argv[2],"r")))
    {
    printf("Esse tal de arquivo %s não tem como abrir... \n",argv[2]);
    exit(1);
    }
  initMe();
  yyparse(); 
  return 0;
  
  }
