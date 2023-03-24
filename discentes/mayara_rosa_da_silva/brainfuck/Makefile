CC=gcc
CFLAGS=-Wall
SRCDIR=src
SOURCES=$(wildcard $(SRCDIR)/*.c)
EXECUTABLE=brainfuck

.PHONY: all build clean run

all: build

build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

run: build
	./$(EXECUTABLE)
