## A simple makefile
CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic
BINDIR = ~/swdev/c/cpama/bin
PROG = justify

$(PROG): justify.o word.o  line.o
	$(CC) $(CFLAGS) -o $(BINDIR)/$(PROG) justify.o word.o line.o

justify.o: justify.c word.h line.h
	$(CC) $(CFLAGS) -c justify.c

word.o: word.c word.h
	$(CC) $(CFLAGS) -c word.c

line.o: line.c line.h
	$(CC) $(CFLAGS) -c line.c

