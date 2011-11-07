%{
//c code
//UFRGS, Compiladores 2011/1. Prof. Marcelo Johann
//Alessandra Leonnhardt - 181895
//Arthur C. Rauter -  180575
#include <stdio.h>
#include<stdlib.h>
#include "astree.h"
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
   AST *ast;
   node *hashNode;
}

%type<ast> statement_block
%type<ast> statement
%type<ast> declaracao
%type<ast> funcao
%type<ast> tipo
%type<ast> lista_parametros
%type<ast> parametro
%type<ast> bloco
%type<ast> bloco_comandos
%type<ast> comando
%type<ast> atribuicao
%type<ast> fluxo
%type<ast> expressao
%type<ast> aritmetica
%type<ast> logica
%type<ast> identifier
%type<ast> literal
%type<ast> string



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

%left OPERATOR_AND OPERATOR_OR
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE   
%left '+' '-'
%left '*' '/'

%nonassoc '(' ')'

%%


programa: statement_block { root = ast_insert_node(AST_declr , 0, $1, 0, 0, 0); }
;
statement_block: statement statement_block { $$ = ast_insert_node(AST_declr , 0, $1, $2, 0, 0); }
| { $$ = 0; }
; 
statement: declaracao { $$ = ast_insert_node(AST_vardecl , 0, $1, 0, 0, 0);}
|funcao	{ $$ = ast_insert_node(AST_fundecl , 0, $1, 0, 0, 0);}
;


identifier: TK_IDENTIFIER {$$ = ast_insert_node(AST_identifier, $1,0,0,0,0);}
;


declaracao: tipo identifier ';' { $$ = ast_insert_node(AST_var , 0, $1, $2, 0, 0);}
| tipo identifier '['LIT_INTEGER']' ';' { $$ = ast_insert_node(AST_vector , $4, $1, $2, 0, 0);}
;


tipo: KW_INT { $$ = ast_insert_node(AST_kwint , 0, 0, 0, 0, 0);}
 | KW_CHAR  { $$ = ast_insert_node(AST_kwchar ,0, 0, 0, 0, 0);}
;


funcao: tipo identifier '(' lista_parametros ')' bloco  { $$ = ast_insert_node(AST_function, 0, $1, $2, $4, $6);}
;
lista_parametros : parametro { $$ = ast_insert_node(AST_oneparamlist, 0, $1, 0, 0, 0);}		
| parametro',' lista_parametros { $$ = ast_insert_node(AST_listparam, 0, $1, $3, 0, 0);}		
| {$$=0;}
;
parametro: tipo identifier	{ $$ = ast_insert_node(AST_param, 0, $1, $2, 0, 0);}		
;


bloco: '{'bloco_comandos'}' { $$ = ast_insert_node(AST_block, 0, $2, 0, 0, 0);}
| comando ';' { $$ = ast_insert_node(AST_onecmdblock, 0, $1, 0, 0, 0);}
;

bloco_comandos: comando';' bloco_comandos { $$ = ast_insert_node(AST_cmdblock, 0, $1, $3, 0, 0);	 }
| comando { $$ = ast_insert_node(AST_cmdblock, 0, $1, 0, 0, 0);	 }
;

comando: atribuicao { $$ = ast_insert_node(AST_cmd, 0, $1, 0, 0, 0); }	
| fluxo { $$ = ast_insert_node(AST_control, 0, $1, 0, 0, 0); }	
| KW_READ identifier { $$ = ast_insert_node(AST_kwread,   0, $2, 0, 0, 0); }
| KW_PRINT aritmetica { $$ = ast_insert_node(AST_kwprint,  0,  $2, 0, 0, 0); }
| KW_PRINT string{ $$ = ast_insert_node(AST_kwprint,  0, $2, 0, 0, 0); }
| KW_PRINT '('string')'{ $$ = ast_insert_node(AST_kwprint, 0, $3, 0, 0, 0); }
| KW_RETURN expressao { $$ = ast_insert_node(AST_kwreturn, 0, $2, 0, 0, 0); }
| {$$=0;}
;


