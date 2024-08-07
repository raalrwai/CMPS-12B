
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
  Dictionary A = newDictionary();
  FILE* in = fopen("DictionaryClient2.c", "r");
  FILE* out = fopen("DictionaryClient2-out", "w");
  char* key;
  char* value;
  char* keyBuffer = NULL;
  char* valBuffer = NULL;
  int keyBufferOffset = 0, valBufferOffset = 0;
  int keyBufferLength = 0, valBufferLength = 0;
  char line[MAX_LEN+1];
  char label[MAX_LEN+1];
  int i, labelLength, lineLength, lineNumber = 0;

  //read input files
    while( fgets(line, MAX_LEN, in)!=NULL ){

      // put line in valBuffer
      lineNumber++;
      lineLength = strlen(line)-1;
      line[lineLength] = '\0';  // overwrite newline '\n' with null '\0'
      valBufferLength += (lineLength+1);
      valBuffer = realloc(valBuffer, valBufferLength*sizeof(char) );
      value = &valBuffer[valBufferOffset];
      strcpy(value, line);
      valBufferOffset = valBufferLength;

      // put label in keyBuffer
      sprintf(label, "line %d:\t", lineNumber);
      labelLength = strlen(label);
      keyBufferLength += (labelLength+1);
      keyBuffer = realloc(keyBuffer, keyBufferLength*sizeof(char) );                                                                                                          key = &keyBuffer[keyBufferOffset];
      strcpy(key, label);
      keyBufferOffset = keyBufferLength;
    }

  // put keys and values in dictionary A
  keyBufferOffset = valBufferOffset = 0;
  for(i=0; i<lineNumber; i++){
    key = &keyBuffer[keyBufferOffset];
    value = &valBuffer[valBufferOffset];
    insert(A, key, value);
    keyBufferOffset += (strlen(key) + 1);
    valBufferOffset += (strlen(value) + 1);
  } 

  printDictionary(out, A);

  // free memory and close files
  freeDictionary(&A);
  free(keyBuffer);
  free(valBuffer);
  fclose(in);
  fclose(out);

  return(EXIT_SUCCESS);
}
