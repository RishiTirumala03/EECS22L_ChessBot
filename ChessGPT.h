#include <stdbool.h>
#ifndef ChessGPT_h
#define ChessGPT_h
struct Piece{
        int color;// 0 = white, 1 = black
        int pieceType;// 0 = pawn, 1 = rook, 2 = bishop, 3 = knight, 4 = queen, 5 = king
        bool firstMove;
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
//Board Functions
void initializeBoard(struct Square gameBoard[8][8]);
void deepCopyBoard(struct Square gameBoard[8][8], struct Square gameBoardCopy[8][8]);
void printBoard(struct Square gameBoard[8][8]);

// Move Functions
bool isValidMove(struct Square gameBoard[8][8], const struct Move *move, int currColor);
bool isValidMoveFormat(const char *input);
void getPlayerMove(struct Move *move);
int getPromotionChoice(void);
void makeMove(struct Square gameBoard[8][8], struct Move *move, int currColor);
bool isValidBishopMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidKnightMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidRookMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidQueenMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidPawnMove(struct Square gameBoard[8][8], const struct Move *move);
bool isValidCastle(struct Square gameBoard[8][8], const struct Move *move);
bool isValidKingMove(struct Square gameBoard[8][8], const struct Move *move);

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


#endif
