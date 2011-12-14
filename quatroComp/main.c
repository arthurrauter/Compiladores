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
    printf("call: ./etapa4 input.txt\n");
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
  printf("yyparse return value: %d\n", yyparse_out);
  FILE* fileAST=NULL;
  //ast_print_tree(root);
  ast_to_program(root, fileAST);
  return 0;
}
