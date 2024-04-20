# Variable
CC = gcc
DEBUG = -g
#DEBUG = -O2
CFLAGS = -Wall -std=c11 $(DEBUG) -c
LFLAGS = -Wall -std=c11 $(DEBUG)
Mathlib = -lm

#default target
all: ChessGPT
clean:
	rm -f ChessGPT
	rm -f *.o

#Target for ChessGPT

game.o: game.c game.h struct.h
	$(CC) $(CFLAGS) game.c -o game.o
chess.o: chess.c game.h struct.h
	$(CC) $(CFLAGS) chess.c -o chess.o


ChessGPT: chess.o game.o
	$(CC) $(LFLAGS)  chess.o game.o -o ChessGPT
