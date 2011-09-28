%{
	#include <stdlib.h> 
    #include "lex.yy.h"
	#include "astree.h"
	extern void yyerror(char *);
	

%}

%union{
	struct AST *ast;
	struct symData *symbol;
	
};

%type<ast> body
%type<ast> type
%type<ast> var
%type<ast> logicExpr
%type<ast> aritExpr
%type<ast> literal
%type<ast> expr
%type<ast> block
%type<ast> cmdblock
%type<ast> cmdblock2
%type<ast> cmd
%type<ast> atrib
%type<ast> idvar
%type<ast> ident
%type<ast> control
%type<ast> function
%type<ast> listparam
%type<ast> funcident
%type<ast> paramident
%type<ast> sizelit
%type<ast> declr
%type<ast> funcall
%type<ast> listcall
%type<ast> callident
%type<ast> string
%type<ast> nullcmd

%token KW_INT        
%token KW_BYTE       
%token KW_IF         
%token KW_THEN       
%token KW_ELSE       
%token KW_WHILE      
%token KW_PRINT      
%token KW_RETURN     
%token KW_READ       
%token OPERATOR_LE   
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_NE   
%token OPERATOR_AND  
%token OPERATOR_OR   

%token<symbol> TK_IDENTIFIER 
%token<symbol> LIT_INTEGER   
%token<symbol> LIT_CHAR      
%token<symbol> LIT_STRING    

%token TOKEN_ERROR  

%left '+' '-'
%left '*' '/'
%left OPERATOR_OR
%left OPERATOR_AND
%left OPERATOR_EQ OPERATOR_NE  
%left OPERATOR_LE OPERATOR_GE  

%nonassoc '(' ')'   

%%
programa:	body								{ root = ast_insert_node(AST_declr , 0, $1, 0, 0, 0); }
body:		declr body 							{ $$ = ast_insert_node(AST_declr , 0, $1, $2, 0, 0); }
	|											{ $$ = 0; }
	;
declr: 		var 								{ $$ = ast_insert_node(AST_vardecl , 0, $1, 0, 0, 0);}
	| 		function 			    		    { $$ = ast_insert_node(AST_fundecl , 0, $1, 0, 0, 0);}
	;
type: 		KW_INT  							{ $$ = ast_insert_node(AST_kwint , 0, 0, 0, 0, 0);}
	| 		KW_BYTE 							{ $$ = ast_insert_node(AST_kwbyte ,0, 0, 0, 0, 0);}
	;

var: 		type ident ';' 						{ $$ = ast_insert_node(AST_var,      0, $1, $2, 0, 0); }
	|		type ident'[' sizelit ']'';' 		{ $$ = ast_insert_node( AST_vector , 0, $1, $2, $4, 0); }
	;
function:	type funcident'('listparam')'block
											    { $$ = ast_insert_node(AST_function,  0, $1, $2, $4, $6);}
	;
listparam: 	type paramident listparam      		{ $$ = ast_insert_node(AST_listparam, 0, $1, $2, $3, 0);}		
	| 									    	{ $$ = 0;}		
	;
block: 		'{'cmdblock'}'						{ $$ = ast_insert_node(AST_block, 0, $2, 0, 0, 0);	 }
	;
cmdblock: 	block cmdblock						{ $$ = ast_insert_node(AST_onecmdblock, 0, $1, $2, 0, 0);	 }
	| 		cmd									{ $$ = ast_insert_node(AST_cmdblock, 0, $1, 0, 0, 0); 	 }
	|		cmd ';' cmdblock					{ $$ = ast_insert_node(AST_cmdblock, 0, $1, $3, 0, 0); 	 }
	|		nullcmd ';'	cmdblock				{ $$ = ast_insert_node(AST_nullcmd, 0, $3, 0, 0, 0); 	} 
	|											{ $$ = 0; }				
	;
nullcmd:										{ printf("BOM DIA\n"); } 
	;
cmdblock2:  block								{ $$ = ast_insert_node(AST_cmdblock2, 0, $1, 0, 0, 0);; }								
	| 		cmd									{ $$ = ast_insert_node(AST_cmdblock2, 0, $1, 0, 0, 0);; }
	;
cmd:		KW_READ	  ident						{ $$ = ast_insert_node(AST_kwread,   0,  $2, 0, 0, 0); }
	|		KW_PRINT  string					{ $$ = ast_insert_node(AST_kwprint,  0,  $2, 0, 0, 0); }
	|		KW_PRINT  aritExpr					{ $$ = ast_insert_node(AST_kwprint,  0, $2, 0, 0, 0); }
	|		KW_RETURN aritExpr					{ $$ = ast_insert_node(AST_kwreturn, 0, $2, 0, 0, 0); }
	|		atrib								{ $$ = ast_insert_node(AST_cmd, 0, $1, 0, 0, 0); }	
	|		control 							{ $$ = ast_insert_node(AST_control, 0, $1, 0, 0, 0); }	
	;

