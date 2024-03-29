#include "hash.h"
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
		return hashTable[adress];
	else//doesn't exists the node
	{	
		hashNode=(node*)malloc(sizeof(node));
		/*if(type==SYMBOL_LIT_INTEGER)
			hashNode->value=atoi(text);
		else
		{*/
	  	hashNode->text = (char*) malloc(strlen(text) +1);
			strcpy(hashNode->text,text);
		//}
	 	hashNode->type=type;
		hashNode->next=NULL;
		hashTable[adress]=hashNode;
	}
	
	return hashNode;
	
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
		printf ("(%d, %s)", hashNode->type, hashNode->text);
		hashNode = hashNode->next;
		if (hashNode != NULL) printf (", ");	
	} 	
	printf ("}");
}
		


