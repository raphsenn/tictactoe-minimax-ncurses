#ifndef TICTACTOE_H
#define TICTACTOE_H

/* 0 represents empty cell,
 * 1 represents X,
 * 2 represents O.
 */

extern int board[9];
extern int* boardPointer;

extern int dimX;
extern int dimY;

extern int sizeGridX;
extern int sizeGridY;

extern int lastMouseClickPosX;
extern int lastMouseClickPosY;

extern bool running;

// ASCII Art strings for O and X.
extern const char* O_ASCII_ART;
extern const char* X_ASCII_ART;

// ____________________________________________________________________________

void initTerminal();

void initGame();

void drawBoard();

void processUserInput(int keycode);

#endif // TICTACTOE_H
