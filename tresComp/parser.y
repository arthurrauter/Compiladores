%{
//c code
//UFRGS, Compiladores 2011/1. Prof. Marcelo Johann
//Alessandra Leonnhardt - 181895
//Arthur C. Rauter -  180575
#include <stdio.h>
#include<stdlib.h>
#include "hash.h"
extern int getLineNumber();
extern int yylex (void);

int yyerror (char *str)
    {
        fflush (stderr);
        fprintf (stderr, "Linha %d: erro - %s\n", getLineNumber(), str);
        exit (3);
    }

%}

%union
{
   node *hashNode;
}




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

%token<hashNode> TK_IDENTIFIER   
%token<hashNode> LIT_INTEGER   
%token<hashNode> LIT_FLOAT   
%token<hashNode> LIT_FALSE   
%token<hashNode> LIT_TRUE   
%token<hashNode> LIT_CHAR  
%token<hashNode> LIT_STRING 
%token<hashNode> TOKEN_ERROR

%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE   
%left OPERATOR_AND OPERATOR_OR
%left '+' '-'
%left '*' '/'

%%


programa: statement_block;
statement_block: statement statement_block|;
statement:declaracao |funcao;

declaracao: tipo TK_IDENTIFIER ';'| tipo TK_IDENTIFIER '['LIT_INTEGER']' ';' ;
tipo: KW_INT | KW_CHAR ;


funcao: tipo TK_IDENTIFIER '(' lista_parametros ')' bloco  ;
lista_parametros : parametro | parametro',' lista_parametros | ;
parametro: tipo TK_IDENTIFIER;


bloco: '{'bloco_comandos'}'| comando ';' ;

bloco_comandos: comando';' bloco_comandos | comando ;

comando: atribuicao | fluxo | KW_READ TK_IDENTIFIER | KW_PRINT expressao | KW_RETURN expressao| ;



atribuicao: TK_IDENTIFIER '=' expressao | TK_IDENTIFIER '['expressao']' '=' expressao;



expressao: '(' expressao ')'| TK_IDENTIFIER| TK_IDENTIFIER '['expressao']'| LIT_CHAR | LIT_STRING | LIT_INTEGER | LIT_FLOAT |
  LIT_FALSE | LIT_TRUE | logica | aritmetica ;

aritmetica: expressao operador_aritmetico expressao;
operador_aritmetico: '+'|'-'|'*'|'/'|'%';

logica: expressao operador_logico expressao;
operador_logico: OPERATOR_AND| OPERATOR_OR|
 OPERATOR_LE| OPERATOR_GE| OPERATOR_EQ| OPERATOR_NE;

fluxo: KW_IF '('expressao')' KW_THEN bloco | 
KW_IF '('expressao')' KW_THEN bloco KW_ELSE bloco |
KW_WHILE '('expressao')' bloco;


















