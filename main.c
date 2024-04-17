#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChessGPT.h"
#include <ctype.h>
#include <stdbool.h>

//game menu
void printMenu(){
    printf("\t\t\t\tChess\n");
	printf("Main Menu:\n");
	printf("\t1. Start Game\n");
	printf("\t2. Log file\n");
	printf("\t3. Rules of Chess\n");
	printf("\t4. Exit program\n");
	printf("Enter an option: ");
}

//start game
void subMenu(){
    //the sub-menu before entering the game

    int chooseMode;// 1 for pvp, 2 for pve
    int chooseColor;// 1 for white, 2 for black **implement later
    



}


void initializeBoard(struct Square gameBoard[8][8]){
    // Set each square's position
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            gameBoard[i][j].currPiece = NULL;
            gameBoard[i][j].row = i;
            gameBoard[i][j].col = j;
        }
    }
    
    for(int i = 0;i<8;i++){
        struct Piece* bPawn = malloc(sizeof(struct Piece)); // Allocate memory
        gameBoard[1][i].currPiece = bPawn;
        gameBoard[1][i].currPiece->firstMove = true;
        gameBoard[1][i].currPiece->color = 1;
        gameBoard[1][i].currPiece->pieceType = 0;
        
        // Initialize first row of black pawns
    }
    for(int i = 0;i<8;i++){
        struct Piece* bPawn = malloc(sizeof(struct Piece)); // Allocate memory
        gameBoard[6][i].currPiece = bPawn;
        gameBoard[6][i].currPiece->firstMove = true;
        gameBoard[6][i].currPiece->color = 0;
        gameBoard[6][i].currPiece->pieceType = 0;
        
        // Initialize first row of black pawns
    }
    // initialize rooks
    struct Piece* bRook1 = malloc(sizeof(struct Piece));
    struct Piece* bRook2 = malloc(sizeof(struct Piece));
    struct Piece* wRook1 = malloc(sizeof(struct Piece));
    struct Piece* wRook2 = malloc(sizeof(struct Piece));
    bRook1->color = 1;
    bRook1->pieceType = 1;
    bRook1->firstMove = true;
    bRook2->color = 1;
    bRook2->pieceType = 1;
    bRook2->firstMove = true;
    wRook1->color = 0;
    wRook1->pieceType = 1;
    wRook1->firstMove = true;
    wRook2->color = 0;
    wRook2->pieceType = 1;
    wRook2->firstMove = true;
    gameBoard[0][0].currPiece = bRook1;
    gameBoard[0][7].currPiece = bRook2;
    gameBoard[7][0].currPiece = wRook1;
    gameBoard[7][7].currPiece = wRook2;
    //TODO make into function
    //initialize bishops
    struct Piece* bBish1 = malloc(sizeof(struct Piece));
    struct Piece* bBish2 = malloc(sizeof(struct Piece));
    struct Piece* wBish1 = malloc(sizeof(struct Piece));
    struct Piece* wBish2 = malloc(sizeof(struct Piece));
    bBish1->color = 1;
    bBish1->pieceType = 2;
    bBish1->firstMove = true;
    bBish2->color = 1;
    bBish2->pieceType = 2;
    bBish2->firstMove = true;
    wBish1->color = 0;
    wBish1->pieceType = 2;
    wBish1->firstMove = true;
    wBish2->color = 0;
    wBish2->pieceType = 2;
    wBish2->firstMove = true;
    gameBoard[0][2].currPiece = bBish1;
    gameBoard[0][5].currPiece = bBish2;
    gameBoard[7][2].currPiece = wBish1;
    gameBoard[7][5].currPiece = wBish2;
    //TODO make into function
    //initialize knights
    struct Piece* bKnig1 = malloc(sizeof(struct Piece));
    struct Piece* bKnig2 = malloc(sizeof(struct Piece));
    struct Piece* wKnig1 = malloc(sizeof(struct Piece));
    struct Piece* wKnig2 = malloc(sizeof(struct Piece));
    bKnig1->color = 1;
    bKnig1->pieceType = 3;
    bKnig1->firstMove = true;
    bKnig2->color = 1;
    bKnig2->pieceType = 3;
    bKnig2->firstMove = true;
    wKnig1->color = 0;
    wKnig1->pieceType = 3;
    wKnig1->firstMove = true;
    wKnig2->color = 0;
    wKnig2->pieceType = 3;
    wKnig2->firstMove = true;
    gameBoard[0][1].currPiece = bKnig1;
    gameBoard[0][6].currPiece = bKnig2;
    gameBoard[7][1].currPiece = wKnig1;
    gameBoard[7][6].currPiece = wKnig2;
    //TODO make into function
    //initialize queens
    struct Piece * bQueen = malloc(sizeof(struct Piece));
    struct Piece * wQueen = malloc(sizeof(struct Piece));
    bQueen->color = 1;
    bQueen->pieceType = 4;
    bQueen->firstMove = true;
    wQueen->color = 0;
    wQueen->pieceType = 4;
    wQueen->firstMove = true;
    gameBoard[0][3].currPiece = bQueen;
    gameBoard[7][3].currPiece = wQueen;
    //TODO make into function
    //initialize kings
    struct Piece * bKing = malloc(sizeof(struct Piece));
    struct Piece * wKing = malloc(sizeof(struct Piece));
    bKing->color = 1;
    bKing->pieceType = 5;
    bKing->firstMove = true;
    wKing->color = 0;
    wKing->pieceType = 5;
    wKing->firstMove = true;
    gameBoard[0][4].currPiece = bKing;
    gameBoard[7][4].currPiece = wKing;
    //TODO make into function
}
void printBoard(struct Square gameBoard[8][8]) {
    // Column Labels
    printf("   a b c d e f g h\n");

    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i); // Row labels
        for (int j = 0; j < 8; j++) {
            struct Piece *piece = gameBoard[i][j].currPiece;
            char symbol = '.'; // Default to empty

            if (piece != NULL) {
                if (piece->color == 0) { // White
                    switch (piece->pieceType) {
                        case 0: symbol = 'P'; break;
                        case 1: symbol = 'R'; break;
                        case 2: symbol = 'B'; break;
                        case 3: symbol = 'H'; break;
                        case 4: symbol = 'Q'; break;
                        case 5: symbol = 'K'; break;
                    }
                } else { // Black
                    switch (piece->pieceType) {
                        case 0: symbol = 'p'; break;
                        case 1: symbol = 'r'; break;
                        case 2: symbol = 'b'; break;
                        case 3: symbol = 'h'; break;
                        case 4: symbol = 'q'; break;
                        case 5: symbol = 'k'; break;
                    }
                }
            }
            printf(" %c", symbol);
        }
        printf("\n");
    }
}
bool isValidMoveFormat(const char *input) {
    if (strlen(input) != 4) {
        printf("Invalid character! Try again! \n");
        return false; // Wrong length
    }

    // Check column letters
    if (input[0] < 'a' || input[0] > 'h' || input[2] < 'a' || input[2] > 'h') {
        printf("Invalid character! Try again! \n");
        return false;
    }

    // Check row numbers
    if (input[1] < '1' || input[1] > '8' || input[3] < '1' || input[3] > '8') {
        printf("Invalid character! Try again! \n");
        return false;
    }

    return true; // Within legal boundaries
}
void getPlayerMove(struct Move *move) {
    char input[10]; // Buffer for input string

    do {
        printf("Enter your move (e.g., e2e4): ");
        fgets(input, sizeof(input), stdin); //
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline, if present(i have no clue how it works stack exchange )
    } while (!isValidMoveFormat(input));

    // Assuming valid input, now parse into the move structure
    move->initialCol = input[0] - 'a';
    move->initialRow = '8' - input[1];
    move->destinationCol = input[2] - 'a';
    move->destinationRow = '8' - input[3];
}
bool isValidBishopMove(struct Square gameBoard[8][8], const struct Move *move) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;
    struct Piece *piece = gameBoard[startRow][startCol].currPiece;

    // Check if moving piece is a bishop
    if (piece == NULL || piece->pieceType != 2) {
        return false;
    }

    // Check if the move is diagonal
    if (abs(destRow - startRow) != abs(destCol - startCol) && !(destRow == startRow && destCol == startCol)) { // no staying in place
        return false;
    }

    // Check if the path is clear
    int rowDirection = (destRow > startRow) ? 1 : -1;
    int colDirection = (destCol > startCol) ? 1 : -1;

    // Check along the diagonal
    for (int i = startRow + rowDirection, j = startCol + colDirection;
         i != destRow;
         i += rowDirection, j += colDirection) {
        if (gameBoard[i][j].currPiece != NULL) {
            return false; // Path is blocked
        }
    }

    // Ensure destination square contains an opponent's piece or is empty
    return gameBoard[destRow][destCol].currPiece == NULL ||
           gameBoard[destRow][destCol].currPiece->color != piece->color;
}
bool isValidKnightMove(struct Square gameBoard[8][8], const struct Move *move) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;

    struct Piece *piece = gameBoard[startRow][startCol].currPiece;

    // Check if moving piece is a knight
    if (piece == NULL || piece->pieceType != 3) {
        return false;
    }

    // Check for valid L-shaped moves
    int rowDiff = abs(destRow - startRow);
    int colDiff = abs(destCol - startCol);

    if (!((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))) {
        return false; // Not a valid L-shape
    }

    // Ensure the target square is empty or contains an opponent's piece
    return gameBoard[destRow][destCol].currPiece == NULL ||
           gameBoard[destRow][destCol].currPiece->color != piece->color;
}
bool isValidRookMove(struct Square gameBoard[8][8], const struct Move *move) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;

    struct Piece *piece = gameBoard[startRow][startCol].currPiece;

    // Check if moving piece is a rook
    if (piece == NULL || piece->pieceType != 1) {
        return false;
    }

    // Check for horizontal or vertical movement
    if (startRow != destRow && startCol != destCol) {
        return false; // Not horizontal or vertical
    }

    // Check if path is clear
    if (startRow == destRow) { // Horizontal movement
        int colDir = (destCol > startCol) ? 1 : -1;
        for (int col = startCol + colDir; col != destCol; col += colDir) {
            if (gameBoard[startRow][col].currPiece != NULL) {
                return false; // Path is obstructed
            }
        }
    } else { // Vertical movement
        int rowDir = (destRow > startRow) ? 1 : -1;
        for (int row = startRow + rowDir; row != destRow; row += rowDir) {
            if (gameBoard[row][startCol].currPiece != NULL) {
                return false; // Path is obstructed
            }
        }
    }

    // Ensure the target square is empty or contains an opponent's piece
    return gameBoard[destRow][destCol].currPiece == NULL ||
           gameBoard[destRow][destCol].currPiece->color != piece->color;
}
bool isValidQueenMove(struct Square gameBoard[8][8], const struct Move *move) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;

    struct Piece *piece = gameBoard[startRow][startCol].currPiece;

    // Check if moving piece is a queen
    if (piece == NULL || piece->pieceType != 4) {
        return false;
    }

    // Check diagonal, horizontal, or vertical movement
    if (abs(destRow - startRow) != abs(destCol - startCol) &&
        startRow != destRow && startCol != destCol) {
        return false; // Invalid queen movement
    }

    // Check if path is clear (combines rook and bishop logic)
    int rowDir = (destRow > startRow) ? 1 : -1;
    int colDir = (destCol > startCol) ? 1 : -1;

    // Diagonal Checks
    if (abs(destRow - startRow) == abs(destCol - startCol)) {
        for (int i = startRow + rowDir, j = startCol + colDir;
               i != destRow;
               i += rowDir, j += colDir) {
            if (gameBoard[i][j].currPiece != NULL) {
                return false;
            }
        }
    } else if (startRow == destRow) { // Horizontal Movement
        for (int col = startCol + colDir; col != destCol; col += colDir) {
            if (gameBoard[startRow][col].currPiece != NULL) {
                return false;
            }
        }
    } else { // Vertical Movement
        for (int row = startRow + rowDir; row != destRow; row += rowDir) {
            if (gameBoard[row][startCol].currPiece != NULL) {
                return false;
            }
        }
    }

    // Ensure the target square is empty or contains an opponent's piece
    return gameBoard[destRow][destCol].currPiece == NULL ||
           gameBoard[destRow][destCol].currPiece->color != piece->color;
}

