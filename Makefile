# Variable
CC = gcc
DEBUG = -g
#DEBUG = -O2
CFLAGS = -Wall -std=c11 $(DEBUG) -c
LFLAGS = -Wall -std=c11 $(DEBUG)
Mathlib = -lm

#default target
all: Chess
clean:
	rm -f Chess

#Target for Chess
Chess: main.c ChessGPT.h
	$(CC) $(LFLAGS) main.c -o Chess
