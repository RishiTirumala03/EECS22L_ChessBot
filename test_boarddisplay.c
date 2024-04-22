#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "rules.h"
#include <ctype.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {

    
    	
	printf("This is Testing mode\n");
	freopen("input_TEST.txt", "r", stdin);
	
    
    struct Square board[8][8];
    struct Square backupBoard[8][8];
    initializeBoard(board);
    printBoard(board);
    printf("\nWelcome to Chess! Currently, there is only a 2 person option for playing.\n");
    printf("White pieces will be specified with upper case characters,\nwhile black pieces will be specified with lower case characters.\n");
    printf("Move notation will be specified by starting square then destination square (ex. a2a4)\n");
    bool checkMate = false;
    struct Move *move1 = malloc(sizeof(struct Move));
    int currColor = 0;
    char redoChoice[10]; // Buffer for redo input
    int exit_V = 0;

    while(!checkMate){
        if(isStalemate(board, currColor)) {
            printf("Stalemate! Ending Game.\n");
            break;
        }

        deepCopyBoard(board, backupBoard); // Backup the board before the move

        if(possibleCheck(board, currColor)){ // First check for check
            printf("Player is in Check!\n");
            if(!canEscapeCheck(board, currColor)){ // No escape; game over
                printf("Checkmate!! Game Over!\n");
                checkMate = true;
                break;
            }
            else{
                bool check = false;
                while(!check){
                    printBoard(board);
                    getPlayerMove(move1);
                    if(outOfCheck(board, move1, currColor)){ // Test if player move removes check
                        makeMove(board, move1, currColor);
                        printBoard(board);
                        printf("Do you want to redo this move? (yes/no): ");
                        fgets(redoChoice, sizeof(redoChoice), stdin);
                        redoChoice[strcspn(redoChoice, "\n")] = '\0'; // Remove newline character
			redoChoice[strcspn(redoChoice, "\r")] = '\0';
                        if (strcmp(redoChoice, "yes") == 0) {
                            deepCopyBoard(backupBoard, board); // Restore the backup
                            printf("Redoing the move...\n");
                            printBoard(board);
                            continue; // Skip changing the player
                        }
			if (strcmp(redoChoice,"exit")==0){
                           exit_V = 1;
			   printf("exiting..\n");
      			   break;
			}
                        check = true;
                    }
                    else{
                        printf("Try again!\n"); // Redo loop if not out of check
                    }
                }
            }
        }
        else{
            bool invalidMove = false;
            while(!invalidMove){
                getPlayerMove(move1);
                if(isValidMove(board, move1, currColor)){
                    makeMove(board, move1, currColor);
                    printBoard(board);
                    printf("Do you want to redo this move? (yes/no): ");
                    fgets(redoChoice, sizeof(redoChoice), stdin);
                    redoChoice[strcspn(redoChoice, "\n")] = '\0'; // Remove newline character
			redoChoice[strcspn(redoChoice, "\r")] = '\0'; // Remove newline character

                    if (strcmp(redoChoice, "yes") == 0) {
                        deepCopyBoard(backupBoard, board); // Restore the backup
                        printf("Redoing the move...\n");
                        printBoard(board);
                        continue; // Skip changing the player
                    }
                   if (strcmp(redoChoice,"exit")==0){
                           exit_V = 1;
                           printf("exiting..\n");
                           break;
                        }

                   invalidMove = true;
                }
                else{
                    printf("Invalid Move! Try again!\n");
                }
            }
        }
        if(exit_V==1){
		break;
	}
        currColor = 1 - currColor; // Switch player after a valid move
    }


   
	return 0;
}

