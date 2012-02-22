CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OBJECTS=$(SOURCES:.cpp=.o)

all: roller
	
roller: roller.c
	$(CC) $(LDFLAGS) roller.c -o $@
