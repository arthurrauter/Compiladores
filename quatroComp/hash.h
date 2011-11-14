#ifndef HEADER_HASH
#define HEADER_HASH

#define HASH_SIZE 997

typedef struct _node{
  char* text;
  int type;
  int value;
  int datatype;
  struct _node *next;
}node;

char buf[6];
node* hashTable[HASH_SIZE];



#define HASH_VARDEC 11
#define HASH_DATATYPE_INT 22
#define HASH_DATATYPE_CHAR 33
#define HASH_VECTORDEC 44
#define HASH_FUNDEC 55


#define SYMBOL_UNDEFINED 0
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7

void hashCheckUndefined(node** hashTable);


char* getNodeInfo (node* node);


void initHash(node** hashTable);

node* insertHash(node** hashTable, char* text, int type);

node* getNode (node** hashTable ,char* text);

void printHash(node** hashTable);

void printList(node* hashNode);
#endif
