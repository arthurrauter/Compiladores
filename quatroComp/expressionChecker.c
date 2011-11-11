//#include <stdio.h>
//#include <stdlib.h>
//#include "hash.h"
//#include "astree.h"
// SEMANTIC CHECKS/ACTIONS
//
// DONE - anotar declarações na hash e datatype ( a fazer)
// DONE - verificar duplas declarações
// DONE - verificar não declaradas
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
void ast_check(AST*);
void ast_check_declarations(AST*);
void ast_check_attributions(AST*);
void ast_check_expressions(AST*);

void ast_check(AST* root)
{
	ast_check_attributions(root);
}

void ast_check_declarations(AST* root)
{
	if(root == NULL || root==0)
		return;
	if(root->type==AST_var)
	{
		if(root->sons[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared\n");
		root->sons[1]->hashNode->type=HASH_VARDEC;	
		
		if(root->sons[0]->type==AST_type_int)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
	
	if(root->type==AST_vector)
	{
		if(root->sons[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared\n");
		root->sons[1]->hashNode->type=HASH_VECTORDEC;
		
		if(root->sons[0]->type==AST_type_int)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_function)
	{
		if(root->sons[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared\n");
		root->sons[1]->hashNode->type=HASH_FUNDEC;
		
		if(root->sons[0]->type==AST_type_int)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
	if(root->type==AST_param)
	{
		if(root->sons[1]->hashNode->type!=SYMBOL_IDENTIFIER)
			printf("already declared\n");
		root->sons[1]->hashNode->type=HASH_PARAM;
		
		if(root->sons[0]->type==AST_type_int)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_INT;
		if(root->sons[0]->type==AST_type_char)
			root->sons[1]->hashNode->datatype=HASH_DATATYPE_CHAR;
	}
int i;
for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_declarations(root->sons[i]);
}

//-----------------------------

void ast_check_attributions(AST* root)
{

	if(root->type==AST_atrib)
	{
		switch (root->sons[0]->hashNode->datatype)		{
			case HASH_DATATYPE_INT:
						switch(root->sons[1]->type)				
						{
							case AST_identifier:
								if(root->sons[1]->hashNode->datatype != HASH_DATATYPE_INT)
								{
									printf("%d: variable not declared\n", getLineNumber());
								}
								break;
							
							case AST_aritexpr:
								break;
							
							case AST_expr://literal
								if(root->sons[1]->sons[0]->type != AST_litint)
								{
									printf("%d: incorrect type attribution\n", getLineNumber());
								}
								break;
							
							default: printf("%d: incorrect type attribution\n", getLineNumber());
						}
				break;
			case HASH_DATATYPE_CHAR:
						 	switch(root->sons[1]->type)				
									{
										case AST_identifier:
											if(root->sons[1]->hashNode->datatype != HASH_DATATYPE_CHAR)
											{
												printf("%d: variable not declared\n", getLineNumber());
											}
											break;
														
										case AST_expr://literal
											if(root->sons[1]->sons[0]->type != AST_litchar)
											{
												printf("%d: incorrect type attribution\n", getLineNumber());
											}
											break;
							
										default: printf("%d: incorrect type attribution\n", getLineNumber());
									}
				break;
			default: printf("%d: variable not declared\n", getLineNumber());
		}
	}	

int i;
for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_attributions(root->sons[i]);
}

//-----------------------------
/*
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

int i;
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
} */
