all:
	gcc -o work.pickle main.c list.c list.h

run:
	./work.pickle