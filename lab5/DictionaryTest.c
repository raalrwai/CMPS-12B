//Rami ALrwais
//raalrwai
//!2b
//5/11/16
//DictionaryTest.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAXIMUM_LENGTH 180

int main(int argc, char* argv[]){
  Dictionary A = newDictionary();
  char* f;
  char* g;
  char* word1[] = {"1","2","3","4"};
  char* word2[] = {"this","is","a","test"};
  int u;

  for(u=0; u<4; u++){
    insert(A, word1[u], word2[u]);
  }

  printDictionary(stdout, A);

  for(u=0; u<4; u++){
    f = word1[u];
    g = lookup(A, f);
    printf("key=\"%s\" %s\"%s\"\n", f, (g==NULL?"not found ":"value="), g);
  }

  delete(A, "1");
  delete(A, "3");

  printDictionary(stdout, A);

  for(u=0; u<4; u++){
    f = word1[u];
    g = lookup(A, f);
    printf("key=\"%s\" %s\"%s\"\n", f, (g==NULL?"not found ":"value="), g);
  }

  printf("%s\n", (isEmpty(A)?"true":"false"));
  printf("%d\n", size(A));
  makeEmpty(A);
  printf("%s\n", (isEmpty(A)?"true":"false"));

  freeDictionary(&A);

  return(EXIT_SUCCESS);
}
