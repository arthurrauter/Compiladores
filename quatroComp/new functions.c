void ast_check_declarations(AST* root)
{
	if(root==null || root==0)
		return;
	
	if(root->type==VARDEC)
	{
		if(root->hashNode->type!=HASH_IDENTIFIER)
			printf("already declared");
		root->hashNode->type=HASH_VARDEC;	
		
		if(root->son[0]->type==AST_TYPE_INT)
			root->hashTable->datatype=HASH_DATATYPE_INT;
		if(root->son[0]->type==AST_TYPE_CHAR)
			root->hashTable->datatype=HASH_DATATYPE_CHAR;
}
//outros fundec e tal
for(i=0; i<MAX_SONS; i++)
	if(root->son[i]!=0)
		ast_check_declarations(root->son[i]);
		}

void ast_check_expressions(AST* root)

if(root=0)
return;

if(root->type==AST_ADD)
{
	if(!(isArithmetic(root->son[0]))||!(isAritmethic(root->son[1])))
		printf("add requires arith operands");
}
//go on


for(i=0; i<MAX_SONS; i++)
	if(root->son[i]!=0)
		ast_check_expressions(root->son[i]);
}

int is arithmetic(AST* root)
{ 
if(root==0)
	return 0;
if(root->type==AST_SYMBOL){
	if(root->hashNode->datatype==HASH_DATATYPE_INT)
		return 1;
	else
		return 0;
		}
if(root->type==AST_ADD||
root->type==AST_SUB||
root->type==AST_MUL||
root->type==AST_DIV)
	return 1;
}


//criar campo datatype na hash

//na hash
void hashCheckUndefined() //called on the first parser.y item
{
	int i;
	for(i=0; i<HASH_SIZE; i++)
	{
		if(hash[i]!=NULL && hash[i]->type==TK_IDENTIFIER)
			printf("Undeclared %s", hash[i]->text);
	}
}
/*
SEMANTIC CHECKS

anotar declarações da hash e datatype
verificar duplas declarações
verificar não declarados
verifiicar tipodnos nodos de expressão (filhos corretos)
	op arit devem ter filhos arit
	igualdade e desigualdade devem ter filhos char
	op logicos com filhos logicos ou relacionais
	arit sao *+-/ lit_inteiro ou symbol com datatype aritmetico
variaveis usadas so como variaveis
funcoes usadas so como funcoes
vetores usados como vetores
nas atribuições, datatypes devem ser iguais
indice de vetor deve ser expressao inteira
argumentos versus parametros de funções: numeros e tipos
valor de retornno versus tipo da função
varificar se o simbolo dado para a read é uma variavel
	*/
