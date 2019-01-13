CC=gcc
CFLAGS=-c -Wall
all: div mul rakam myshell
div: div.c
	$(CC) div.c -o div
mul: mul.c
	$(CC) mul.c -o mul
rakam: rakam.c
	$(CC) rakam.c -o rakam
myshell: myshell.c
	$(CC) myshell.c -o myshell						
clean: rm -rf *o myshell		
