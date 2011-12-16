#include "astree.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int getLineNumber(void);
void ast_print_tree(AST* tree)
{
	int i;
	printf("\nAST:\n");
	if(tree)
	for(i=0; i<4; i++)	
		{
			if(tree->sons[i])
				ast_print(tree->sons[i]);
		}

}

void ast_to_program(AST* tree, FILE* fileAST)
{
	int i;
	if(!fileAST)
		fileAST=fopen("ASTprogram.txt", "w+");

	if(tree)
	{
		fputs(nodeString0(tree), fileAST);
		for(i=0; i<4; i++)	
		{
			if(tree->sons[i])
				ast_to_program(tree->sons[i], fileAST);
			switch(i)
			{
				case 0:fputs(nodeString1(tree), fileAST); break;
				case 1:fputs(nodeString2(tree), fileAST); break;
				case 2:fputs(nodeString3(tree), fileAST); break;
				case 3:fputs(nodeString4(tree), fileAST); break;
			}
		}
	}
	
}

char* nodeString0(AST* node)
{
	char *tmpSTR;
	tmpSTR = (char*)malloc(STRMAX);
	sprintf(tmpSTR, ""); //sprintf(tmpSTR, "wolololo"): escreve wolololo\0 em tmpSTR
 
	if(node)
	{
		
		switch(node->type)
		{
			
			case AST_identifier: if(node->hashNode) strcpy(tmpSTR, (char*)getNodeInfo(node->hashNode));break;
			case AST_literal:	if(node->hashNode) strcpy(tmpSTR, (char*)getNodeInfo(node->hashNode));break;
			
			case AST_kwint: strcpy(tmpSTR, "int ");break;
			case AST_kwchar: strcpy(tmpSTR, "char ");break;
			case AST_block: strcpy(tmpSTR, "{\n"); break;
			
			case AST_kwelse:
			case AST_kwif: strcpy(tmpSTR, "if ("); break;
			case AST_kwwhile : strcpy(tmpSTR, "while("); break;
			
			case AST_kwread: strcpy(tmpSTR, "read("); break;
			case AST_kwprint: strcpy(tmpSTR, "print("); break;
			
			case AST_kwreturn: strcpy(tmpSTR, "return(");break;
			
			case AST_litchar:
			strcpy(tmpSTR, "\'");
			if(node->hashNode) strcat(tmpSTR, (char*)getNodeInfo(node->hashNode));
			strcat(tmpSTR, "\'"); 
			break;
			
			case AST_litstring: 
			if(node->hashNode) strcpy(tmpSTR, "\""); 
			strcat(tmpSTR, (char*)getNodeInfo(node->hashNode));
			strcat(tmpSTR, "\""); 
			break;
			
			case AST_litint: 
			if(node->hashNode) strcpy(tmpSTR, (char*) getNodeInfo(node->hashNode)); 
			break;
			
		
			case AST_add:
			case AST_sub:
			case AST_mul:
			case AST_div:
			case AST_operand:
			case AST_operor:
			case AST_operle:
			case AST_operge:
			case AST_operl:
			case AST_operg:
			case AST_opereq:
			case AST_operne:strcpy(tmpSTR, "("); break;
			
			default:	
			strcpy(tmpSTR, "");
		}
	}
	if(tmpSTR[strlen(tmpSTR)-1]!='\0')
		tmpSTR[strlen(tmpSTR)]='\0';
	return tmpSTR;				
}

