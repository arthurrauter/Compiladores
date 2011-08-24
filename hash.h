typedef struct _node{
  char *text;
  int type;
  struct _node *next;
}node;

#define HASH_SIZE 997


void initHash();

int insertHash(char* text);

node* getNode (char* text);


