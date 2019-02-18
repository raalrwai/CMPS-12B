//Rami ALrwais
//raalrwai
//cmps12b
//pa5
//Dictionary.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"
#define MAX_LEN 180
const int tableSize = 101;
// rotate the bits in an unsigned int
unsigned int rotate_left(unsigned int value, int shift) {
  int bitSize = 8*sizeof(unsigned int);
  shift = shift & (bitSize - 1);
  if ( shift == 0 )
    return value;
  return (value << shift) | (value >> (bitSize - shift));
}
// turn a string into an unsigned int
unsigned int pre_hash(char* input) {
  unsigned int answer = 0xBAE86554;
  while (*input) {
    answer ^= *input++;
    answer = rotate_left(answer, 5);
  }
  return answer;
}
// hash()
// turns a string into an int in the range 0 to tableSize-1
int hash(char* key){
  return pre_hash(key)%tableSize;
}
//Private types----------------------------------
//NodeObj
typedef struct NodeObj{
  char* key;
  char* value;
  struct NodeObj* next;
}
NodeObj;
//Node
typedef NodeObj* Node;
//newNode() constructor for the Node type
Node newNode(char*o, char* u){
  Node N = malloc(sizeof(NodeObj));
  assert(N!=NULL);
  N->key = o;
  N->value = u;
  N->next = NULL;
  return(N);
}
//freeNode() destructor for the Node type
void freeNode(Node* pN){
  if(pN!=NULL && *pN!=NULL){
    free(*pN);
    *pN = NULL;
  }
}
//ListObj
typedef struct ListObj{
  Node head;
} ListObj;
//List
typedef ListObj* List;
//newList() constructor for the Node type
List newList(void){
  List W = malloc(sizeof(ListObj));
  assert(W!=NULL);
  W->head = NULL;
  return W;
}
//DictionaryObj
typedef struct DictionaryObj{
  List table;
  int numofItems;
} DictionaryObj;
//returns a reference to the NodeObj containing its respective key
//returns null if no such Node exists
Node findKey(Node H, char* targetKey){
  while(H!=NULL){
    if(strcmp(H->key, targetKey)==0){
      break;
    } H = H->next;
  } return H;
}
//deleteAll
void deleteAll(Node N){
  if(N!=NULL){
    deleteAll(N->next);
    freeNode(&N);
  }
}
// newDictionary()
// constructor for the Dictionary type
Dictionary newDictionary(void){
  Dictionary D = malloc(sizeof(DictionaryObj));
  assert(D!=NULL);
  D->table = calloc(tableSize, sizeof(ListObj));
  D->numofItems = 0;
  return D;
}
// freeDictionary()
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD){
  if(pD!=NULL && *pD!=NULL){
    if(!isEmpty(*pD)) makeEmpty(*pD);
    free(*pD);
    *pD = NULL;
  }
}
// returns 1 (true) if S is empty, 0 (false) otherwise
// pre: none
int isEmpty(Dictionary D){
  if(D==NULL){
    fprintf(stderr, "DICTIONARY ERROR: calling isEmpty() on invalid Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  return(D->numofItems==0);
}
// returns the number of (key, value) pairs in D
// pre: none
int size(Dictionary D){
  return D->numofItems;
}
// returns the value v such that (k, v) is in D, or returns NULL if no
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k){
  int tableIndex;
  Node N;
  List W;
  tableIndex = hash(k);
  W = &D->table[tableIndex];
  N = findKey(W->head, k);
  if(N==NULL){
    return NULL;
  }
  else{
    return N->value;
  }
}
// insert()
/// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* k, char* v){
  Node N;
  List W;
  int tableIndex;
  tableIndex = hash(k);
  N = newNode(k,v);
  W = &D->table[tableIndex];
  if(findKey(W->head,k)!=NULL){
    fprintf(stderr, "DICTIONARY ERROR: calling insert() on an existing key\n");
    exit(EXIT_FAILURE);
  }
  N->next = W->head;
  W->head = N;
  N = NULL;
  D->numofItems++;
}
// delete()
// deletes pair with the key k
// pre: lookup(D, k)!=NULL
void delete(Dictionary D, char* k){
  if(D==NULL){
    fprintf(stderr, "DICTIONARY ERROR: calling delete() on an invalid Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  Node N;
  List W;
  int tableIndex;
  tableIndex = hash(k);
  W = &D->table[tableIndex];
  if(findKey(W->head, k)==W->head){
    N = W->head;
    W->head = W->head->next;
    N->next = NULL;
  } else{
    N = findKey(W->head,k);
    Node prev = W->head;
    Node temp = W->head->next;
    while(temp != N){
      temp = temp->next;
      prev = prev->next;
    }
    prev->next = N->next;
    N->next = NULL;
  }
  D->numofItems--;
  freeNode(&N);
}
// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D){
  List W;
  if(D==NULL){
    fprintf(stderr, "DICTIONARY ERROR: calling makeEmpty() on an invalid Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  if(D->numofItems==0){
    fprintf(stderr, "DICTIONARY ERROR: calling makeEmpty() on an empty Dictionary\n");
    exit(EXIT_FAILURE);
  }
  for(int i=0; i<tableSize; i++){
    W = &D->table[i];
    deleteAll(W->head);
  }
  D->table = NULL;
  D->numofItems = 0;
}
// printDictionary()
// pre: none
// prints a text representation of D to the file pointed to by out
void printDictionary(FILE* out, Dictionary D){
  if(D==NULL){
    fprintf(stderr, "DICTIONARY ERROR: calling printDictionary() on an invalid Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  Node N;
  List W;
  for(int i=0; i<tableSize; i++){
    W = &D->table[i];
    N = W->head;
    while(N!=NULL){
      fprintf(out, "%s %s\n", N->key, N->value);
      N = N->next;
    }
  }
}
