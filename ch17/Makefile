## Call make with MAIN:=filename as argument
CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic

$(MAIN): $(MAIN).o ../lib/my_functions.o
	$(CC) $(CFLAGS) -o ../bin/$(MAIN) $(MAIN).o ../lib/my_functions.o

$(MAIN).o: $(MAIN).c ../lib/my_functions.h
	$(CC) $(CFLAGS) -c $(MAIN).c

my_functions.o: ../lib/my_functions.c ../lib/my_functions.h
	$(CC) $(CFLAGS) -c ../lib/my_functions.c



