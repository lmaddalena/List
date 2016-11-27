CC = gcc

CFLAGS = -std=c99 -g
ODIR = bin
PROG = test.out

all: test.o list.o
	$(CC) $(LDFLAGS) $(ODIR)/*.o -o $(ODIR)/$(PROG)

test.o: test.c list.h
	$(CC) $(CFLAGS) -c test.c -o $(ODIR)/test.o

list.o : list.h list.c
	$(CC) $(CFLAGS) -c list.c -o $(ODIR)/list.o

clean:
	rm -f $(ODIR)/$(PROG) $(ODIR)/*.o

