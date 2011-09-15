#include <stdio.h>
#include <stdlib.h>

extern int running;
extern FILE* yyin;
void initMe(void);

int main(int argc, char** argv)
  {
  FILE *gold = 0;
  int token = 0;
  int answare = 0;
  int nota = 0;
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
  while (running)
    {
    token = yylex();
    if (!running)
      break;
    fscanf(gold,"%d",&answare);
    if (token == answare)
      {
      printf("ok ");
      ++nota;
      }
    else
      printf("ERROR ");
    }
  printf("\nNOTA %d\n",nota);  
  }
