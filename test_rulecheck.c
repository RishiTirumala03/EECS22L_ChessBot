#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "rules.h"
#include <ctype.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {

/**
	char input_string[100][10];
	strcpy(input_string[0],"a2a4");
	strcpy(input_string[1],"no");
	strcpy(input_string[2],"back");
**/
	printf("testing chess program rule with a classic chess game.\n");
	int counter = 0;
	char input_string[100][10];
	counter = addMove(input_string,counter,"e2e4");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"e7e5");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"d2d4");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"d7d6");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"f2f4");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"e5f4");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"e4e5");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"g8f6");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"f1d3");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"d6e5");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"d3e4");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"f6e4");
	counter = addMove(input_string,counter,"no");
	counter = addMove(input_string,counter,"back");
	startGame_TEST(0,input_string);

    return 0;

    
}
