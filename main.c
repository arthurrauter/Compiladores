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
    case TK_IDENTIFIER: fprintf(stderr,"ident %s at line %d\n",yytext,LineNumber); break;
    case LIT_INTEGER: fprintf(stderr,"inteiro valor %d at line %d\n",atoi(yytext),LineNumber);  break;
    case TK_OPERATOR_STAR: fprintf(stderr,"asterisco at line %d\n",LineNumber);  break;
    case KW_INT : fprintf(stderr,"INT at line %d\n",LineNumber);  break;
    case KW_FLOAT : fprintf(stderr,"FLOAT at line %d\n",LineNumber);  break;
    case KW_BOOL : fprintf(stderr,"BOOL at line %d\n",LineNumber);  break;
    case KW_CHAR : fprintf(stderr,"CHAR at line %d\n",LineNumber);  break;
    case KW_IF : fprintf(stderr,"IF at line %d\n",LineNumber);  break;
    case KW_INT : fprintf(stderr,"INT at line %d\n",LineNumber);  break;
    default: fprintf(stderr,"Nao sei... %d \n",token);
      } 
    }
  }
