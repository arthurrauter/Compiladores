#include <stdio.h>
#include <stdlib.h>
#include "astree.h"
#include "hash.h"
#include "lex.yy.c"
#include "y.tab.c"


extern int running;
extern FILE* yyin;
void initMe(void);

int main(int argc, char** argv)
{

  if (argc < 2)
    {
    printf("call: ./etapa3 input.txt\n");
    exit(1);
    }
  if (0==(yyin = fopen(argv[1],"r")))
    {
    printf("File %s couldnt be opened \n",argv[1]);
    exit(1);
    }
	initMe();
  int yyparse_out;
  yyparse_out = yyparse();
  printf("\nyyparse return value: %d\n", yyparse_out);
  FILE* fileAST=NULL;
  if(root == NULL)
  	printf("\n\n\n\n\nroot null\n\n\n\n\n\n");
  ast_to_program(root, fileAST);
  return 0;
}
