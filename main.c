#include "tokens.h"
#include <stdio.h>
extern int running;
int main (int argc, char **argv)
  {
  int token = 0;
 
  if (argc < 2)
    {
    fprintf(stderr,"Please, call: ./a.out filename\n");
    exit(1);
    }
    
  yyin = fopen(argv[1],"r");
  if (yyin ==0)
    {
    fprintf(stderr,"Cannot open file \"%s\"\n",argv[1]);
    exit (2);
    }
 
  while(running)
    {
    token = yylex();
    if (! running) 
      break;
    switch (token)
      {
    case TK_IDENTIFIER: fprintf(stderr,"ident %s at line %d\n",yytext,getLineNumber()); break;
    case LIT_INTEGER: fprintf(stderr,"inteiro valor %d at line %d\n",atoi(yytext),getLineNumber());  break;
    case KW_INT : fprintf(stderr,"INT at line %d\n",getLineNumber());  break;
    case KW_FLOAT : fprintf(stderr,"FLOAT at line %d\n",getLineNumber());  break;
    
    case LIT_CHAR : fprintf(stderr,"char %s at line %d\n", yytext, getLineNumber());  break;
    case LIT_STRING : fprintf(stderr,"string %s at line %d\n", yytext, getLineNumber());  break;
    case LIT_FLOAT : fprintf(stderr,"lit float %s at line %d\n", yytext, getLineNumber());  break;
    default: fprintf(stderr,"Nao sei... %d at line %d\n",token, getLineNumber());
      } 
    }
  }
