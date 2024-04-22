# Variable
CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c11 $(DEBUG) -c
LFLAGS = -Wall -std=c11 $(DEBUG)
#TEST = -DTEST_MODE

#default target
all: Chess test_rulecheck test_boarddisplay
test: test_rulecheck test_boarddisplay
clean:
	rm -f Chess
	rm -f test_rulecheck
	rm -f *.o
	rm -f test_boarddisplay


#specific target
rules.o: rules.c rules.h struct.h
	$(CC) $(CFLAGS) rules.c -o rules.o



chess.o: chess.c rules.h struct.h
	$(CC) $(CFLAGS) chess.c -o chess.o
test_rulecheck.o: test_rulecheck.c rules.h struct.h
	$(CC) $(CFLAGS) test_rulecheck.c -o test_rulecheck.o
test_boarddisplay.o: test_boarddisplay.c rules.h struct.h
	$(CC) $(CFLAGS) test_boarddisplay.c -o test_boarddisplay.o




Chess: chess.o rules.o
	$(CC) $(LFLAGS)  chess.o rules.o -o Chess


test_rulecheck: test_rulecheck.o rules.o
	$(CC) $(LFLAGS)  test_rulecheck.o rules.o -o test_rulecheck

test_boarddisplay: test_boarddisplay.o rules.o
	$(CC) $(LFLAGS)  test_boarddisplay.o rules.o -o test_boarddisplay

