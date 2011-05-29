## Call make with FILE=filename as argument

CC = gcc
CFLAGS = -g -Wall -std=gnu99 -pedantic
FILE = filename

$(FILE): $(FILE).o ../lib/my_functions.o ../lib/stack.o
	$(CC) $(CFLAGS) -o ../bin/$(FILE) $(FILE).o ../lib/my_functions.o ../lib/stack.o

$(MAIN): $(MAIN).o ../lib/my_functions.o ../lib/stack.o
	$(CC) $(CFLAGS) -o ../bin/$(MAIN) $(MAIN).o ../lib/my_functions.o ../lib/stack.o

$(MAIN).o: $(MAIN).c ../lib/my_functions.h ../lib/stack.h
	$(CC) $(CFLAGS) -c $(MAIN).c

my_functions.o: ../lib/my_functions.c ../lib/my_functions.h
	$(CC) $(CFLAGS) -c ../lib/my_functions.c

stack.o: ../lib/stack.c ../lib/stack.h
	$(CC) $(CFLAGS) -c ../lib/stack.c


