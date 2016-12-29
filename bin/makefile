CC = gcc

CFLAGS = -std=c99 -g
LDFLAGS =
PROG = a.out

$(PROG): test.o list.o
	$(CC) $(LDFLAGS) *.o -o $(PROG)

test.o: ../test.c ../list.h
	$(CC) $(CFLAGS) -c ../test.c

list.o: ../list.c ../list.h
	$(CC) $(CFLAGS) -c ../list.c

all: $(PROG)

clean:
	rm -f $(PROG) *.o

