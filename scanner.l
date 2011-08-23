%{
#include <stdio.h>
#include <tokens.h>
#include <main.c>
int running=1;
int lineNumber=0;
%}

%x COMMENTS

CHAR        [A-Za-z_]
DIGIT       [0-9]

%%
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

<=	{return OPERATOR_LE;}
>=	{return OPERATOR_GE;}
==	{return OPERATOR_EQ;}
!=	{return OPERATOR_NE;}
&&	{return OPERATOR_AND;}
||	{return OPERATOR_OR;}

{CHAR}({CHAR}|{DIGIT})*	{return TK_IDENTIFIER;}
{DIGIT}+ 		{return LIT_INTEGER;}
{DIGIT}+"."{DIGIT}+	{return LIT_FLOAT;}
false			{return LIT_FALSE;}
true 			{return LIT_TRUE;}
"'"."'"			{return LIT_CHAR;}
""".+"""		{return LIT_STRING;}
[,;:()[]{}+-*/<>=!&$]	{return yytext[0];}

"//".*			{}
"/*"                    BEGIN(COMM);
\n                  	{++lineNumber;}
[ \t]                   {  }
.			{return TOKEN_ERROR;}
<COMM>"*/"              BEGIN(INITIAL);
<COMM>.


%%

int getLineNumber(void){
	return lineNumber;
}



int yywrap ()
  {
  running = 0;
  return 1;
  }
