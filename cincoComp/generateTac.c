
#include "tac.h"
#include "astree.h"


node* make_temp()
{ 
static int nextTemp=0;
static char bufferTemp[256]="";
sprintf(bufferTemp, "_temporary%d",nextTemp);
nextTemp++;
return insertHash(hashTable, bufferTemp, HASH_VARDEC);
}

node* make_label()
{

static int nextLabel=0;
static char bufferLabel[256]="";
sprintf(bufferLabel, "_label%d",nextLabel);
nextLabel++;
return insertHash(hashTable, bufferLabel, HASH_LABEL) ;
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
TAC* do_funTac(node* funName, TAC* params, TAC* function)
{
	
	TAC* beginFun=tac_create(TAC_BEGINFUN, funName, 0, 0);
	TAC* endFun=tac_create(TAC_ENDFUN, funName, 0, 0);
	
	TAC* final=tac_join(beginFun, function);
	final=tac_join(final, endFun);
	final=tac_join(params, final);
	return final;
}
//------------------
TAC *do_returnTac(TAC *expr) {
    TAC *new=NULL;
    
	if (expr->type == TAC_VECTOR_ASS) {
        new= tac_create(TAC_RETURN, expr->res, expr->op2, NULL);
       new= tac_join(expr->ant, new);
    } else {
		new=  tac_create(TAC_RETURN, expr->res, NULL, NULL);
		 new=tac_join(expr,new);
	}
	
  return new;
}
//----------------------


TAC* do_ifTac(TAC* expr, TAC * code)
{	
	TAC* iftac;
	node* label = make_label();
	TAC* final=NULL;
	if(expr)
		iftac = tac_create(TAC_IFZ, label,expr->res,0);
	TAC* labelTac=tac_create(TAC_LABEL, label, 0, 0);
	
	final=tac_join(expr, iftac);
	final=tac_join(final, code);
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
        nova = tac_join(ident->ant, nova);
    } else {
        nova = tac_create(TAC_COPY, dest, expr->res, NULL);
    }
    
    return tac_join(expr,nova);
}
//---------------
TAC *do_vectorAssignTac(TAC* ident, TAC* index) {
    TAC* final=NULL;
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
    TAC* final=NULL;

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
    TAC* temp=NULL;

        
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
    TAC* new=NULL;
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

TAC* do_callParamsTac(TAC* exp, TAC* param)
{
	if(!exp)
	{
	printf("y u no exist?");
	getc(stdin);}
	TAC* new=NULL;
	
	new= tac_create(TAC_CALLPARAM, exp->res, NULL, NULL);
	new=tac_join(param, new);
	return new;
}

TAC* do_oneCallParamsTac(node* param)
{
	TAC* new=NULL;
	new=tac_create(TAC_CALLPARAM, param, NULL, NULL);
	return new;
}
//-------------------	

TAC* do_printTac(TAC *expr) 
{
    TAC* new=NULL;

	
   new = tac_create(TAC_PRINT, expr->res, NULL, NULL);
	
   new=tac_join(expr,new);
   return new;
}

//------------------------------

TAC* do_readTac(TAC* expr) {
    TAC* new=NULL;
    new = tac_create(TAC_READ, expr->res, NULL, NULL);
    
    return tac_join(expr,new);
}

//-----------------------

TAC* do_funParamTac(node* param_id)
{

    TAC* param = tac_create(TAC_PARAM, param_id, 0, 0);
    
    return param;
}


//-----------------------------
//-----------------------------
//-----------------------------

TAC* generateTacCode(AST* root)//geração de código
{
TAC* results[MAX_SONS];
int i;
for(i=0; i<MAX_SONS; ++i)
	results[i]=0;
	
if(root==0)
	return 0;

for(i=0; i<MAX_SONS; i++)
{
if(root->sons[i]!=0)
	results[i]=generateTacCode(root->sons[i]);
	
}
int a;
switch(root->type)
{
	 
	case AST_litchar:
	case AST_litstring:
	case AST_literal:
	case AST_litint:
		return tac_create(TAC_LITERAL, root->hashNode, 0,0); 
		break;
	case AST_identifier:
		return tac_create(TAC_SYMBOL, root->hashNode, 0,0); 
		break;
		//--------------
	case AST_add: 
		return  do_binOpTac(TAC_ADD, results[0], results[1]); 
		break;
	case AST_mul:
		return do_binOpTac(TAC_MUL, results[0], results[1]);
		break;
	case AST_sub: 
		return do_binOpTac(TAC_SUB, results[0], results[1]); 
		break;
	case AST_div: 
		return do_binOpTac(TAC_DIV, results[0], results[1]); 
		break;
	case AST_operand: 
		return do_binOpTac(TAC_AND, results[0], results[1]); 
		break;
	case AST_operor: 
		return do_binOpTac(TAC_OR, results[0], results[1]); 
		break;
	case AST_operle: 
		return do_binOpTac(TAC_LE, results[0], results[1]); 
		break;
	case AST_operge: 
		return do_binOpTac(TAC_GE, results[0], results[1]); 
		break;
	case AST_opereq: 
		return do_binOpTac(TAC_EQ, results[0], results[1]); 
		break;
	case AST_operne: 
		return do_binOpTac(TAC_NE, results[0], results[1]); 
		break;
	case AST_operl: 
		return do_binOpTac(TAC_L, results[0], results[1]); 
		break;
	case AST_operg: 
		return do_binOpTac(TAC_G, results[0], results[1]); 
		break;
	//----------------------------
	case AST_vecatrib:
	case AST_funcatrib:
	case AST_atrib: 
		return do_assignTac(results[0], results[1]); 
		break;
	
	case AST_idvec:
		return do_vectorAssignTac(results[0], results[1]);
		break;
	//-----------------
	case AST_function: 
	
		return do_funTac(results[1]->res, results[2], results[3]); 
		break; 
	
	case AST_param:
		return do_funParamTac(results[1]->res);
		break;
	case AST_listparam:
	
		return tac_join(results[0], results[1]);
		break;
	
		return results[0];
		//--------------------
		
	case AST_cmdblock:
	case AST_declr: 
		
		return tac_join(results[0], results[1]); 
		break;
	//-------------------
	case AST_kwreturn:
		return do_returnTac(results[0]);
		break;
	case AST_kwread:
		return do_readTac(results[0]);
		break;
	case AST_kwprint:
		return do_printTac(results[0]);
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
		return do_funCallTac(results[0], results[1]);
		break;
	case AST_onecall:
		return do_oneCallParamsTac(root->sons[0]->hashNode);
		break;
	case AST_listcall:
		return do_callParamsTac(results[0], results[1]);
		break;
	
	
}

return results[0];
}
