#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"
// SEMANTIC CHECKS/ACTIONS
//
// OK - DONE - anotar declarações na hash e datatype 
// OK - DONE - verificar duplas declarações
// OK - DONE - verificar não declaradas
// - verificar tipos nos nodos de expressão (filhos devem ser corretos)
//    - operadores aritméticos e relacionais devem ter filhos aritméticos (int)
//    - igualdade e desigualdade podem ter filhos char
//    - operadores lógicos devem ter filhos lógicos ou relacionais
//    * aritméticos são: *+-/ lit_inteiro ou symbol com datatype aritmético
// - variáveis somente usadas como variáveis
// - vetores somente usados como vetores
// - funções somente usadas como funções
// OK - DONE - nas atribuições, datatypes devem ser iguais (compatíveis)
// OK - DONE- indice de vetor deve ser expressao inteira
// OK - DONE- argumentos versus parametros de função: número e tipos
// OK - DONE- valor de retorno versus tipo da função
// OK - DONE- verificar que simbolo dado para read é variável
void ast_check(AST*);
void hashCheckUndeclared(node** hashTable);

void checkALLAttributions(AST* root);
int check_funcatrib(AST* fatribNode);
int check_vecatrib(AST* vecatribNode);
int check_atrib(AST* atribNode);
void ast_check_declarations(AST*);
void ast_check_expressions(AST*);
void checkALLFuncalls(AST*, AST*);
void checkFuncall(AST*, AST*);
void  checkALLFunctionReturns(AST* root);
int check_function_return_type(AST* function);
void checkALLReads(AST* root);
int check_read_symbol(AST* readNode);
void checkALLVectorIndexes(AST* root);
int check_vector_index(AST* vectorNode);
int getExpressionDatatype(AST* expr);

void ast_check(AST* root)
{
	
	ast_check_declarations(root);
	printHash(hashTable);
	printf("\n\n");
	
	checkALLAttributions(root);
	hashCheckUndeclared(hashTable);
	
	checkALLVectorIndexes(root);
	checkALLFunctionReturns(root);
	checkALLFuncalls(root, root);
	checkALLReads(root);
	
	
	printf("\n\ncheck  ");
}

void checkALLVectorIndexes(AST* root)
{
	
	if(root == NULL || root==0 )
		return;
	if(root->type==AST_idvec ||root->type==AST_vecatrib)
	{
	
		 check_vector_index(root);
	}
	
	int i;
	for(i=0; i<MAX_SONS; i++)
		if(root->sons[i]!=0)
			checkALLVectorIndexes(root->sons[i]);	
}

int check_vector_index(AST* vectorNode)
{
	if(vectorNode->sons[0]->hashNode->type!=HASH_VECTORDEC)
	{
		printf("%s is not a vector\n", getNodeInfo(vectorNode->sons[0]->hashNode));
		return 0;
	}
	
	
	AST* indexExpr = vectorNode->sons[1];
	if(getExpressionDatatype(indexExpr)!=HASH_DATATYPE_INT)
	{
		printf("Index of vector %s must be and INT expression\n", getNodeInfo(vectorNode->sons[0]->hashNode));
		return 0;
	}
	return 1;
}
//---------------------------
void checkALLReads(AST* root)
{
	if(root == NULL || root==0 )
		return;
	if(root->type==AST_kwread)
	{
		 check_read_symbol(root);
	}
	
	int i;
	for(i=0; i<MAX_SONS; i++)
		if(root->sons[i]!=0)
			checkALLReads(root->sons[i]);	
	
}

int check_read_symbol(AST* readNode)
{
	if(readNode==0)
		return 0;//function null
	
	if(readNode->type!=AST_kwread)
		return 0;//not a function
			
	AST* readSymbol = readNode->sons[0];
	if(readSymbol->hashNode->type!=HASH_PARAM &&readSymbol->hashNode->type!=HASH_VARDEC)
	{
		printf("wrong read symbol: %s\n", getNodeInfo(readSymbol->hashNode));
		return 0;
	} 
	return 1;
}
//--------------------------------------------
void  checkALLFunctionReturns(AST* root)
{
	if(root == NULL || root==0 )
		return;
	if(root->type==AST_function)
	{
		 check_function_return_type(root);
	}
	
	int i;
	for(i=0; i<MAX_SONS; i++)
		if(root->sons[i]!=0)
			checkALLFunctionReturns(root->sons[i]);	
}

