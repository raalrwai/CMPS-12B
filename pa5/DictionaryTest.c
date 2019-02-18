//Rami Alrwais
//raalrwai
//cmps12b
//pa5
//DictionaryTest.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
  Dictionary A = newDictionary();
  char* u;
  char* w;
  char* case1[] = {"this","is","quite", "confusing"};
  char* case2[] = {"one","two","three", "four"};
  int i;
  for(i=0; i<4; i++){
    insert(A, case1[i], case2[i]);
  }
  printDictionary(stdout, A);
  for(i=0; i<4; i++){
    u = case1[i];
    w = lookup(A, k);
    printf("key=\"%s\" %s\"%s\"\n", u, (w==NULL?"not found ":"value="), w);
  }
  delete(A, "one");
  delete(A, "three");
  printDictionary(stdout, A);
  for(i=0; i<4; i++){
    u = case1[i];
    w = lookup(A, u);
    printf("key=\"%s\" %s\"%s\"\n", u, (w==NULL?"not found ":"value="), w);
    printf("%s\n", (isEmpty(A)?"true":"false"));
    printf("%d\n", size(A));
    makeEmpty(A);
    printf("%s\n", (isEmpty(A)?"true":"false"));
    freeDictionary(&A);
    return(EXIT_SUCCESS);
  }
}
