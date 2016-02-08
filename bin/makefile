test: test.o list.o
	gcc -std=c99 test.o list.o -o test

test.o: ../test.c ../list.h
	gcc -std=c99 -c ../test.c

list.o : ../list.h ../list.c
	gcc -std=c99 -c ../list.c