int check_function_return_type(AST* function)
{
	if(function==0)
		return 0;//function null
	
		if(function->type!=AST_function)
			return 0;//not a function
		int funDataType=function->sons[1]->hashNode->datatype;
		AST* commandBlock=function->sons[3]->sons[0];
		do{
			if(commandBlock->sons[0]&&commandBlock->sons[0]->type==AST_kwreturn)
			{
				AST* returnExpr= commandBlock->sons[0]->sons[0];
				
				if(getExpressionDatatype(returnExpr)!=funDataType)
				{
					printf("wrong return data type: %s\n", getNodeInfo(function->sons[1]->hashNode));
					return 0;
					}
				else if(getExpressionDatatype(returnExpr)==funDataType)
					return 1;//ok
						
			}
			else
			{
				commandBlock=commandBlock->sons[1];
			}
		}while(commandBlock);
	printf("return missing: %s\n",getNodeInfo(function->sons[1]->hashNode) );
	return 0;//no return

}
//--------------------------------
int getExpressionDatatype(AST* expr)
{
	if(expr->type==AST_logicexpr || expr->type==AST_aritexpr)
		return HASH_DATATYPE_INT;
	if(expr->type==AST_expr||expr->type==AST_idvec)
	{
		return expr->sons[0]->hashNode->datatype;
	}
	else
		return 0;
}
//-----------------------
void checkALLAttributions(AST* root)
{

if(root->type==AST_atrib)
{
	check_atrib(root);
}
if(root->type==AST_vecatrib)
{
	check_vecatrib(root);
}

if(root->type==AST_funcatrib)
{
	check_funcatrib(root);
}

int i;
for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		checkALLAttributions(root->sons[i]);
}

int check_funcatrib(AST* fatribNode)
{
	if(fatribNode->sons[0]->hashNode->type!=HASH_VARDEC&&fatribNode->sons[0]->hashNode->type!=HASH_PARAM)
	{
		printf("%s is not a variable\n", getNodeInfo(fatribNode->sons[0]->hashNode));
		return 0;
	}
	
	if(fatribNode->sons[1]->type!=AST_funcall)
	{
		printf("%s is not a function call\n", getNodeInfo(fatribNode->sons[1]->sons[0]->hashNode));
		return 0;
	}
	
	if(fatribNode->sons[1]->sons[0]->hashNode->type!=HASH_FUNDEC)
	{
		printf("%s is not a function\n", getNodeInfo(fatribNode->sons[1]->sons[0]->hashNode));
		return 0;
	}
	
	int atribDatatype=fatribNode->sons[0]->hashNode->datatype;
	int functionDatatype=fatribNode->sons[1]->sons[0]->hashNode->datatype; 
	if(functionDatatype!=atribDatatype)
	{
		printf("atribution of %s with function %s with wrong datatype\n", getNodeInfo(fatribNode->sons[0]->hashNode), getNodeInfo(fatribNode->sons[1]->sons[0]->hashNode));
		return 0;
	}
	else if(functionDatatype==atribDatatype)
		return 1;//ok
}

int check_vecatrib(AST* vecatribNode)
{
	if(vecatribNode->sons[0]->hashNode->type!=HASH_VECTORDEC)
	{
		printf("%s is not a vector\n", getNodeInfo(vecatribNode->sons[0]->hashNode));
		return 0;
	}
	
	AST* atribExpr= vecatribNode->sons[2];
	int vecatribDatatype=vecatribNode->sons[0]->hashNode->datatype;
	
	if(getExpressionDatatype(atribExpr)!=vecatribDatatype)
	{
		printf("atribution of %s with wrong datatype\n", getNodeInfo(vecatribNode->sons[0]->hashNode));
		return 0;
	}
	else if(getExpressionDatatype(atribExpr)==vecatribDatatype)
		return 1;//ok

}

