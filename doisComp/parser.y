%{
//c code
#include <stdio.h>
#include "hash.h"

int yyerror (char *str)
    {
        fflush (stderr);
        fprintf (stderr, "Linha %d: erro - %s\n", getLineNumber(), str);
        exit (3);
    }

%}

%token KW_INT
%token KW_INT 
%token KW_FLOAT 
%token KW_BOOL  
%token KW_CHAR  
%token KW_IF 
%token KW_THEN 
%token KW_ELSE  
%token KW_WHILE   
%token KW_DO   
%token KW_PRINT   
%token KW_RETURN   
%token KW_READ 

%token OPERATOR_LE   
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_NE   
%token OPERATOR_AND   
%token OPERATOR_OR

%token TK_IDENTIFIER   
%token LIT_INTEGER   
%token LIT_FLOAT   
%token LIT_FALSE   
%token LIT_TRUE   
%token LIT_CHAR  
%token LIT_STRING 
%token TOKEN_ERROR

%%
programa: declaracao | funcao | programa | ;

//declaracao: tipo_var TK_IDENTIFIER ';'| tipo_var  TK_INDENTIFIER '['LIT_INTEGER']' ';' ;
//tipo_var: KW_CHAR|KW_INT;

declaracao: tipo TK_IDENTIFIER ';'| tipo  TK_INDENTIFIER '['LIT_INTEGER']' ';' ;
tipo: KW_INT|KW_FLOAT|KW_CHAR|KW_BOOL;

funcao: tipo TK_INDENTIFIER '(' lista_parametros ')' bloco;
lista_parametros:mais_parametros| ;
mais_parametros:parametro|parametro','mais_parametros;
parametro: tipo TK_INDENTIFIER;

bloco: '{'bloco_comandos'}';

bloco_comandos: comando';' bloco_comandos | ;

comando: atribuicao | fluxo | KW_READ TK_IDENTIFIER | 
KW_PRINT imprimir | KW_RETURN expressao| ;

imprimir: LIT_STRING|expressao;

atribuicao: TK_IDENTIFIER '=' expressao | TK_INDENTIFIER '['expressao']' '=' expressao;



expressao: '(' expressao ')'| TK_IDENTIFIER| vetor|
 LIT_CHAR | LIT_STRING | LIT_INTEGER | LIT_FLOAT |
  LIT_FALSE | LIT_TRUE | logica | aritmetica ;

aritmetica: expressao operador_aritmetico expressao;
operador_aritmetico: '+'|'-'|'*'|'/'|'%';

logica: expressao operador_logico expressao;
operador_logico: OPERADOR_AND| OPERADOR_OR|
 OPERADOR_LE| OPERADOR_GE| OPERADOR_EQ| OPERADOR_NE;

fluxo: KW_IF '('expressao')' KW_THEN bloco | 
KW_IF '('expressao')' KW_THEN bloco KW_ELSE bloco |
KW_WHILE '('expressao')' bloco;


