bool isValidPawnMove(struct Square gameBoard[8][8], const struct Move *move) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;

    struct Piece *piece = gameBoard[startRow][startCol].currPiece;

    // Ensure moving piece is a pawn
    if (piece == NULL || piece->pieceType != 0) {
        return false;
    }

    int direction = (piece->color == 0) ? -1 : 1; // (White: -1, Black: 1)

    // Normal forward moves
    if (destCol == startCol) {
        if (destRow == startRow + direction) {
            return gameBoard[destRow][destCol].currPiece == NULL; // One step
        } else if (destRow == startRow + 2 * direction && piece->firstMove)  {
            // Two steps on first move
            return gameBoard[startRow + direction][startCol].currPiece == NULL && // First step empty
                   gameBoard[destRow][destCol].currPiece == NULL;        // Destination empty
        }
    }

    // Diagonal capture
    if (abs(destCol - startCol) == 1 && destRow == startRow + direction) {
        return gameBoard[destRow][destCol].currPiece != NULL &&
               gameBoard[destRow][destCol].currPiece->color != piece->color; // Opponent piece
    }

    return false; // No valid move pattern
}

bool possibleCheck(struct Square gameBoard[8][8], int currColor){
    
    int kingRow, kingCol;
    // Find the king!!!!
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (gameBoard[i][j].currPiece != NULL && gameBoard[i][j].currPiece->color == currColor &&  gameBoard[i][j].currPiece->pieceType == 5) {
                kingRow = i;
                kingCol = j;
                break; // You can break out of the loop once the king is found
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            struct Piece *piece = gameBoard[i][j].currPiece;

            // Check for opponent's pieces
            if (piece != NULL && piece->color != currColor) {
                struct Move * move = malloc(sizeof(struct Move));
                move->initialRow = i;
                move->initialCol = j;
                move->destinationRow = kingRow;
                move->destinationCol = kingCol;
                if (isValidMove(gameBoard,move,piece->color)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool isValidCastle(struct Square gameBoard[8][8], const struct Move *move){
    int col = gameBoard[move->initialRow][move->initialCol].currPiece->color;
    if(possibleCheck(gameBoard,col)){
        
        return false;
    }
    if(!gameBoard[move->initialRow][move->initialCol].currPiece->firstMove){
        
        return false;
    }
    if((move->destinationCol - move->initialCol) > 0){
        struct Piece* rook = gameBoard[move->initialRow][7].currPiece;
        if(rook == NULL || (rook->pieceType != 1)){return false;}
        if(!rook->firstMove){return false;}
        struct Square tempBoard[8][8];
        deepCopyBoard(gameBoard,tempBoard);
        for(int i = move->initialCol+1;i<=move->destinationCol;i++){
            if(gameBoard[move->initialRow][i].currPiece != NULL){
                return false;}
        }
        for(int i = (move->initialCol+1);i<=move->destinationCol;i++){
            struct Move *tempMove = malloc(sizeof(struct Move));
            tempMove->initialRow = move->initialRow;
            tempMove->destinationRow = move->initialRow;
            tempMove->initialCol = i-1;
            tempMove->destinationCol = i;
            makeMove(tempBoard,tempMove,col);
            if(possibleCheck(tempBoard,col)){return false;}
        }
        return true;
    }
    else if((move->destinationCol - move->initialCol) < 0){
        struct Piece* rook = gameBoard[move->initialRow][0].currPiece;
        if(rook == NULL || (rook->pieceType != 1)){return false;}
        if(!rook->firstMove){return false;}
        struct Square tempBoard[8][8];
        deepCopyBoard(gameBoard,tempBoard);
        for(int i = move->initialCol-1;i<=move->destinationCol;i--){
            if(gameBoard[move->initialRow][i].currPiece != NULL){return false;}
        }
        for(int i = (move->initialCol-1);i<=move->destinationCol;i--){
            struct Move *tempMove = malloc(sizeof(struct Move));
            tempMove->initialRow = move->initialRow;
            tempMove->destinationRow = move->initialRow;
            tempMove->initialCol = i+1;
            tempMove->destinationCol = i;
            makeMove(tempBoard,tempMove,col);
            if(possibleCheck(tempBoard,col)){return false;}
        }
        return true;
    }
    return false;
}
bool isValidKingMove(struct Square gameBoard[8][8], const struct Move *move) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;
    struct Piece *piece = gameBoard[startRow][startCol].currPiece;

    // Check if moving piece is a king
    if (piece == NULL || piece->pieceType != 5) {
        return false;
    }

    // Check for basic one-square moves
    if (abs(destRow - startRow) <= 1 && abs(destCol - startCol) <= 1) {
        // Ensure the target square is empty or contains an opponent's piece
        return gameBoard[destRow][destCol].currPiece == NULL ||
               gameBoard[destRow][destCol].currPiece->color != piece->color;
    }

    // Check for castling
    if((abs(destRow - startRow)==0))
        if (isValidCastle(gameBoard, move)) {
            return true;
        }

    return false; // No other valid move patterns
}
bool isValidMove(struct Square gameBoard[8][8], const struct Move *move, int currColor) {
    if(move->initialRow < 0){return false;}
    if(move->initialCol < 0){return false;}
    if(move->destinationRow<0){return false;}
    if(move->destinationCol<0){return false;}
    if(move->initialRow > 7){return false;}
    if(move->initialCol > 7){return false;}
    if(move->destinationRow>7){return false;}
    if(move->destinationCol>7){return false;}
    
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    struct Square tempBoard[8][8];
    deepCopyBoard(gameBoard,tempBoard);
    tempBoard[move->destinationRow][move->destinationCol] = tempBoard[startRow][startCol];
    tempBoard[startRow][startCol].currPiece = NULL;
    if(possibleCheck(tempBoard,currColor)){return false;}
    struct Piece *piece = gameBoard[startRow][startCol].currPiece;
    if (piece == NULL) {
        return false; // No piece to move
    }
    if(currColor != piece->color){
        return false;
    }
    // Call specialized functions based on piece type
    switch (piece->pieceType) {
        case 0: return isValidPawnMove(gameBoard, move);
        case 1: return isValidRookMove(gameBoard, move);
        case 2: return isValidBishopMove(gameBoard, move);
        case 3: return isValidKnightMove(gameBoard, move);
        case 4: return isValidQueenMove(gameBoard, move);
        case 5: return isValidKingMove(gameBoard, move);
        default:{return false;} // Unknown piece type
    }
}
int getPromotionChoice() {
    int choice;
    do {
        printf("Promote your pawn to:\n");
        printf("0 - Pawn\n");
        printf("1 - Rook\n");
        printf("2 - Bishop\n");
        printf("3 - Knight\n");
        printf("4 - Queen\n");
        printf("Enter your choice (0-4): ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 4);

    return choice;
}
void makeMove(struct Square gameBoard[8][8], struct Move *move, int currColor) {
    int startRow = move->initialRow;
    int startCol = move->initialCol;
    int destRow = move->destinationRow;
    int destCol = move->destinationCol;
    
    // Ensure the move is valid before execution
    if (!isValidMove(gameBoard, move, currColor)) {
        printf("Invalid move.\n");
        return;
    }
    if(gameBoard[startRow][startCol].currPiece->pieceType == 5 &&
    gameBoard[startRow][startCol].currPiece->firstMove && abs(startCol-destCol) == 2
    && abs(destRow-startRow) == 0){// We can be sure that the user would like to castle
        if(startRow == 7){
            if(destCol>startCol){
                
                gameBoard[startRow][startCol].currPiece->firstMove = false;
                gameBoard[destRow][destCol].currPiece = gameBoard[startRow][startCol].currPiece;
                gameBoard[startRow][startCol].currPiece = NULL;
                gameBoard[7][7].currPiece->firstMove = false;
                gameBoard[7][5].currPiece = gameBoard[7][7].currPiece;
                gameBoard[7][7].currPiece = NULL;
            }
            else if(startCol>destCol){
                
                gameBoard[startRow][startCol].currPiece->firstMove = false;
                gameBoard[destRow][destCol].currPiece = gameBoard[startRow][startCol].currPiece;
                gameBoard[startRow][startCol].currPiece = NULL;
                gameBoard[7][0].currPiece->firstMove = false;
                gameBoard[7][3].currPiece = gameBoard[7][0].currPiece;
                gameBoard[7][0].currPiece = NULL;
            }
        }
        else if(startRow == 0){
           if(destCol>startCol){
                
                gameBoard[startRow][startCol].currPiece->firstMove = false;
                gameBoard[destRow][destCol].currPiece = gameBoard[startRow][startCol].currPiece;
                gameBoard[startRow][startCol].currPiece = NULL;
                gameBoard[0][7].currPiece->firstMove = false;
                gameBoard[0][5].currPiece = gameBoard[0][7].currPiece;
                gameBoard[0][7].currPiece = NULL;
            }
            else if(startCol>destCol){
                
                gameBoard[startRow][startCol].currPiece->firstMove = false;
                gameBoard[destRow][destCol].currPiece = gameBoard[startRow][startCol].currPiece;
                gameBoard[startRow][startCol].currPiece = NULL;
                gameBoard[0][0].currPiece->firstMove = false;
                gameBoard[0][3].currPiece = gameBoard[0][0].currPiece;
                gameBoard[0][0].currPiece = NULL;
            }
        }
    }
    else if((destRow == 7 || destRow == 0) && gameBoard[startRow][startCol].currPiece->pieceType == 0){
        int promo = getPromotionChoice();
        if(promo == 0){
            gameBoard[startRow][startCol].currPiece->firstMove = false;
            gameBoard[destRow][destCol].currPiece = gameBoard[startRow][startCol].currPiece;
            gameBoard[startRow][startCol].currPiece = NULL;
        }
        else if(promo == 1){
            struct Piece* newPiece = malloc(sizeof(struct Piece));
            newPiece->color = currColor;
            newPiece->pieceType = 1;
            newPiece->firstMove = false;
            gameBoard[destRow][destCol].currPiece = newPiece;
            gameBoard[startRow][destCol].currPiece = NULL;
        }
        else if(promo == 2){
            struct Piece* newPiece = malloc(sizeof(struct Piece));
            newPiece->color = currColor;
            newPiece->pieceType = 2;
            newPiece->firstMove = false;
            gameBoard[destRow][destCol].currPiece = newPiece;
            gameBoard[startRow][destCol].currPiece = NULL;
        }
        else if(promo == 3){
            struct Piece* newPiece = malloc(sizeof(struct Piece));
            newPiece->color = currColor;
            newPiece->pieceType = 3;
            newPiece->firstMove = false;
            gameBoard[destRow][destCol].currPiece = newPiece;
            gameBoard[startRow][destCol].currPiece = NULL;
        }
        else if(promo == 4){
            struct Piece* newPiece = malloc(sizeof(struct Piece));
            newPiece->color = currColor;
            newPiece->pieceType = 4;
            newPiece->firstMove = false;
            gameBoard[destRow][destCol].currPiece = newPiece;
            gameBoard[startRow][destCol].currPiece = NULL;
        }
    }
    else{
    // 1. Move the piece
        gameBoard[startRow][startCol].currPiece->firstMove = false;
        gameBoard[destRow][destCol].currPiece = gameBoard[startRow][startCol].currPiece;
        gameBoard[startRow][startCol].currPiece = NULL; // Clear original square
    }
    
}


void deepCopyBoard(struct Square gameBoard[8][8], struct Square gameBoardCopy[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            gameBoardCopy[i][j] = gameBoard[i][j];
            if (gameBoard[i][j].currPiece != NULL) {
                gameBoardCopy[i][j].currPiece = malloc(sizeof(struct Piece));
                *gameBoardCopy[i][j].currPiece = *gameBoard[i][j].currPiece; // Copy Piece data
            }
        }
    }
}
void generateRookMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    // Directions: Up, Right, Down, Left
    int rowDirections[] = { -1, 0, 1, 0 };
    int colDirections[] = { 0, 1, 0, -1 };

    for (int direction = 0; direction < 4; direction++) {
        int destRow = startRow + rowDirections[direction];
        int destCol = startCol + colDirections[direction];

        while (destRow >= 0 && destRow < 8 && destCol >= 0 && destCol < 8) {
            struct Move move;
            move.initialRow = startRow;
            move.initialCol = startCol;
            move.destinationRow = destRow;
            move.destinationCol = destCol;

            if (isValidMove(gameBoard, &move, currColor)) {
                moves[*numMoves] = move;
                (*numMoves)++;
            }

            // Check if path is blocked
            if (gameBoard[destRow][destCol].currPiece != NULL) {
                break; // Stop checking further in this direction
            }

            // Move to the next square in the direction
            destRow += rowDirections[direction];
            destCol += colDirections[direction];
        }
    }
}
void generateQueenMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    // Rook directions
    int rowDirections[] = { -1, 0, 1, 0 };
    int colDirections[] = { 0, 1, 0, -1 };

    // Bishop Directions
    int bishopRowDirections[] = { -1, 1, 1, -1 };
    int bishopColDirections[] = { 1, 1, -1, -1 };

    // Generate Rook-like moves
    for (int direction = 0; direction < 4; direction++) {
        int destRow = startRow + rowDirections[direction];
        int destCol = startCol + colDirections[direction];

        while (destRow >= 0 && destRow < 8 && destCol >= 0 && destCol < 8) {
            struct Move move;
            move.initialRow = startRow;
            move.initialCol = startCol;
            move.destinationRow = destRow;
            move.destinationCol = destCol;

            if (isValidMove(gameBoard, &move, currColor)) {
                moves[*numMoves] = move;
                (*numMoves)++;
            }

            if (gameBoard[destRow][destCol].currPiece != NULL) {
                break;
            }

            destRow += rowDirections[direction];
            destCol += colDirections[direction];
        }
    }

    // Generate Bishop-like moves
    for (int direction = 0; direction < 4; direction++) {
        int destRow = startRow + bishopRowDirections[direction];
        int destCol = startCol + bishopColDirections[direction];

        while (destRow >= 0 && destRow < 8 && destCol >= 0 && destCol < 8) {
            struct Move move;
            move.initialRow = startRow;
            move.initialCol = startCol;
            move.destinationRow = destRow;
            move.destinationCol = destCol;

            if (isValidMove(gameBoard, &move, currColor)) {
                moves[*numMoves] = move;
                (*numMoves)++;
            }

            if (gameBoard[destRow][destCol].currPiece != NULL) {
                break;
            }

            destRow += bishopRowDirections[direction];
            destCol += bishopColDirections[direction];
        }
    }
}
void generateKingMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    // Possible king moves (offsets)
    int rowDeltas[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int colDeltas[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++) {
        int destRow = startRow + rowDeltas[i];
        int destCol = startCol + colDeltas[i];

        if (destRow >= 0 && destRow < 8 && destCol >= 0 && destCol < 8) {
            struct Move move;
            move.initialRow = startRow;
            move.initialCol = startCol;
            move.destinationRow = destRow;
            move.destinationCol = destCol;

            if (isValidMove(gameBoard, &move, currColor)) {
                moves[*numMoves] = move;
                (*numMoves)++;
            }
        }
    }
}
void generatePawnMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    int direction = (currColor == 0) ? -1 : 1;

    // One-step forward
    struct Move move;
    move.initialRow = startRow;
    move.initialCol = startCol;
    move.destinationRow = startRow + direction;
    move.destinationCol = startCol;
    if (isValidMove(gameBoard, &move, currColor)) {
        moves[*numMoves] = move;
        (*numMoves)++;
    }

    // Two-step forward (if on starting rank)
    move.destinationRow = startRow + 2 * direction;
    if ((currColor == 0 && startRow == 6) || (currColor == 1 && startRow == 1)) {
        if (gameBoard[startRow + direction][startCol].currPiece == NULL &&
            isValidMove(gameBoard, &move, currColor)) {
            moves[*numMoves] = move;
            (*numMoves)++;
        }
    }

    // Diagonal captures
    for (int deltaCol = -1; deltaCol <= 1; deltaCol += 2) {
        move.destinationRow = startRow + direction;
        move.destinationCol = startCol + deltaCol;
        if (startCol + deltaCol >= 0 && startCol + deltaCol < 8 &&
            gameBoard[move.destinationRow][move.destinationCol].currPiece != NULL &&
            gameBoard[move.destinationRow][move.destinationCol].currPiece->color != currColor &&
            isValidMove(gameBoard, &move, currColor)) {
            moves[*numMoves] = move;
            (*numMoves)++;
        }
    }
}
void generateKnightMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    int possibleDeltas[][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

    for (int i = 0; i < 8; i++) {
        int destRow = startRow + possibleDeltas[i][0];
        int destCol = startCol + possibleDeltas[i][1];

        // Check if the destination is on the board
        if (destRow >= 0 && destRow < 8 && destCol >= 0 && destCol < 8) {
            struct Move move;
            move.initialRow = startRow;
            move.initialCol = startCol;
            move.destinationRow = destRow;
            move.destinationCol = destCol;

            // Check legality and add to moves
            if (isValidMove(gameBoard, &move, currColor)) {
                moves[*numMoves] = move;
                (*numMoves)++;
            }
        }
    }
}
void generateBishopMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    // Directions: Up-Right, Down-Right, Down-Left, Up-Left
    int rowDirections[] = { -1, 1, 1, -1 };
    int colDirections[] = { 1, 1, -1, -1 };

    for (int direction = 0; direction < 4; direction++) {
        int destRow = startRow + rowDirections[direction];
        int destCol = startCol + colDirections[direction];

        while (destRow >= 0 && destRow < 8 && destCol >= 0 && destCol < 8) {
            struct Move move;
            move.initialRow = startRow;
            move.initialCol = startCol;
            move.destinationRow = destRow;
            move.destinationCol = destCol;

            if (isValidMove(gameBoard, &move, currColor)) {
                moves[*numMoves] = move;
                (*numMoves)++;
            }

            // Check if path is blocked
            if (gameBoard[destRow][destCol].currPiece != NULL) {
                break; // Stop checking further in this direction
            }

            // Move to the next diagonal square
            destRow += rowDirections[direction];
            destCol += colDirections[direction];
        }
    }
}

void generateLegalMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor) {
    struct Piece *piece = gameBoard[startRow][startCol].currPiece;
    if (piece == NULL || piece->color != currColor) {
        return;
    }

    *numMoves = 0;

    switch(piece->pieceType) {
        case 0: generatePawnMoves(gameBoard, startRow, startCol, moves, numMoves, currColor);
        case 1: generateRookMoves(gameBoard, startRow, startCol, moves, numMoves, currColor);
        case 2: generateBishopMoves(gameBoard, startRow, startCol, moves, numMoves, currColor);
        case 3: generateKnightMoves(gameBoard, startRow, startCol, moves, numMoves, currColor);
        case 4: generateQueenMoves(gameBoard, startRow, startCol, moves, numMoves, currColor);
        case 5: generateKingMoves(gameBoard, startRow, startCol, moves, numMoves, currColor);
    }
}
bool canEscapeCheck(struct Square gameBoard[8][8], int currColor) {
    // 1. Ensure the player is actually in check
    if (!possibleCheck(gameBoard, currColor)) {
        return true; // Not in check, so 'escapable'
    }
    // 2. Iterate through the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            struct Piece *piece = gameBoard[i][j].currPiece;
            if (piece != NULL && piece->color == currColor) {
                // 3. Generate legal moves for the current piece
                struct Move moves[200];
                int numMoves = 0;
                generateLegalMoves(gameBoard, i, j, moves, &numMoves, currColor);
                
                // 4. Test each legal move
                for (int moveIndex = 0; moveIndex < numMoves; moveIndex++) {
                    struct Square gameBoardCopy[8][8];
                    deepCopyBoard(gameBoard, gameBoardCopy);
                    makeMove(gameBoardCopy, &moves[moveIndex], currColor);

                    if (!possibleCheck(gameBoardCopy, currColor)) {
                        return true; // Found a move that escapes check
                    }
                }
            }
        }
    }

    // If we've tried all moves and none escape check:
    return false;
}
bool outOfCheck(struct Square gameBoard[8][8],struct Move *move,int currColor){
    struct Square gameBoardCopy[8][8];
    deepCopyBoard(gameBoard,gameBoardCopy);
    makeMove(gameBoardCopy,move,currColor);
    if(possibleCheck(gameBoardCopy,currColor)){
        printf("Still in Check!\n");
        return false;
    }
    else return true;
}
bool isStalemate(struct Square gameBoard[8][8], int currColor) {
    // Check if the current player is in check
    if (possibleCheck(gameBoard, currColor)) {
        return false; // Not a stalemate if in check
    }

    // Check if the current player has any legal moves
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            struct Piece *piece = gameBoard[i][j].currPiece;
            if (piece != NULL && piece->color == currColor) {
                struct Move moves[200];
                int numMoves = 0;
                generateLegalMoves(gameBoard, i, j, moves, &numMoves, currColor);

                // If we find at least one legal move, it's not stalemate
                if (numMoves > 0) {
                    return false;
                }
            }
        }
    }

    // If we've reached here, there are no legal moves and the player is not in check
    return true;
}

int startGame() {
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
                        if (strcmp(redoChoice, "yes") == 0) {
                            deepCopyBoard(backupBoard, board); // Restore the backup
                            printf("Redoing the move...\n");
                            printBoard(board);
                            continue; // Skip changing the player
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
                    if (strcmp(redoChoice, "yes") == 0) {
                        deepCopyBoard(backupBoard, board); // Restore the backup
                        printf("Redoing the move...\n");
                        printBoard(board);
                        continue; // Skip changing the player
                    }
                   invalidMove = true;
                }
                else{
                    printf("Invalid Move! Try again!\n");
                }
            }
        }
        currColor = 1 - currColor; // Switch player after a valid move
    }
    return 0;
}

int main(int argc, const char * argv[]) {



    int menuInput;
    char menuStatus = 1;

    while (menuStatus == 1){
        printMenu();
        scanf("%d", &menuInput);
        getchar();
        switch(menuInput){
            case 1://start game
                startGame();
                break;

            case 2:
                printf("Not implemented yet :(\n");
				break;

            case 3:
                printf("Not implemented yet :(\n");
				break;

            case 4:
                menuStatus = 0;
                break;
            
            default:
                printf("Invalid Input!\n\n");
				break;
        }
        
    } 

    //return 0;
}