char* nodeString1(AST* node)
{
	
	char *tmpSTR;
	tmpSTR = (char*)malloc(STRMAX);
	sprintf(tmpSTR, ""); //sprintf(tmpSTR, "wolololo"): escreve wolololo\0 em tmpSTR	
	if(node)
	{
	
	
		switch(node->type)
		{
			case AST_block: strcpy(tmpSTR, "}\n"); break;
			case AST_onecall:
			case AST_oneparamlist: break;
			case AST_listcall:
			case AST_listparam: strcpy(tmpSTR, ", "); break;
			case AST_funcatrib:
			case AST_atrib: strcpy(tmpSTR, " = "); break;
			case AST_funcall: strcpy(tmpSTR, "(");break;
			case AST_cmd: strcpy(tmpSTR, ";\n"); break;
			
			case AST_idvec:
			case AST_vecatrib: strcpy(tmpSTR, "["); break;
			
			case AST_add: strcpy(tmpSTR, "+"); break;
			case AST_sub: strcpy(tmpSTR, "-"); break;
			case AST_mul: strcpy(tmpSTR, "*"); break;
			case AST_div: strcpy(tmpSTR, "/"); break;
			
			case AST_operand: strcpy(tmpSTR, "&&"); break;
			case AST_operor: strcpy(tmpSTR, "||"); break;
			case AST_operle: strcpy(tmpSTR, "<="); break;
			case AST_operge: strcpy(tmpSTR, ">="); break;
			case AST_operl: strcpy(tmpSTR, "<"); break;
			case AST_operg: strcpy(tmpSTR, ">"); break;
			case AST_opereq: strcpy(tmpSTR, "=="); break;
			case AST_operne: strcpy(tmpSTR, "!="); break;
			
			case AST_kwif:
			case AST_kwelse:strcpy(tmpSTR, ") then\n"); break;
			case AST_kwprint:
			case AST_kwwhile: strcpy(tmpSTR, ")\n"); break;
			
			
			case AST_kwreturn: strcpy(tmpSTR, ")"); break;
			
			default: strcpy(tmpSTR, "");
		}
	}
	if(tmpSTR[strlen(tmpSTR)-1]!='\0')
		tmpSTR[strlen(tmpSTR)]='\0';
	return tmpSTR;
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
			case AST_function: strcpy(tmpSTR, "(");break;
			case AST_var: strcpy(tmpSTR, ";\n");break;
			case AST_vector:strcpy(tmpSTR, "[");
			strcat(tmpSTR, (char*)getNodeInfo(node->hashNode));
			strcat(tmpSTR, "];\n");
			break;
			
			
			case AST_vecatrib:strcpy(tmpSTR, "] ="); break;
			case AST_idvec: strcpy(tmpSTR, "]");break;
			case AST_kwelse: strcpy(tmpSTR, "else\n"); break;
			
			case AST_add:
			case AST_sub:
			case AST_mul:
			case AST_div:
			case AST_operand:
			case AST_operor:
			case AST_operle:
			case AST_operge:
			case AST_operl:
			case AST_operg:
			case AST_opereq:
			case AST_operne: strcpy(tmpSTR, ")"); break;
			
			default:
				strcpy(tmpSTR, "");
		}
	}
	if(tmpSTR[strlen(tmpSTR)-1]!='\0')
		tmpSTR[strlen(tmpSTR)]='\0';
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
			case AST_funcall: strcpy(tmpSTR, ")");break;
			case AST_function:
				strcpy(tmpSTR, ")\n");
			break;
			default:
				strcpy(tmpSTR, "");
		}
	}
	if(tmpSTR[strlen(tmpSTR)-1]!='\0')
		tmpSTR[strlen(tmpSTR)]='\0';
	return tmpSTR;
	
}
//ok

char* nodeString4 (AST* node)
{
	
	char *tmpSTR;
	tmpSTR = (char*)malloc(STRMAX);
	sprintf(tmpSTR, "");
	if(node)
	{
		switch(node->type)
		{
		case AST_literal: strcpy(tmpSTR, (char*)getNodeInfo(node->hashNode));break;
		
		case AST_atrib: break;
		 case AST_kwread:
		 case AST_kwprint:
		 case AST_kwreturn: 
		 case AST_kwwhile:
		 case AST_vecatrib: strcpy(tmpSTR, ";\n"); break;
		 default: strcpy(tmpSTR, "");	
		}
	}
	if(tmpSTR[strlen(tmpSTR)-1]!='\0')
		tmpSTR[strlen(tmpSTR)]='\0';
	return tmpSTR;
	
}

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


void ast_print(AST *node)
{
	
	
	switch(node->type){
		case AST_declr:  printf("AST_declarations"); break;
		case AST_atrib:			printf("AST_atrib");		break;
		case AST_identifier: 	printf("AST_identifier");	break;
		case AST_cmdblock: 		printf("AST_cmdblock");		break;
		case AST_cmd: 			printf("AST_cmd");			break;
		case AST_onecmdblock: 			printf("AST_onecmdblock");			break;
		case AST_vecatrib: 			printf("AST_vecatrib");			break;
		case AST_aritexpr: 		printf("AST_aritexpr");		break;
		case AST_logicexpr: 		printf("AST_logicexpr");		break;
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
		case AST_var:			printf("AST_var");		break;
		case AST_idvec:			printf("AST_idvec");		break;
		case AST_kwprint:		printf("AST_kwprint");		break;
		case AST_kwprintstring:		printf("AST_kwprintstring");		break;
		case AST_kwreturn:		printf("AST_kwreturn");		break;
		case AST_kwread:		printf("AST_kwread");		break;
		case AST_kwwhile:		printf("AST_kwwhile");		break;
		case AST_kwif:			printf("AST_kwif");			break;
		case AST_kwelse:			printf("AST_kwelse");			break;
		case AST_litchar:		printf("AST_litchar");		break;
		case AST_litstring:		printf("AST_litstring");		break;
		case AST_litint:		printf("AST_litint");		break;
		case AST_function:		printf("AST_function");		break;
		case AST_kwint:		printf("AST_typeint");	 	break;
		case AST_kwchar:		printf("AST_typechar");	 	break;
		case AST_listparam:		printf("AST_listparam");	break;
		case AST_oneparamlist:		printf("AST_oneparamlist");	break;
		
		case AST_vardecl:		printf("AST_vardecl");		break;
		case AST_fundecl:		printf("AST_fundecl");		break;
		
		default: printf("%d", node->type);
		}


	if(node->hashNode){
		if(node->hashNode->text!=NULL)
			printf("\t \t %s",node->hashNode->text);
		else
			printf("\t \t %d", node->hashNode->value);
	}
	//printf("\t\tlinha %d");//, node->lineNumber);	
}


