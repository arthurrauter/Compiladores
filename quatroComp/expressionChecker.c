#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"
// SEMANTIC CHECKS/ACTIONS
//
// DONE - anotar declarações na hash e datatype ( a fazer)
// DONE - verificar duplas declarações
// - verificar não declaradas
// - verificar tipos nos nodos de expressão (filhos devem ser corretos)
//    - operadores aritméticos e relacionais devem ter filhos aritméticos (int)
//    - igualdade e desigualdade podem ter filhos char
//    - operadores lógicos devem ter filhos lógicos ou relacionais
//    * aritméticos são: *+-/ lit_inteiro ou symbol com datatype aritmético
// - variáveis somente usadas como variáveis
// - vetores somente usados como vetores
// - funções somente usadas como funções
// - nas atribuições, datatypes devem ser iguais (compatíveis)
// - indice de vetor deve ser expressao inteira
// - argumentos versus parametros de função: número e tipos
// - valor de retorno versus tipo da função
// - verificar que simbolo dado para read é variável
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
			root->son[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
	
	if(root->type==AST_vector)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_VECTORDEC;
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_function)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_FUNDEC;
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_param)
	{
		if(root->son[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared");
		root->son[1]->hashNode->type=HASH_PARAM;
		
		if(root->sons[0]->type==AST_type_int)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->son[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}

for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_declarations(root->son[i]);
}

//-----------------------------

void ast_check_attributions(AST* root)
{

	if(root->type==AST_atrib)
	{
		switch (root->son[0]->hashNode->datatype)		{
			case HASH_DATATYPE_INT:
						switch(root->son[1]->type)				
						{
							case AST_identifier:
								if(root->son[1]->hashNode->datatype != HASH_DATATYPE_INT)
								{
									printf("variable not declared");
								}
								break;
							
							case AST_aritexpr:
								break;
							
							case AST_expr://literal
								if(root->son[1]->son[0]->type != AST_litint)
								{
									printf("incorrect type attribution");
								}
								break;
							
							default: printf("incorrect type attribution");
						}
				break;
			case HASH_DATATYPE_CHAR:
						 	switch(root->son[1]->type)				
									{
										case AST_identifier:
											if(root->son[1]->hashNode->datatype != HASH_DATATYPE_CHAR)
											{
												printf("variable not declared");
											}
											break;
														
										case AST_expr://literal
											if(root->son[1]->son[0]->type != AST_litchar)
											{
												printf("incorrect type attribution");
											}
											break;
							
										default: printf("incorrect type attribution");
									}
				break;
			default: printf("variable not declared");
		}
	}	


for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_attributions(root->son[i]);
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
