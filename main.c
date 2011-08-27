#include "tokens.h"

#include <stdio.h>

void initMe(void);

extern int running;
int main (int argc, char **argv)
  {
  int token = 0;
	initMe();

  if (argc < 2)
    {
    fprintf(stderr,"Please, call: ./a.out filename\n");
    return;
    }
   
  yyin = fopen(argv[1],"r");
  if (yyin ==0)
    {
    fprintf(stderr,"Cannot open file \"%s\"\n",argv[1]);
    return;
    }

  while(running)
    {
		token = yylex();
		//printf("running");   

   
	if (! running) 
    break;
  switch (token)
    {
  case TK_IDENTIFIER: fprintf(stderr,"TK_IDENTIFIER: %s " /*[%d] "*/,yytext,getLineNumber()); break;
  case LIT_INTEGER: fprintf(stderr,"LIT_INT: %d " /*[%d] "*/,atoi(yytext),getLineNumber());  break;
  case KW_INT : fprintf(stderr,"KW_INT " /*[%d] "*/,getLineNumber());  break;
  case KW_FLOAT : fprintf(stderr,"KW_FLOAT " /*[%d] "*/,getLineNumber());  break;
  case LIT_FALSE : fprintf(stderr,"LIT_FALSE " /*[%d] "*/, getLineNumber());break;
  case LIT_CHAR : fprintf(stderr,"LIT_CHAR: %s " /*[%d] "*/, yytext, getLineNumber());  break;
  case LIT_STRING : fprintf(stderr,"LIT_STRING: %s " /*[%d] "*/, yytext, getLineNumber());  break;
  case LIT_FLOAT : fprintf(stderr,"LIT_FLOAT: %s " /*[%d] "*/, yytext, getLineNumber());  break;
  case 59: fprintf(stderr,"SEMICOLON [%d]\n", getLineNumber()); break;
  case 43: fprintf(stderr,"PLUS " /*[%d] "*/, getLineNumber()); break;
  case 61: fprintf(stderr,"EQUALS " /*[%d] "*/, getLineNumber()); break;
  case LIT_TRUE : fprintf(stderr,"LIT_TRUE " /*[%d] "*/, getLineNumber()); break;
  case KW_CHAR : fprintf(stderr,"KW_CHAR " /*[%d] "*/,getLineNumber()); break;
	default: fprintf(stderr,"???: %d " /*[%d] "*/,token, getLineNumber());
    } 
  }
  }
