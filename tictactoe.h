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

// ____________________________________________________________________________

void initTerminal();

void initGame();

void drawBoard();

void processUserInput(int keycode);

#endif // TICTACTOE_H
