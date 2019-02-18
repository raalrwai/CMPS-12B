# Makefile for hello.c with macros

FLAGS   = -std=c99 -Wall
SOURCES = FileReverse.c
OBJECTS = FileReverse.o
EXEBIN  = FileReverse
all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)
clean :
	rm -f $(EXEBIN) $(OBJECTS))
submit : README Makefile FileReverse.c
	submit  cmps012b-pt.s16 lab3 Makefile FileReverse.c README
