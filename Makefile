# Variable
CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c11 $(DEBUG) -c
LFLAGS = -Wall -std=c11 $(DEBUG)
#TEST = -DTEST_MODE

#default target
all: Chess test_rulecheck
test: test_rulecheck
clean:
	rm -f Chess
	rm -f Test_rulecheck
	rm -f *.o


#specific target
rules.o: rules.c rules.h struct.h
	$(CC) $(CFLAGS) rules.c -o rules.o



chess.o: chess.c rules.h struct.h
	$(CC) $(CFLAGS) chess.c -o chess.o
test_rulecheck.o: test_rulecheck.c rules.h struct.h
	$(CC) $(CFLAGS) test_rulecheck.c -o test_rulecheck.o



Chess: chess.o rules.o
	$(CC) $(LFLAGS)  chess.o rules.o -o Chess


test_rulecheck: test_rulecheck.o rules.o
	$(CC) $(LFLAGS)  test_rulecheck.o rules.o -o Test_rulecheck
