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
void hashCheckUndeclared(node** hashTable);
void ast_check_attributions(AST*);
void ast_check_expressions(AST*);
void checkALLFuncalls(AST*, AST*);

void ast_check(AST* root)
{
	ast_check_attributions(root);
	checkALLFuncals(root, root);
}

void checkALLFuncalls(AST* root, AST* actual)
{
	
	if(root == NULL || root==0 || actual=0 || actual=NULL)
		return;
	if(actual->type==AST_funcall)
	{
		checkFuncall(actual, root);
	}
	
	int i;
	for(i=0; i<MAX_SONS; i++)
		if(actual->sons[i]!=0)
			checkALLFuncalls(root,actual->sons[i]);

}
//------------------

void checkFuncall(AST *funcall, AST* root)
{
	if(root->type!=AST_funcall|| root==0)
		return;	
	
	node* funIdent = root->sons[0]->hashNode;
	if(funIdent->datatype!=HASH_FUNDEC)
		printf("Not a Function: %s", getNodeInfo(funIdent));
	else
	{
		AST* fundec = getFundecOfFuncall(funcall, root);
		
		if(!checkListParameters(fundec, funcall))
			printf("paramaters wrong");		
			
	}
}
//-------------------------

int checkListParameters(AST* fundec, AST* funcall)
{
	AST* fundecParamList = fundec->sons[2];
	AST* funcallParamList= funcall->sons[1];
	
	do{
	
	AST* funcallParam = funcallParamList->sons[0];
	AST* fundecParam = fundecParamList->sons[0];
	
	if(funcallParam->sons[0]->hashNode->datatype != fundecParam->sons[1]->hashNode->datatype)
	{printf("wrong parameter type on function call: %s", getNodeInfo(fundecParam->sons[0]->hashNode));
		return 0;//wrong datatype of the params
		}
	else{ //right datatype
		if(fundecParamList->sons[1])//continues the list
		{
			if(funcallParamList->sons[1])
			{
				fundecParamList=fundecParamList->sons[1];
				funcallParamList=funcallParamList->sons[1];
							
			}
			else{
			printf("missing parameters on function call: %s", getNodeInfo(fundecParam->sons[0]->hashNode));
				return 0;
				} //one list of diferent size of other
		}
		else
		{
			if(funcallParamList->sons[1])
			{	printf("too many parameters on function call: %s", getNodeInfo(fundecParam->sons[0]->hashNode));
				return 0; //one list of diferent size of other
				}
			else
				return 1;//ok list is over and done
		}		
			

	}
	}while(funcallParamList->sons[0]||fundeclParamList->sons[0]);
	
	return 0;
}
//--------------------------------
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

void hashCheckUndeclared(node** hashTable) //called on the first parser.y item
{
	int i;
	for(i=0; i<HASH_SIZE; i++)
	{
		if(hashTable[i]!=NULL && hashTable[i]->type==SYMBOL_IDENTIFIER)
			printf("Undeclared %s", hashTable[i]->text);
	}
}
//-----------------------------

void ast_check_expressions(AST* root) 
{
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
} 
