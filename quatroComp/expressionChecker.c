#include <stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "astree.h"

void ast_check_declarations(AST* root)
{
	if(root==null || root==0)
		return;
	
	if(root->type==AST_var)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_VARDEC;	
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_vector)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_VECTORDEC;
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_function)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_FUNDEC;
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_param)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_PARAM;
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashTable->datatype=HASH_DATATYPE_CHAR;
	}

for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_declarations(root->son[i]);
}

//-----------------------------

void ast_check_expressions(AST* root)

if(root=0)
return;

if(root->type==AST_add||root->type==AST_sub|| root->type== AST_div|| 
root->type==AST_mul)
{
	if(!(isArithmetic(root->sons[0]))||!(isAritmethic(root->sons[1]))) //&& ou ||??
		printf("requires arith operands");
}

if(root->type==AST_operand|| root->type==AST_operor||root->type==AST_operle||
root->type==AST_operge||root->type==AST_opereq||root->type==AST_operne||
root->type==AST_operl||root->type==AST_operg)
{
	if(!(isLogic(root->sons[0]))&& !(isLogic(root->sons[1])))
		printf("requires logic operands");

}
//go on


for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_expressions(root->sons[i]);
}


int isLogic(AST* root)//don't know how to do
{
if(root==0)
	return 0;
if(root->type==AST_operand|| root->type==AST_operor||root->type==AST_operle||
root->type==AST_operge||root->type==AST_opereq||root->type==AST_operne||
root->type==AST_operl||root->type==AST_operg)
	return 1;
else 
	return 0;
}

int isArithmetic(AST* root)
{ 
if(root==0)
	return 0;
if(root->type==AST_identifier){
	if(root->hashNode->datatype==HASH_DATATYPE_INT)
		return 1;
	else
		return 0;
		}
if(root->type==AST_litint||
root->type==AST_add||
root->type==AST_sub||
root->type==AST_mul||
root->type==AST_div)
	return 1;
else
	return 0;
}
