#
# Generic Makefile to compile an executable
# (Ben Nakash, I.D: 303140057)
#

# our compiler
CC=gcc

# compile arguments
CFLAGS+=-c -g -Wall

# linker flags
LDFLAGS+=

# libraries
LIBS+=-lncurses

# our source files
SOURCES=main.c shapes.c rectangle.c trapeze.c triangle.c circle.c rhombus.c

# a macro to define the objects from sources
OBJECTS=$(SOURCES:.c=.o)

# executable name
EXECUTABLE=test

$(EXECUTABLE): $(OBJECTS)
	@echo "Building target" $@ "..."
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

# a rule for generating object files given their c files
.c.o:
	@echo "Compiling" $< "..."
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *s *o $(EXECUTABLE)

.PHONY: all clean