atribuicao: identifier '=' expressao {$$=ast_insert_node(AST_atrib, 0, $1, $3, 0, 0); }
| identifier '['expressao']' '=' expressao {$$=ast_insert_node(AST_vecatrib, 0, $1, $3, $6, 0); }
;



expressao:  identifier	{ $$ = ast_insert_node(AST_expr, 0, $1, 0, 0, 0); }	
| identifier '['expressao']' { $$ = ast_insert_node(AST_idvec, 0, $1, $3, 0, 0); }	
| literal { $$ = ast_insert_node(AST_expr, 0, $1, 0, 0, 0); }	
| logica { $$ = ast_insert_node(AST_logicexpr, 0, $1, 0, 0, 0); }	
| aritmetica { $$ = ast_insert_node(AST_aritexpr,  0, $1, 0, 0, 0); }	
;

literal : LIT_CHAR {$$ = ast_insert_node(AST_litchar, $1,0,0,0,0);}
| LIT_STRING {$$ = ast_insert_node(AST_litstring, $1,0,0,0,0);}
| LIT_FLOAT {$$ = ast_insert_node(AST_literal, $1,0,0,0,0);}
| LIT_FALSE {$$ = ast_insert_node(AST_literal, $1,0,0,0,0);}
| LIT_TRUE {$$ = ast_insert_node(AST_literal, $1,0,0,0,0);}
| LIT_INTEGER {$$ = ast_insert_node(AST_litint, $1,0,0,0,0);}
;

string: LIT_STRING {$$ = ast_insert_node(AST_litstring, $1,0,0,0,0);}
;


aritmetica: '(' aritmetica ')'	{ $$ = $2; }  
| expressao '+' expressao { $$ = ast_insert_node(AST_add,  0, $1, $3, 0, 0); }
| expressao '-' expressao { $$ = ast_insert_node(AST_sub,  0, $1, $3, 0, 0); }
| expressao '*' expressao { $$ = ast_insert_node(AST_mul,  0, $1, $3, 0, 0); }
| expressao '/' expressao { $$ = ast_insert_node(AST_div,  0, $1, $3, 0, 0); }
;


logica: '(' logica ')'	{ $$ = $2; } 
| expressao OPERATOR_AND expressao { $$ = ast_insert_node(AST_operand,  0, $1, $3, 0, 0); }
| expressao OPERATOR_OR expressao { $$ = ast_insert_node(AST_operor,  0, $1, $3, 0, 0); }
| expressao OPERATOR_LE expressao { $$ = ast_insert_node(AST_operle,  0, $1, $3, 0, 0); }
| expressao OPERATOR_GE expressao { $$ = ast_insert_node(AST_operge,  0, $1, $3, 0, 0); }
| expressao OPERATOR_EQ expressao { $$ = ast_insert_node(AST_opereq,  0, $1, $3, 0, 0); }
| expressao OPERATOR_NE expressao { $$ = ast_insert_node(AST_operne,  0, $1, $3, 0, 0); }
| expressao '<' expressao { $$ = ast_insert_node(AST_operl,  0, $1, $3, 0, 0); }
| expressao '>' expressao { $$ = ast_insert_node(AST_operg,  0, $1, $3, 0, 0); }
;

fluxo: KW_IF '('expressao')' KW_THEN bloco { $$ = ast_insert_node(AST_kwif,    0, $3, $6, 0, 0);}
| KW_IF '('expressao')' KW_THEN bloco KW_ELSE bloco { $$ = ast_insert_node(AST_kwelse,    0, $3, $6, $8, 0);}
|KW_WHILE '('expressao')' bloco { $$ = ast_insert_node(AST_kwwhile, 0, $3, $5, 0,0); }
;


















