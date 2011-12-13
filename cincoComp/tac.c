#include "tac.h"

TAC *tac_create (int type, node* hashRes, node* hashOp2, node* hashOp3){
	TAC* new =NULL;
	new=(TAC*)malloc(1, sizeof(TAC));
	new->type=type;
	new->res=hashRes;
	new->op2=hashOp2;
	new->op3=hashOp3;
	new->prox=NULL;
	new->ant=NULL;
	return new;

}

void tac_printALL (TAC* list){
	TAC* aux=NULL;
	for(aux=first; aux!=NULL; aux=aux->next)
		tac_print_one(aux);
}

void tac_print_one (TAC* element){
	
	printf("TAC ");
	switch(element->type)
	{
		case TAC_UNDEF:
			printf("UNDEFINED ");
			break;
		case TAC_ADD:
			printf("ADD ");
			break;
		case TAC_SUB:
			printf("SUB ");
			break;
		case TAC_MUL:
			printf("MUL ");
		case TAC_DIV:
			printf("DIV ");
			break;
		case TAC_EQ:
			printf("EQ ");
			break;
		case TAC_LE:
			printf("LE ");
			break;
		case TAC_GE:
			printf("GE ");
			break;
		case TAC_NE:
			printf("NE ");
			break;
		case TAC_AND:
			printf("AND ");
			break;
		case TAC_OR:
			printf("OR ");
			break;
		case TAC_SYMBOL:
			printf("SYMBOL ");
			break;
		case TAC_COPY:
			printf("COPY ");
			break;
		case TAC_IFZ:
			printf("IFZ ");
			break;
		case TAC_IFNZ:
			printf("IFNZ ");
			break;
		case TAC_LABEL:
			printf("LABEL ");
			break;
		case TAC_GOTO:
			printf("GOTO ");
			break;
		case TAC_VECTOR:
			printf("VECTOR ");
			break;
		case TAC_VECTOR_ASS:
			printf("VECTOR ASS ");
			break;
		case TAC_CALL:
			printf("CALL ");
			break;
		case TAC_PARAM:
			printf("PARAM ");
			break;
		case TAC_BEGINFUN:
			printf("BEGINFUN ");
			break;
		case TAC_ENDFUN:
			printf("ENDFUN ");
			break;
		case TAC_RETURN:
			printf("RETURN ");
			break;
		case TAC_PRINT:
			printf("PRINT ");
			break;
		case TAC_READ:
			printf("READ ");
			break;
}

if (element->res) 
	printf("res: %s ", getNodeInfo(element->res));
	
  if (element->op2) 
  	printf("op2: %s ", getNodeInfo(element->op2));
	
  if (element->op3) 
  	printf("op3: %s ", getNodeInfo(tac->op3));
	

  printf("\n");
  }

}

TAC * tac_join( TAC* first, TAC* second){
	TAC* new=NULL;
	if(!first) 
		return second;
	if(!second)
		return first;
	
	new=second;
	while(new->ant)
		new=new->ant;
	new->ant=first;
	
	return second;
}


TAC *tac_invert(TAC* list){
	TAC* aux=list;
	if(aux)
		for(aux=list; aux->ant!=0; aux=aux->ant)
			aux->ant->prox = aux;
		
	return aux;
}
