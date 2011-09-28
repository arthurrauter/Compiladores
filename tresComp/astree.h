#ifndef HEADER_ASTREE
#define HEADER_ASTREE

#include "hashTab.h"

#define AST_declarations    1
#define AST_var             2
#define AST_function        3
#define AST_litint          4
#define AST_kwbyte          5
#define AST_kwint           6
#define AST_kwif            7
#define AST_kwthen          8
#define AST_kwelse          9
#define AST_kwwhile         10
#define AST_kwprint         11
#define AST_kwreturn        12
#define AST_kwread          13
#define AST_vector          14 
#define AST_sub             15
#define AST_mul             16
#define AST_div             17
#define AST_add             18
#define AST_atrib           19
#define AST_identifier      20
#define AST_vecident        21 // ?????
#define AST_listparam       22
#define AST_cmdblock        23
#define AST_cmdblock2       24
#define AST_cmd             25
#define AST_aritexpr        26
#define AST_literal         27
#define AST_operle 	        28
#define AST_operge 	        29
#define AST_opereq 	        30
#define AST_operne 	        31
#define AST_operor 	        32
#define AST_operand         33
#define AST_expr	        34
#define AST_block	        35
#define AST_litchar	        36
#define AST_BLABLAB	        37
#define AST_idvar	        38
#define AST_idvec	        39
#define AST_logicexpr       40
#define AST_typeint         41
#define AST_typebyte        42
#define AST_identfunc       43
#define AST_identparam      44
#define AST_vardecl 	    45
#define AST_fundecl	        46
#define AST_declr	        47
#define AST_funcall         48
#define AST_listcall        49
#define AST_call       		50
#define AST_control			51
#define AST_onecall			52
#define AST_litstring		53
#define AST_onecmdblock		54
#define AST_nullcmd			55	


		

//nodo e funções


typedef struct ast_node{
	symData *symbol;
	int type, lineNumber;	
	struct ast_node *sons[4];
}AST;

AST *root;

AST* ast_insert_node(int type, symData *symbol, AST *son0, AST *son1, AST *son2, AST *son3);
AST* ast_do_for_each(AST *node, void* (*fun)(AST*));
void* ast_print(AST *node);
char *print0(AST* node);
char *print1(AST* node);
char *print2(AST* node);
char *print3(AST* node);
char *print4(AST* node);
void ast_to_program(AST *tree, FILE* outAST);

#endif
