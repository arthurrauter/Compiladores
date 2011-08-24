%{
#include <stdio.h>
#include "tokens.h"
#include "main.c"
#include "hash.h"
#include "hash.c"
int running;
int lineNumber;
node* hashTable[HASH_SIZE];

%}

%x COMM
%x STRING
%x CHAR


CHAR        [A-Za-z_]
DIGIT       [0-9]

%%

<CHAR>\'		BEGIN(INITIAL);
<CHAR>.			{insertHash (hashTable, yytext, LIT_CHAR);return LIT_CHAR;}

<STRING>\"		BEGIN(INITIAL);
<STRING>[^"]* 		{insertHash (&hash_table, yytext, LIT_STRING);return LIT_STRING;}


<COMM>"*/"              BEGIN(INITIAL);
<COMM>\n		{lineNumber++;}
<COMM>.

int 	{return KW_INT;}
float 	{return KW_FLOAT;}
bool 	{return KW_BOOL;}
char 	{return KW_CHAR;}
if 	{return KW_IF;}
then 	{return KW_THEN;}
else 	{return KW_ELSE;}
while	{return KW_WHILE;}
do	{return KW_DO;}
print	{return KW_PRINT;}
return	{return KW_RETURN;}
read	{return KW_READ;}

"<="	{return OPERATOR_LE;}
">="	{return OPERATOR_GE;}
"=="	{return OPERATOR_EQ;}
"!="	{return OPERATOR_NE;}
"&&"	{return OPERATOR_AND;}
"||"	{return OPERATOR_OR;}
false			{return LIT_FALSE;}
true 			{return LIT_TRUE;}
{CHAR}({CHAR}|{DIGIT})*	{insertHash (hashTable, yytext, TK_IDENTIFIER);return TK_IDENTIFIER;}
{DIGIT}+ 		{insertHash (hashTable, yytext, LIT_INTEGER); return LIT_INTEGER;}
{DIGIT}+"."{DIGIT}+	{return LIT_FLOAT;}
\"			BEGIN(STRING);
\'			BEGIN(CHAR);
["*""]""[""+"]		{return yytext[0];}
[,;:(){}"/"<>=!&$-]	{return yytext[0];}
"//".*			{}
"/*"                    BEGIN(COMM);
\n                  	{++lineNumber;}
[ \t]                   {  }
.			{}



%%

void initMe (void)
{
     initHash (hash_table);
     lineNum = 1;
     running = 1;
}

int getLineNumber(void){
	return lineNumber;
}



int yywrap ()
  {
  running = 0;
  return 1;
  }
