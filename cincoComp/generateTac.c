#include "hashTab.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

node* make_temp()
{ 
static int nextTemp=0;
static char buffer[256]="";
sprintf(buffer, "_temporary%d",nextTemp);
nextTemp++;
return hash_insert(HASH_VARDEC, buffer)
}

node* make_label()
{

static int nextLabel=0;
statich char bufferLabel[256]="";
sprintf(buffer, "_label%d",nextLabel)
nextLabel++;;
return hash_insert(HASH_LABEL, bufferLabel) 
}

//---------------------------

TAC* do_binOpTac(int type, TAC* first, TAC* second) {
    node* hashNovo = 0;
    TAC* list = 0;
    TAC* final = 0;

   hashNovo = make_temp();
    list = tac_join(first, second);
    final = tac_create(type, hashNovo, first->res, second->res);
    final->ant = list;
    return final;
}
//---------------------
TAC* do_funTac(node* funName, TAC* function, TAC* params)
{
	TAC* beginFun=tac_create(TAC_BEGINFUN, funName, 0, 0);
	TAC* endFun=tac_create(TAC_ENDFUN, funName, 0, 0);
	TAC* final=tac_join(function, endFun);
	final=tac_join(beginFun, final);
	final=tac_join(params, final);
	return final;
}
//------------------
AC *do_returnTac(TAC *expr) {
    TAC *new;
    
	if (expr->type == TAC_VECTOR_ASS) {
        new= = tac_create(TAC_RETURN, expr->res, expr->op2, NULL);
       new= tac_join(expr->ant, new);
    } else {
		new=  tac_create(TAC_RETURN, expr->res, NULL, NULL);
		 new=tac_join(expr,nova);
	}
	
  return new;
}
//----------------------


TAC* do_ifTac(TAC* first, TAC * second)
{	
	TAC* iftac;
	node* label = make_label();
	TAC* final;
	if(first)
		iftac = tac_create(TAC_IFZ, label,first, 0,0);
	TAC* labelTac=tac_create(TAC_LABEL, label, 0, 0);
	
	final=tac_join(first, iftac);
	final=tac_join(final, second);
	final=tac_join(final, labelTac);
	return final;
	
}

//-----------------------------

TAC *do_assignTac(TAC* ident, TAC* expr) {
    TAC* nova = NULL;
    node* dest;
    if (ident == NULL) {
        printf("Missing value for assignment\n");
        exit(0);
    }
    dest = ident->res;    
    
    if (ident->type == TAC_VECTOR_ASS) {
        nova = tac_create(TAC_COPY, dest, expr->res, ident->op2);
        nova = tac_join(ident->prev, nova);
    } else {
        nova = tac_create(TAC_COPY, dest, expr->res, NULL);
    }
    
    return tac_join(expr,nova);
}
//---------------
TAC *do_vectorAssignTac(TAC* ident, TAC* index) {
    TAC* final;
    final = tac_create(TAC_VECTOR_ASS, ident->res, index->res, NULL);
    
   final= tac_join(index, final);
   return final;
}
//---------------------

TAC *do_ifElseTac(TAC* exp, TAC* ifCode, TAC* elseCode) {

    node* labelElse;
    node* labelFim;

    TAC* tacJz;
    TAC* tacLabelElse;
    TAC* tacLabelFim;
    TAC* tacGoto;
    TAC* final;

    labelElse = make_label();
    labelFim = make_label();
    
    tacLabelElse = tac_create(TAC_LABEL, labelElse, NULL, NULL);
    tacLabelFim = tac_create(TAC_LABEL, labelFim, NULL, NULL);
    tacJz = tac_create(TAC_IFZ, labelElse, exp->res, NULL);
    tacGoto = tac_create(TAC_GOTO, labelFim, NULL, NULL);
    
    final = tac_join(exp, tacJz);
    final = tac_join(final, ifCode);
    final = tac_join(final, tacGoto);
    final = tac_join(final, tacLabelElse);
    final = tac_join(final, elseCode);
    final = tac_join(final, tacLabelFim);
    
    return final;
}
//---------------------------

TAC *do_whileTac(TAC* exp, TAC* whileCode) {

    node* labelIni=make_label();
    node* labelFim=make_label();
    
    TAC* tacLabelIni;
    TAC* tacLabelFim;
    TAC* tacGoto;
    TAC* tacJz;
    TAC* temp;

        
    tacLabelIni = tac_create(TAC_LABEL, labelIni, NULL, NULL);
    tacLabelFim = tac_create(TAC_LABEL, labelFim, NULL, NULL);
     tacGoto = tac_create(TAC_GOTO, labelIni, NULL, NULL);
    tacJz = tac_create(TAC_IFZ, labelFim, exp->res, NULL);
   
    
    temp = tac_join(tacLabelIni, exp);
    temp = tac_join(temp, tacJz);
    temp = tac_join(temp, whileCode);
    temp = tac_join(temp, tacGoto);
    temp = tac_join(temp, tacLabelFim);
    
    return temp;
}


