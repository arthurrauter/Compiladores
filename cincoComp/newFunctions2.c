//--na hash

node* make_temp()
{ static int next=0;
statich char[] buffer
sprintf(buffer, "temporary%d",next++);
return hash_insert(HASH_IDENTIFIER, buffer)
}

node* make_label()
{
static int next=0;
statich char[] bufferLabel
sprintf(buffer, "label%d",next++);
return hash_insert(HASH_LABEL, bufferLabel) //HASH_LABEL?
}

//--na ast
TAC* do_bin(int op, TAC* r0, TAC* r1)
{
	return tac_join(tac_join(r0, r1), tac_create(op, make_temp(), r0?r0->res:0,r1?r1->res:0));
}

tac* genco(AST* root)//geração de código
{
TAC* result[MAX_SONS];

for(i=0; i<MAX_SONS; ++i)
	results[i]=0;
	
if(root==0)
return 0;

for(i=0; i<MAX_SONS; i++)
{
if(root->sons[i]!=0)
	results[i]=genco(root->sons[i]);
}

switch(root->type)
{
case AST_SYMBOL: return tac_create(TAC_SYMBOL, root->symbol, 0,0); break;
case AST_ADD: return do_bin(AST_ADD, results[0], results[1]); break;
//outras operações igual o add
case AST_ATTR: return do_attr(root->symbol, results[0]); break;
case AST_FUNDEC: return do_fun(root->symbol, results[1]); break; 
case AST_CMDL:
case AST_DECLIST: return tac_join(results[0], results[1]); break;
case AST_IFT: return do_ift(results[0], results[1]); break;
}
return 0;
}

TAC* do_attr(node* var, TAC* r0)
{
return tac_join(results[0], tac_create(TAC_COPY, var, r0? 
r0->res:0,0);
}

TAC* do_fun(node* funName, TAC* r1)
{
	return tac_join(tac_create(TAC_BEGINFUN, funName, 0, 0), tac_join(r1, tac_create(TAC_ENDFUN, funName, 0, 0)));
}

TAC* do_ift(TAC*r0, TAC *r1)
{
	node*label = make_label();
	TAC* iftac = tac_create(TAC_IFZ, label,r0? r0->res:0,0);
	TAC* labelTac=tac_create(TAC_LABEL, label, 0, 0);
	
	return tac_join(tac_join(tac_join(r0, iftac), r1), labelTac);
}

}
