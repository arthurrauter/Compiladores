#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astree.h"

extern int getLineNumber(void);

void ast_to_program(AST *tree, FILE* outAST)
{
	int i, writePos=5;
	if(!outAST) fopen("stdOut.s", "w+");
	if(tree)
	{
		fputs(print0(tree), outAST);
		for(i=0; i<4; i++)	
		{
			if(tree->sons[i])
				ast_to_program(tree->sons[i], outAST);
			switch(i)
			{
				case 0:	fputs(print1(tree), outAST); break;
				case 1:	fputs(print2(tree), outAST); break;
				case 2:	fputs(print3(tree), outAST); break;
				case 3:	fputs(print4(tree), outAST); break;
			}
		}
	}
}
char* nodeString0(AST* node)
{
	char *tmpSTR;
	tmpSTR = (char*)malloc(STRMAX);
	sprintf(tmpSTR, "");
	
	if(node)
	{
		switch(node->type)
		{
			case: AST_identifier:
			case AST_literal:
				strcpy(tmpSTR, getNodeInfo(node->hashNode));
			break;
			case: AST_kwint:
				strcpy(tmpSTR, "int");
			break;
			case AST_kwchar:
				strcpy(tmpSTR, "char");
			break;
				
			
}

char* nodeString2(AST* node)
{
	char *tmpSTR;
	tmpSTR = (char*)malloc(STRMAX);
	sprintf(tmpSTR, "");
	
	if(node)
	{
		switch(node->type)
		{
			case AST_vector:
			//...
			break;
			case AST_function:
			//...
			break;
			case AST_vecatrib:
			//...
			break;
			case AST_kwelse:
			//...
			break;
			default:
				strcpy(tmpSTR, "");
		}
	}
	return tmpSTR;
}

//ok
char* nodeString3 (AST* node)
{
	char *tmpSTR;
	tmpSTR = (char*)malloc(STRMAX);
	sprintf(tmpSTR, "");
	if(node)
	{
		switch(node->type)
		{
			case AST_function:
				strcpy(tmpSTR, ")\n");
			break;
			case AST_vector:
				sprintf(tmpSTR, "];\n");
				break;
			default:
				strcpy(tmpSTR, "");
		}
	}
	return tmpSTR;
}
//ok
AST* ast_insert_node(int type, node *hashNode, AST *son0, AST *son1, AST *son2, AST *son3)
{
	AST *newNode;

	newNode=(AST *) calloc(1,sizeof(AST));
	newNode->lineNumber = getLineNumber();

	if(hashNode)
		newNode->hashNode=hashNode;

	newNode->type=type;
	newNode->sons[0]=son0;
	newNode->sons[1]=son1;
	newNode->sons[2]=son2;
	newNode->sons[3]=son3;	

	return newNode;
}


/*AST* ast_do_for_each(AST *node, void* (*fun)(AST*))
{
	int i;

	if(node)
		(*fun)(node);

	for(i=0; i<4; i++)	
		if(node->sons[i])
			ast_do_for_each(node->sons[i],fun);
}*/


void* ast_print(AST *node)
{
	printf("\nAST:");
	switch(node->type){
		case AST_declarations:  printf("AST_declarations"); break;
		case AST_atrib:			printf("AST_atrib");		break;
		case AST_identifier: 	printf("AST_identifier");	break;
		case AST_cmdblock: 		printf("AST_cmdblock");		break;
		case AST_cmd: 			printf("AST_cmd");			break;
		case AST_aritexpr: 		printf("AST_aritexpr");		break;
		case AST_literal: 		printf("AST_literal");		break;
		case AST_expr:			printf("AST_expr");			break;
		case AST_add: 			printf("AST_add");			break;
		case AST_sub: 			printf("AST_sub");			break;
		case AST_mul: 			printf("AST_mul");			break;
		case AST_div:			printf("AST_div");			break;
		case AST_operle:		printf("AST_operle");		break;
		case AST_operge:		printf("AST_operge");		break;
		case AST_opereq:		printf("AST_opereq");		break;
		case AST_operne:		printf("AST_operne");		break;
		case AST_operor:		printf("AST_operor");		break;
		case AST_operand:		printf("AST_operand");		break;
		case AST_block:			printf("AST_block");		break;
		case AST_litint:		printf("AST_litint");		break;
		case AST_idvar:			printf("AST_idvar");		break;
		case AST_idvec:			printf("AST_idvec");		break;
		case AST_kwprint:		printf("AST_kwprint");		break;
		case AST_kwreturn:		printf("AST_kwreturn");		break;
		case AST_kwread:		printf("AST_kwread");		break;
		case AST_kwwhile:		printf("AST_kwwhile");		break;
		case AST_kwif:			printf("AST_kwif");			break;
		case AST_litchar:		printf("AST_litchar");		break;
		case AST_function:		printf("AST_function");		break;
		case AST_typeint:		printf("AST_typeint");	 	break;
		case AST_listparam:		printf("AST_listparam");	break;
		case AST_identfunc:		printf("AST_identfunc");	break;
		case AST_identparam:	printf("AST_identparam");	break;
		case AST_vardecl:		printf("AST_vardecl");		break;
		case AST_fundecl:		printf("AST_fundecl");		break;
		case AST_declr:			printf("AST_declr");		break;
		case AST_funcall:		printf("AST_funcall");		break;
		case AST_listcall:		printf("AST_listcall");		break;
		case AST_call:			printf("AST_call");			break;
		case AST_nullcmd:		printf("AST_nullcmd");		break;



		default: printf("%d", node->type);
	} 

	if(node->hashNode){
		if(node->hashNode.text!=NULL)
			printf("\t \t %s",node->hashNode.text);
		else
			printf("\t \t %d", node->hashNode.value);
	}
	//printf("\t\tlinha %d");//, node->lineNumber);	
}

