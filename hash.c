#include "hash.h"

void initHash()
{
	int i;
	for(i=0; i<HASH_SIZE; i++)
		hashTable[i]=NULL;
}

 int hashInsert(char* text)
{	
	node* hashNode;
	int adress=1, i;
	for(i=0;strlen(text);i++)
		adress = (adress*text[i])%HASH_SIZE + 1;
	
	hashNode=(node*)malloc(sizeof(node));
	strcpy(hashNode->text,text);
	if(hashTable[adress]!=NULL)//exists the node
	{
	hashNode->next=hashTable[adress]->next;
	hashTable[adress]->next=hashNode;
	}
	else//doesn't exists the node
	{
	hashNode->next=NULL;
	hashTable[adress]=hashNode;
	}
	
	return adress;
	
}
		
node* getNode (char* text)
{
	int adress=1, i;
	for(i=0;strlen(text);i++)
		adress = (adress*text[i])%HASH_SIZE + 1;
	if(hashTable[adress]==NULL)
		return NULL;
	else
		return hashTable[adress];
}

int howManyOf(char *text)
{
	int length=0;
	node* hashNode = getNode(text);
	while( hashNode!=NULL)
	{
		length++;
		hashNode=hashNode->next;
	}
	return length;
}

