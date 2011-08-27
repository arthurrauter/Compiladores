#ifndef HEADER_HASH
#define HEADER_HASH

typedef struct _node{
  char* text;
  int type;
  struct _node *next;
}node;

#define HASH_SIZE 997

void initHash(node** hashTable);

int insertHash(node** hashTable, char* text, int type);

node* getNode (node** hashTable ,char* text);

void printHash(node** hashTable);

void printList(node* hashNode);
#endif
