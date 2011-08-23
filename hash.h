typedef struct _node{
  char *text;
  struct _node *next;
}node;

#define HASH_SIZE 997
node* hashTable[HASH_SIZE];

void initHash();

int hashInsert(char* text);

node* getNode (char* text);


