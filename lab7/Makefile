#a simple Makefile for lab7
JAVAC      = javac 
MAINCLASS  = DictionaryClient
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) Makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 


all: $(JARFILE)

$(JARFILE): $(CLASSES)
		echo Main-class: $(MAINCLASS) > Manifest
			jar cvfm $(JARFILE) Manifest $(JARCLASSES)
				chmod +x $(JARFILE)
					rm Manifest

%.class: %.java
		$(JAVAC) $<

clean:
		rm -f *.class $(JARFILE)
submit: Dictionary.java Makefile README DictionaryInterface.java DuplicateKeyException.java KeyNotFoundException.java DictionaryClient.java
	submit cmps012b-pt.s16 lab7 Dictionary.java Makefile README DictionaryInterface.java DuplicateKeyException.java KeyNotFoundException.java DictionaryClient.java

