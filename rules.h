#include <stdbool.h>
#include "struct.h"
#ifndef rules_h
#define rules_h
/**
struct Piece{
        int color;// 0 = white, 1 = black
        int pieceType;// 0 = pawn, 1 = rook, 2 = bishop, 3 = knight, 4 = queen, 5 = king
        bool firstMove;
        int moveCount;
    };
    struct Square {
        struct Piece* currPiece;
        int col;
        int row;
    };
    struct Move{
        int initialCol;
        int initialRow;
        int destinationCol;
        int destinationRow;

    };
**/

//Board Functions
void initializeBoard(struct Square gameBoard[8][8]);
void deepCopyBoard(struct Square gameBoard[8][8], struct Square gameBoardCopy[8][8]);
void printBoard(struct Square gameBoard[8][8]);

// Move Functions
bool isValidMove(struct Square gameBoard[8][8], const struct Move *move, int currColor);
bool isValidMoveFormat(const char *input);
void getPlayerMove(struct Move *move);
void getPlayerMove_TEST(struct Move *move, char *input);
int getPlayerMove_rint(struct Move *move);
int getPlayerMove_rint_TEST(struct Move *move, char *input);
int getPromotionChoice();
void makeMove(struct Square gameBoard[8][8], struct Move *move, int currColor);
bool isValidBishopMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidKnightMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidRookMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidQueenMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidPawnMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidCastle(struct Square gameBoard[8][8], const struct Move *move);
bool isValidKingMove(struct Square gameBoard[8][8], const struct Move *move);
bool isEnPassant(struct Square gameBoard[8][8], const struct Move *move, int currColor);

//Check Functions
bool isStalemate(struct Square gameBoard[8][8], int currColor);
bool possibleCheck(struct Square gameBoard[8][8], int currColor);
void generateRookMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
void generateQueenMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
void generateKingMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
void generatePawnMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
void generateKnightMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
void generateBishopMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
void generateLegalMoves(struct Square gameBoard[8][8], int startRow, int startCol, struct Move moves[], int *numMoves, int currColor);
bool canEscapeCheck(struct Square gameBoard[8][8], int currColor);
bool outOfCheck(struct Square gameBoard[8][8],struct Move *move,int currColor);

int startGame(int gameMode);
int startGame_TEST(int gameMode, char input_string[100][10]);
bool redoMovePVE(struct Square board[8][8], struct Square backupBoard[8][8], int currentPlayer);
bool redoMovePVP(struct Square board[8][8], struct Square backupBoard[8][8], int currentPlayer);
bool redoMovePVP_TEST(struct Square board[8][8], struct Square backupBoard[8][8], int currentPlayer,char *redoChoice);
void printMenu();
int addMove(char input_string[100][10], int counter, char *input);
#endif 

