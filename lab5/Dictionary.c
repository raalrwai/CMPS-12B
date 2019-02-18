//Rami Alrwais
//raalrwai
//cmps12b
//5/11/16
//lab5
//Dictionary.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"
//objectnode

typedef struct NodeObj{
  char* key;
  char* value;
  struct NodeObj* next;
} NodeObj;
//node declaration
typedef NodeObj* Node;
//constructor for node type
//which is a new node
Node newNode(char* k, char* v){
  Node N = malloc(sizeof(NodeObj));
  assert(N!=NULL);
  N->key = k;
  N->value = v;
  N->next = NULL;
  return(N);
}
//this function free node and is a destructor
//for node type
void freeNode(Node* pN){
  if(pN!=NULL && *pN!=NULL ){
    free(*pN);
    *pN = NULL;
  }
}
//function dictionaryJob
typedef struct DictionaryObj{
  Node front;
  Node back;
  int numofItems;
} DictionaryObj;
//function newDictionary which is constructor for dictionary type
Dictionary newDictionary(void){
  Dictionary D = malloc(sizeof(DictionaryObj));
  assert(D != NULL);
  D->front = NULL;
  D->back = NULL;
  D->numofItems = 0;
  return D;
}
//destructor for the dictionary type
void freeDictionary(Dictionary* pD){
  if( pD!=NULL && *pD!=NULL){
    if( !isEmpty(*pD) )makeEmpty(*pD);
    free(*pD);
    *pD = NULL;
  }
}
//returns true if empty false otherwise
int isEmpty(Dictionary D){
  if( D ==NULL ){
    fprintf(stderr, "DictionaryError: calling isEmpty() on NULL Dictionary reference\n");      exit(EXIT_FAILURE);
  }
  if(D->numofItems>0){
    return 0;
  }
  return 1;
}

int size(Dictionary D){
  return D->numofItems;
}

char* lookup(Dictionary D, char* k){
  Node N = D->front;
  if( D == NULL ){
    fprintf(stderr, "Dictionary Error: calling lookup() on NULL Dictionary\n");
    exit(EXIT_FAILURE);
  }
  while(N != NULL){
    if(strcmp(N->key,k)== 0)
      return N->value;
    N = N->next;
  }
  return NULL;;
}
//function inserts a new pair
void insert(Dictionary D, char* k, char* v){
  if(D->numofItems == 0){
    D->front = D->back = newNode(k, v);
  }else{
    Node N;
    N = newNode(k, v);
    D->back->next = N;
    D->back = N;
  }
  D->numofItems++;
}
//functin Makempty resets D to empty
void makeEmpty(Dictionary D){
  D->front = NULL;
  D->back = NULL;
  D->numofItems = 0;
}
//function delete, deletes a pair with the key k

void delete(Dictionary D, char* k){
  Node N = D->front;
  if( lookup(D,k) == NULL ){
    fprintf(stderr, "Dictionary error: key not found\n");
    exit(EXIT_FAILURE);
  }
  if(strcmp(N->key,k)==0){
    Node P = D->front;
    Node G = P->next;
    D->front = G;
    freeNode(&P);
  }else{
    while(N !=NULL && N->next != NULL){
      if(strcmp(N->next->key, k)==0){
        Node G = N;
        Node C = N->next;
        G->next = C->next;
        N=G;
        freeNode(&C);
      }
      N = N->next;
    }
  }
  D->numofItems--;
}
//prints a text of D by out
void printDictionary(FILE* out, Dictionary D){
  Node N;
  if( D==NULL ){
    fprintf(stderr, "Dictionary Error: calling printDictionary() on NULL Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  for(N=D->front; N!=NULL; N=N->next) fprintf(out, "%s %s \n" , N->key, N->value);
  fprintf(out, "\n");
}
