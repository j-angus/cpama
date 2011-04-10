## A simple makefile

CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic

## Programming Name and Source file
## Change BASE name depending on file you're working on.
BASE = ch09pp04
PROG = $(BASE)~
SRC = $(BASE).c

## Object files have the same name name as .c files, but with .o
OBJS = $(SRC:.c=.o)

## Default rule
## compile program from source file
$(PROG) : $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(SRC)

## Remove all compilation and debugging files
clean:
	rm -f core $(PROG) $(OBJS)
