#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"
#define MAX_LEN 180
const int tableSize = 101;
//Hash functions---------------------------------
// rotate_left()
// rotate the bits in an unsigned int
unsigned int rotate_left(unsigned int value, int shift) {
int sizeInBits = 8*sizeof(unsigned int);
shift = shift & (sizeInBits - 1);
if ( shift == 0 )
return value;
return (value << shift) | (value >> (sizeInBits - shift));
}
// pre_hash()
// turn a string into an unsigned int
unsigned int pre_hash(char* input) {
unsigned int result = 0xBAE86554;
while (*input) {
result ^= *input++;
result = rotate_left(result, 5);
}
return result;
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
} NodeObj;
//Node
typedef NodeObj* Node;
//newNode() constructor for the Node type
Node newNode(char*k, char* v){
Node N = malloc(sizeof(NodeObj));
assert(N!=NULL);
N->key = k;
N->value = v;
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
List L = malloc(sizeof(ListObj));
assert(L!=NULL);
L->head = NULL;
return L;
}
//DictionaryObj
typedef struct DictionaryObj{
List table;
int numItems;
} DictionaryObj;
//Private helper functions-----------------------
//findKey()
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
//Public functions-------------------------------
// newDictionary()
// constructor for the Dictionary type
Dictionary newDictionary(void){
Dictionary D = malloc(sizeof(DictionaryObj));
assert(D!=NULL);
D->table = calloc(tableSize, sizeof(ListObj));
D->numItems = 0;
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
// isEmpty()
// returns 1 (true) if S is empty, 0 (false) otherwise
// pre: none
int isEmpty(Dictionary D){
if(D==NULL){
fprintf(stderr, "DICTIONARY ERROR: calling isEmpty() on invalid Dictionary reference\n");
exit(EXIT_FAILURE);
}
return(D->numItems==0);
}
// size()
// returns the number of (key, value) pairs in D
// pre: none
int size(Dictionary D){
return D->numItems;
}
// lookup()
// returns the value v such that (k, v) is in D, or returns NULL if no
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k){
int tableIndex;
Node N;
List L;
tableIndex = hash(k);
L = &D->table[tableIndex];
N = findKey(L->head, k);
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
List L;
int tableIndex;
tableIndex = hash(k);
N = newNode(k,v);
L = &D->table[tableIndex];
if(findKey(L->head,k)!=NULL){
fprintf(stderr, "DICTIONARY ERROR: calling insert() on an existing key\n");
exit(EXIT_FAILURE);
}
N->next = L->head;
L->head = N;
N = NULL;
D->numItems++;
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
List L;
int tableIndex;
tableIndex = hash(k);
L = &D->table[tableIndex];
if(findKey(L->head, k)==L->head){
N = L->head;
L->head = L->head->next;
N->next = NULL;
} else{
N = findKey(L->head,k);
Node prev = L->head;
Node temp = L->head->next;
while(temp != N){
temp = temp->next;
prev = prev->next;
}
prev->next = N->next;
N->next = NULL;
}
D->numItems--;
freeNode(&N);
}
// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D){
List L;
if(D==NULL){
fprintf(stderr, "DICTIONARY ERROR: calling makeEmpty() on an invalid Dictionary reference\n");
exit(EXIT_FAILURE);
}
if(D->numItems==0){
fprintf(stderr, "DICTIONARY ERROR: calling makeEmpty() on an empty Dictionary\n");
exit(EXIT_FAILURE);
}
for(int i=0; i<tableSize; i++){
L = &D->table[i];
deleteAll(L->head);
}
D->table = NULL;
D->numItems = 0;
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
List L;
for(int i=0; i<tableSize; i++){
L = &D->table[i];
N = L->head;
while(N!=NULL){
fprintf(out, "%s %s\n", N->key, N->value);
N = N->next;
}
}
}
