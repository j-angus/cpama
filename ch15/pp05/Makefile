## A simple makefile

CC = gcc
CFLAGS = -g -Wall -std=gnu99 -pedantic

ch15pp05: ch15pp05.o stack.o readline.o
	$(CC) $(CFLAGS) -o ../../bin/ch15pp05 ch15pp05.o stack.o readline.o

ch15pp05.o: ch15pp05.c stack.h
	$(CC) $(CFLAGS) -c ch15pp05.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c readline.c