string:		LIT_STRING							{ $$ = ast_insert_node(AST_litstring, yylval.symbol,  0, 0, 0, 0); }
	;

atrib: 		idvar '=' expr						{ $$ = ast_insert_node(AST_atrib, 0, $1, $3, 0, 0); }
	
	;

control:	KW_WHILE'('logicExpr')' cmdblock2		
												{ $$ = ast_insert_node(AST_kwwhile, 0, $3, $5, 0,0); }
	|		KW_IF'('logicExpr')' KW_THEN cmdblock2		
												{ $$ = ast_insert_node(AST_kwif,    0, $3, $6, 0, 0);}
	|		KW_IF'('logicExpr')' KW_THEN cmdblock2 KW_ELSE cmdblock2 
												{ $$ = ast_insert_node(AST_kwelse,    0, $3, $6, $8, 0);}
	;

expr: 		aritExpr							{ $$ = ast_insert_node(AST_aritexpr,  0, $1, 0, 0, 0); }				
	| 		logicExpr							{ $$ = ast_insert_node(AST_logicexpr, 0, $1, 0, 0, 0); }	
	| 		funcall								{ $$ = ast_insert_node(AST_call,      0, $1, 0, 0, 0); }
	;	
logicExpr: 	'(' logicExpr')'					{ $$ = $2; } 
	|		aritExpr OPERATOR_LE aritExpr		{ $$ = ast_insert_node(AST_operle, 0, $1, $3, 0, 0); }
	|		aritExpr OPERATOR_GE aritExpr		{ $$ = ast_insert_node(AST_operge, 0, $1, $3, 0, 0); }
	|		aritExpr OPERATOR_EQ aritExpr		{ $$ = ast_insert_node(AST_opereq, 0, $1, $3, 0, 0); }
	|		aritExpr OPERATOR_NE aritExpr		{ $$ = ast_insert_node(AST_operne, 0, $1, $3, 0, 0); }
	|		logicExpr OPERATOR_OR logicExpr		{ $$ = ast_insert_node(AST_operor, 0, $1, $3, 0, 0); }
	|		logicExpr OPERATOR_AND logicExpr	{ $$ = ast_insert_node(AST_operor, 0, $1, $3, 0, 0); }
	;
aritExpr:  	'('aritExpr')'						{ $$ = $2; } 
	|		literal								{ $$ = ast_insert_node(AST_literal, 0, $1,  0, 0, 0);}	
	|		aritExpr '+'  aritExpr				{ $$ = ast_insert_node(AST_add,	0, $1, $3, 0, 0);	 }	
	|		aritExpr '-'  aritExpr				{ $$ = ast_insert_node(AST_sub,	0, $1, $3, 0, 0);	 }	
	|		aritExpr '*'  aritExpr				{ $$ = ast_insert_node(AST_mul,	0, $1, $3, 0, 0);	 }	
	|		aritExpr '/'  aritExpr				{ $$ = ast_insert_node(AST_div,	0, $1, $3, 0, 0);	 }	
	;
literal: 	LIT_INTEGER							{ $$ = ast_insert_node(AST_litint, 		yylval.symbol, 0, 0, 0, 0); } 
	|		LIT_CHAR							{ $$ = ast_insert_node(AST_litchar, 	yylval.symbol, 0, 0, 0, 0); }
	| 		idvar								{ $$ = $1;}
	;
idvar:		ident								{ $$ = ast_insert_node(AST_idvar, 	0, $1, 0, 0, 0);  } 
	| 		ident'[' expr ']' 					{ $$ = ast_insert_node(AST_idvec, 	0, $1, $3, 0, 0); } 
	;
ident:		TK_IDENTIFIER						{ $$ = ast_insert_node(AST_identifier, 	yylval.symbol, 0, 0, 0, 0); }
	;
funcident:	TK_IDENTIFIER						{ $$ = ast_insert_node(AST_identfunc, 	yylval.symbol, 0, 0, 0, 0); }
	;
paramident:	TK_IDENTIFIER						{ $$ = ast_insert_node(AST_identparam, 	yylval.symbol, 0, 0, 0, 0); }
	;
sizelit:	LIT_INTEGER							{ $$ = ast_insert_node(AST_litint, 		yylval.symbol, 0, 0, 0, 0); } 
	;
funcall:	funcident'('listcall')' 			{ $$ = ast_insert_node(AST_funcall,  0 , $1, $3, 0, 0); } 	
	;
listcall:	callident 		 					{ $$ = ast_insert_node(AST_onecall, 0 , $1, 0, 0, 0);  } 
	|	    callident','listcall 				{ $$ = ast_insert_node(AST_listcall, 0 , $1, $3, 0, 0); } 
	|											{ $$ = 0; } 
	;
callident:	expr								{ $$ = $1; } 
	;
	
%%

void yyerror(char *s) {
	fprintf(stderr, "Falha na linha %d: %s\n", getLineNumber(), s);
	exit(3);
}
