
JAVAC      = javac
MAINCLASS  = Simulation
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
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
		rm *.class $(JARFILE)

submit: README Simulation.java QueueInterface.java QueueEmptyException.java Queue.java QueueTest.java Job.java Makefile
		submit cmps012b-pt.s16 pa4 README Simulation.java QueueInterface.java QueueEmptyException.java Queue.java QueueTest.java Job.java Makefile

