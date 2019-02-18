#a simple Makeifle for Dictionary.c
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
submit: Dictionary.c DictionaryClient.c Dictionary.h DictionaryTest.c README Makefile
		submit cmps012b-pt.s16 lab5 README Makefile Dictionary.c Dictionary.h DictionaryClient.c DictionaryTest.c 
