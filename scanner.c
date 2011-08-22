%{
#include <stdio.h>
#include <tokens.h>
#include <main.c>
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

{CHAR}({CHAR}|{DIGIT})*   {return TK_IDENTIFIER;}

%%


