#ifndef HEADER_HASH
#define HEADER_HASH

typedef struct _node{
  char* text;
  int type;
  int value;
  struct _node *next;
}node;

char buf[6];

#define HASH_SIZE 997

#define SYMBOL_UNDEFINED 0
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7

void initHash(node** hashTable);

node* insertHash(node** hashTable, char* text, int type);

node* getNode (node** hashTable ,char* text);

void printHash(node** hashTable);
char* getNodeInfo (node* node);
void printList(node* hashNode);
#endif
