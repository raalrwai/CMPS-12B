#Rami Alrwais
#raalrwai
#5/22/16
#cmps12b
#pa5
FLAGS   = -std=c99 -Wall
SOURCES = Dictionary.c DictionaryClient.c
OBJECTS = Dictionary.o DictionaryClient.o
HEADERS = Dictionary.h
EXEBIN  = DictionaryClient

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
		gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
		gcc -c $(FLAGS) $(SOURCES)

clean :
		rm -f $(EXEBIN) $(OBJECTS)

check:
		valgrind --leak-check=full $(EXEBIN) 
submit: Dictionary.c Dictionary.h DictionaryTest.c DictionaryClient.c Makefile
		submit cmps012b-pt.s16 pa5 Dictionary.c Dictionary.h DictionaryTest.c DictionaryClient.c Makefile