//---------------------------

TAC *do_funCallTac(TAC* funcall, TAC* params) {
    TAC* new;
    node* result = NULL;
       node* ident;
        
    if (funcall == NULL) {
        printf("Invalid funcall\n");
        exit(0);
    }
    
    result = make_temp();
    
    ident = funcall->res;
   new = tac_create(TAC_CALL, result, ident, NULL);   

    new= tac_join(params,new);
    return new;
}
//-------------------

TAC* do_paramsTac(TAC* exp, TAC* param)
{
	TAC* new;
	if(param==NULL)
	{
		printf("invalid params\n");
		exit(0);
	}
	
	new= tac_create(TAC_PARAM, exp->res, NULL, NULL);
	
	new= tac_join(param, new);
	return new;
}

TAC* do_listParamTac(TAC* param, TAC* listParam)
{
	TAC* new;
	if(listParam==NULL)
	{
		printf("invalid list of params\n");
		exit(0);
	}
	
	new = tac_create(TAC_PARAM, param->res, NULL, NULL);
	new = tac_join(new, listParam);
	
	return new;
}
//-------------------	

TAC* do_printTac(TAC *expr) 
{
    TAC* new;

	
   new = tac_create(TAC_PRINT, expr->res, NULL, NULL);
	
   new=tac_join(expr,new);
   return new;
}

//------------------------------

TAC* do_readTac(TAC* expr) {
    TAC* new;
    new = tac_create(TAC_READ, expr->res, NULL, NULL);
    
    return tac_join(expr,new);
}
//-----------------------------
//-----------------------------
//-----------------------------

tac* generateTacCode(AST* root)//geração de código
{
TAC* result[MAX_SONS];

for(i=0; i<MAX_SONS; ++i)
	results[i]=0;
	
if(root==0)
	return 0;

for(i=0; i<MAX_SONS; i++)
{
if(root->sons[i]!=0)
	results[i]=generateTacCode(root->sons[i]);
}

switch(root->type)
{
	case AST_identifier: 
	case AST_litchar:
	case AST_litstring:
	case AST_literal:
	case AST_litint:
		return tac_create(TAC_SYMBOL, root->hashNode, 0,0); 
		break;
		//--------------
	case AST_add: 
		return do_bin(TAC_ADD, results[0], results[1]); 
		break;
	case AST_mul:
		return do_bin(TAC_MUL, results[0], results[1]);
		break;
	case AST_sub: 
		return do_bin(TAC_SUB, results[0], results[1]); 
		break;
	case AST_div: 
		return do_bin(TAC_DIV, results[0], results[1]); 
		break;
	case AST_operand: 
		return do_bin(TAC_AND, results[0], results[1]); 
		break;
	case AST_operor: 
		return do_bin(TAC_OR, results[0], results[1]); 
		break;
	case AST_operle: 
		return do_bin(TAC_LE, results[0], results[1]); 
		break;
	case AST_operge: 
		return do_bin(TAC_GE, results[0], results[1]); 
		break;
	case AST_opereq: 
		return do_bin(TAC_EQ, results[0], results[1]); 
		break;
	case AST_operne: 
		return do_bin(TAC_NE, results[0], results[1]); 
		break;
	case AST_operl: 
		return do_bin(TAC_L, results[0], results[1]); 
		break;
	case AST_operg: 
		return do_bin(TAC_G, results[0], results[1]); 
		break;
	//----------------------------
	case AST_vecatrib:
	case AST_funcatrib:
	case AST_atrib: 
		return do_assignTac(result[0], results[1]); 
		break;
	
	case AST_idvec:
		return do_vectorAssignTac(result[0], result[1]);
		break;
	
	case AST_function: 
		return do_funTac(result[1], results[2], result[3]); 
		break; 
	case AST_oneparamlist:
	case AST_listparam:
		return do_listParamTac(result[1], result[2]);
	case AST_cmdblock:
	case AST_declr: 
		return tac_join(results[0], results[1]); 
		break;
	//-------------------
	case AST_kwreturn:
		return do_returnTac(result[0]);
		break;
	case AST_kwread:
		return do_readTac(result[0]);
		break;
	case AST_kwprint:
		return do_printTac(result[0]);
		break;
		//------------
	case AST_kwif: 
		return do_ifTac(results[0], results[1]); 
		break;
	case AST_kwelse: 
		return do_ifElseTac(results[0], results[1], results[2]); 
		break;
	case AST_kwwhile: 
		return do_whileTac(results[0], results[1]); 
		break;
		//-------------
		
	case AST_funcall:
		return do_funCall(result[0], result[1]);
		break;
	case AST_onecall:
	case AST_listcall:
		return do_paramTac(result[0], result[1]);
		break;
	
	
}
return result[0];
}
