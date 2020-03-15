CC = gcc
FLAGS = -Wall -g

all: main

main: main.o myBank.o
	$(CC) $(FLAGS) -o main main.o myBank.o

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c 

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c 

.PHONY: clean all

clean:
	rm -f *.o main
