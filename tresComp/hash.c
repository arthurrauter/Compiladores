#include "hash.h"
#include "astree.h"
#include "y.tab.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void initHash(node** hashTable)
{
	
	int i;
	for(i=0; i<HASH_SIZE; i++)
		hashTable[i]=NULL;

}

node* insertHash(node** hashTable, char* text, int type)
{	
	node* hashNode;
	int adress=1, i;
	for(i=0;i<strlen(text);i++)
		adress = (adress*text[i])%HASH_SIZE + 1;
	if(hashTable[adress]!=NULL)//exists the node
	{
		if(hashTable[adress]->type==type) //same type of node
			return hashTable[adress];
		
		else//same node name, but other type
		{	
				
			node* aux1;
			node* aux2;
			aux2=hashTable[adress];
			aux1=aux2->next;
			while(aux1!=NULL)
			{
				if(aux1->type==type)//if the node is in the list
					return aux1;	
				aux2=aux1;
				aux1=aux1->next;
						
			}
			
			
			hashNode=(node*)malloc(sizeof(node));
			if(type==SYMBOL_LIT_INTEGER)
				hashNode->value=atoi(text);
			else
			{
		  		hashNode->text = (char*) malloc(strlen(text) +1);
				strcpy(hashNode->text,text);
			}
		 	hashNode->type=type;
			hashNode->next=NULL;
			aux2->next=hashNode;
			return hashNode;
		}
	}
	else//doesn't exists the node
	{	
		hashNode=(node*)malloc(sizeof(node));
		if(type==SYMBOL_LIT_INTEGER)
			hashNode->value=atoi(text);
		else
		{
	  	hashNode->text = (char*) malloc(strlen(text) +1);
			strcpy(hashNode->text,text);
		}
	 	hashNode->type=type;
		hashNode->next=NULL;
		hashTable[adress]=hashNode;
	}
	
	return hashNode;
	
}

char* getNodeInfo (node* node)
{
	if(node->type==SYMBOL_LIT_INTEGER)
	{
	//char buf[6]; cannot be declared here, for it's local to the function.

	// convert node->value to string [buf]
		sprintf(buf, "%d", node->value);
		return buf;
	}
	else
		return node->text;
}
		
node* getNode (node** hashTable ,char* text)
{
	int adress=1, i;
	for(i=0;strlen(text);i++)
		adress = (adress*text[i])%HASH_SIZE + 1;
	if(hashTable[adress]==NULL)
		return NULL;
	else
		return hashTable[adress];
}

void printHash(node** hashTable)
{
	int i;
	for(i=0; i<HASH_SIZE; i++)
		if(hashTable[i]!=NULL)//exists
		{
			printf ("%d: ", i);
			printList (hashTable[i]);		
			printf ("\n");
		}
}

void printList(node* hashNode)
{
	printf ("{");
	if (hashNode == NULL) printf (" ");
	while (hashNode)
	{	
		if(hashNode->text)
			printf ("(%d, %s)", hashNode->type, hashNode->text);
		else
			printf ("(%d, %d)", hashNode->type, hashNode->value);
		hashNode = hashNode->next;
		if (hashNode != NULL) 
			printf (", ");
		
	} 	
	printf ("}");
}
		


