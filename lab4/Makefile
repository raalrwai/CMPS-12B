#Rami ALrwais
#raalrwai
#cmps12b
#makefile for lab4
FLAGS = -std=c99 -Wall
SOURCES = charType.c
OBJECTS = charType.o
EXEBIN = charType

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm $(EXEBIN) $(OBJECTS)
	
submit: README Makefile charType.c
	submit cmps012b-pt.s16 lab4 README Makefile charType.c

check:
	valgrind --leak-check=full charType charType.c out
