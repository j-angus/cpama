
CC = gcc
CFLAGS = -g -Wall -std=gnu99 -pedantic

ch17pp04: ch17pp04.o word.o  line.o
	$(CC) $(CFLAGS) -o ../../bin/ch17pp04 ch17pp04.o word.o line.o

ch17pp04.o: ch17pp04.c word.h line.h
	$(CC) $(CFLAGS) -c ch17pp04.c

word.o: word.c word.h
	$(CC) $(CFLAGS) -c word.c

line.o: line.c line.h
	$(CC) $(CFLAGS) -c line.c