int check_atrib(AST* atribNode)
{
	if(atribNode->sons[0]->hashNode->type!=HASH_VARDEC&&atribNode->sons[0]->hashNode->type!=HASH_PARAM)
	{
		printf("%s is not a variable\n", getNodeInfo(atribNode->sons[0]->hashNode));
		return 0;
	}
	
	
	
	AST* atribExpr= atribNode->sons[1];
	if(atribExpr->sons[0] && atribExpr->sons[0]->hashNode )
	{
		if(atribExpr->sons[0]->hashNode->type==HASH_FUNDEC){
			printf("%s is not a variable in the %s atribuition\n", getNodeInfo(atribExpr->sons[0]->hashNode ),  getNodeInfo(atribNode->sons[0]->hashNode));
			return 0;
		}
		if(atribExpr->sons[0]->hashNode->type==HASH_VECTORDEC)
		{
			if(!atribExpr->sons[1]){ //if the vector has no index
				printf("%s is not a variable in the %s atribuition\n", getNodeInfo(atribExpr->sons[0]->hashNode ),  getNodeInfo(atribNode->sons[0]->hashNode));
				return 0;
			}
				
			
		}
	}
	int atribDatatype=atribNode->sons[0]->hashNode->datatype;
	if(getExpressionDatatype(atribExpr)!=atribDatatype)
	{
		printf("atribution of %s with wrong datatype: %d, %d\n", getNodeInfo(atribNode->sons[0]->hashNode), atribDatatype, getExpressionDatatype(atribExpr));
		return 0;
	}
	else if(getExpressionDatatype(atribExpr)==atribDatatype)
		return 1;//ok

}
//---------------------------


void checkALLFuncalls(AST* root, AST* actual)
{
	
	if(root == NULL || root==0 || actual==0 || actual==NULL)
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


void checkFuncall(AST *funcall, AST* root)
{
	if(funcall->type!=AST_funcall|| root==0||funcall==0)
		return;	
	
	
	node* funIdent = funcall->sons[0]->hashNode;
	if(funIdent->type!=HASH_FUNDEC)
	{
		printf("%s is not a function\n", getNodeInfo(funIdent));
		return;
	} 
	
	AST* fundec = (AST*)getFundecOfFuncall(funcall, root);
	
		
	if(fundec==NULL)
	{
		printf("Not a function: %s", getNodeInfo(funIdent));
		
		return;
	}
	
	if(checkListParameters(fundec, funcall)!=1)
		printf("paramaters wrong: %s\n", getNodeInfo(funIdent));		
			
	
}


int checkListParameters(AST* fundec, AST* funcall)
{
	AST* fundecParamList=NULL;
	AST* funcallParamList=NULL;
	AST* fundecParam=NULL;
	AST* funcallParam=NULL;
	
	if(funcall->sons[1])
		funcallParamList= funcall->sons[1];
	
	if(fundec->sons[2])
		fundecParamList = fundec->sons[2];
	
	do{
	
	if(funcallParamList){
		funcallParam = funcallParamList->sons[0];
	}
	if(fundecParamList){
		fundecParam = fundecParamList->sons[0];
	}
		
	if((fundecParam&&!funcallParam)||funcallParam&&!fundecParam){
		
		return 0; //one list has a size different from the other 
		}
	else if(!fundecParam && !funcallParam){
	
		return 1;//both list with no param
		}
	else if(funcallParam&&fundecParam){
		if(funcallParam->hashNode->datatype != fundecParam->sons[1]->hashNode->datatype)
		{	
		printf("wrong parameters datatype on function call: %s\n", getNodeInfo(fundec->sons[1]->hashNode));
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
			printf("missing parameters on function call: %s\n", getNodeInfo(fundec->sons[1]->hashNode));
				return 0;
				} //one list of diferent size of other
		}
		else
		{	
		
			if(funcallParamList->sons[1])
			{	printf("too many parameters on function call: %s\n", getNodeInfo(fundec->sons[1]->hashNode));
				return 0; //one list of diferent size of other
				}
			else
				return 1;//ok list is over and done
		}		
			

	}
	}
	}while(funcallParamList->sons[0]||fundecParamList->sons[0]);
	
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
	
	if(root->type==AST_litchar)
		root->hashNode->datatype=HASH_DATATYPE_CHAR;
	if(root->type==AST_litint)
		root->hashNode->datatype=HASH_DATATYPE_INT;
	
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
			printf("Undeclared %s\n", hashTable[i]->text);
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
	if(!(isArithmetic(root->sons[0]))||!(isArithmetic(root->sons[1]))) //&& ou ||??
		printf("requires arith operands\n");
}

if(root->type==AST_operand|| root->type==AST_operor||root->type==AST_operle||
root->type==AST_operge||root->type==AST_opereq||root->type==AST_operne||
root->type==AST_operl||root->type==AST_operg)
{
	if(!(isLogic(root->sons[0]))&& !(isLogic(root->sons[1])))
		printf("requires logic operands\n");

}
//go on

int i;
for(i=0; i<MAX_SONS; i++)
	if(root->sons[i]!=0)
		ast_check_expressions(root->sons[i]);
}


int isLogic(AST* root)
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
	if(root->hashNode->datatype==HASH_DATATYPE_INT&&root->hashNode->type!=HASH_FUNDEC)
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
