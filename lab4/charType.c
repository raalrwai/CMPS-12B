//Rami Alrwais
//raalrwai
//cmps12b
//lab4
//4/30/16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define Max_String_Length 100 //max string length

void extract_chars(char* s, char* a, char* d, char* p, char* w);
//extracts characters and places them in arrays
void extract_chars(char* s, char* a, char* d, char* p, char* w){
  int f=0, g=0, q=0, v=0, z=0;
  while (s[f] != '\0' && f<Max_String_Length){
    if( isupper((int)s[f])){
      a[g]=s[f];
      g++;
    }
    else if( isalpha((int)s[f])){
      a[g] =s[f];
      g++;
    }
    else if( isdigit((int)s[f])){
      d[q] = s[f];
      q++;
    }
    else if(ispunct((int)s[f])){
      p[v]=s[f];
      v++;
    }
    else{
      w[z]=s[f];
      z++;
    }
    f++;
  }

  //end of array has null char
  a[g] = '\0';
  d[q] = '\0';
  p[v] = '\0';
  w[z] = '\0';
}
int main(int argc, char* argv[]){
  FILE* in; //declares input
  FILE* out;//declares output
  char* number_characters;//declares variable line
  char* whitespace;//declares letter characters
  char* line;//declares number characters 
  char* punctuation_characters;//
  char* letters;
  int lineNum = 1; //line number


  //if input file is set to null then throw error message and exit
  in = fopen(argv[1], "r");
  if ( in==NULL ){
    printf("Unable to read from file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // if output file is set to null throw error message and exit
  out = fopen(argv[2], "w");
  if( out==NULL ){
    printf("Unable to write to file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  //exits if command line is not three 
  if( argc != 3){
    printf("Usage: %s input file output file\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  //memory is heaped to char arryas
  line = calloc(Max_String_Length + 1, sizeof(char));
  letters = calloc(Max_String_Length + 1, sizeof(char));
  number_characters = calloc(Max_String_Length + 1, sizeof(char));
  punctuation_characters = calloc(Max_String_Length + 1, sizeof(char));
  whitespace = calloc(Max_String_Length + 1, sizeof(char));
  assert( line != NULL && letters != NULL && number_characters != NULL && punctuation_characters != NULL && whitespace != NULL);

  // takes input file and prints array in each of its  character type 
  while ( fgets(line, Max_String_Length, in) != NULL){
    // calls function extract to take characaters from file in and
    // places them in respective arrays to be printed to out
    extract_chars(line, letters, number_characters, punctuation_characters, whitespace);
    fprintf(out, "line %d contains: \n", lineNum);
    //letters allocation
    if(strlen(letters)>1){
      fprintf(out, "%d letters: %s\n", (int)strlen(letters), letters);
    }
    else {
      fprintf(out, "%d word: %s\n", (int)strlen(letters), letters);
    }
    //number characters allocation
    if(strlen(number_characters)>1){
      fprintf(out, "%d number: %s\n", (int)strlen(number_characters), number_characters);
    }
    else {
      fprintf(out, "%d number: %s\n", (int)strlen(number_characters), number_characters);
    }
    //punctuation characters allocation
    if(strlen(punctuation_characters)>1){
      fprintf(out, "%d punctuation: %s\n", (int)strlen(punctuation_characters), punctuation_characters);
    }
    else {
      fprintf(out, "%d punctuation: %s\n", (int)strlen(punctuation_characters), punctuation_characters);
    }
    //whitespace allocation
    if(strlen(whitespace)>1){
      fprintf(out, "%d white space: %s\n", (int)strlen(whitespace), whitespace);
    }
    else {
      fprintf(out, "%d white space: %s\n", (int)strlen(whitespace), whitespace);
    }
    //line number is incremented
    lineNum++;
  }

  //free memory of allocated heap
  free(line);
  free(letters);
  free(number_characters);
  free(punctuation_characters);
  free(whitespace);            
  fclose(in);//closes both files in and out
  fclose(out);

  return EXIT_SUCCESS;

}
