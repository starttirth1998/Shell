
CC = gcc

CFLAGS = -c

all: shell

shell: *.o
	$(CC) *.o -o shell

*.o: *.c
	$(CC) $(CFLAGS) -c *.c
