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
    {/*[%d] "*/
  //case TK_IDENTIFIER: fprintf(stderr,"TK_IDENTIFIER: %s [%d] \n",yytext,getLineNumber()); break;
  //case LIT_INTEGER: fprintf(stderr,"LIT_INT: %d [%d] \n",atoi(yytext),getLineNumber());  break;
  //case KW_INT : fprintf(stderr,"KW_INT [%d] \n",getLineNumber());  break;
  //case KW_FLOAT : fprintf(stderr,"KW_FLOAT [%d] \n",getLineNumber());  break;
  //case LIT_FALSE : fprintf(stderr,"LIT_FALSE [%d] \n", getLineNumber());break;
  //case LIT_CHAR : fprintf(stderr,"LIT_CHAR: %s [%d] \n", yytext, getLineNumber());  break;
  //case LIT_STRING : fprintf(stderr,"LIT_STRING: %s [%d] \n", yytext, getLineNumber());  break;
  //case LIT_FLOAT : fprintf(stderr,"LIT_FLOAT: %s [%d] \n", yytext, getLineNumber());  break;
  //case 59: fprintf(stderr,"SEMICOLON [%d]\n", getLineNumber()); break;
  //case 43: fprintf(stderr,"+PLUS+ [%d] \n", getLineNumber()); break;
  //case 61: fprintf(stderr,"=EQUALS= [%d] \n", getLineNumber()); break;
  //case LIT_TRUE : fprintf(stderr,"LIT_TRUE [%d] \n", getLineNumber()); break;
  //case KW_CHAR : fprintf(stderr,"KW_CHAR [%d] \n",getLineNumber()); break;
  //case KW_IF : fprintf(stderr,"KW_IF [%d] \n",getLineNumber()); break;
  //case OPERATOR_NE : fprintf(stderr,"OPERATOR_NE [%d] \n",getLineNumber()); break;
  //case '[' :  fprintf(stderr,"BRACKETS OPEN [%d] \n",getLineNumber()); break;
	//default: fprintf(stderr,"???: %d [%d] \n",token, getLineNumber());
  default: fprintf(stderr,"%d [%d]\n",token, getLineNumber());  
    } 
  }
  }
