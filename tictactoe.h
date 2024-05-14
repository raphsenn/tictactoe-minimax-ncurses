#ifndef TICTACTOE_H
#define TICTACTOE_H

extern int board[9];
extern int* boardPointer;

extern int dimX;
extern int dimY;

extern bool running;

// ____________________________________________________________________________

void initTerminal();

void initGame();

void processUserInput(int keycode);

#endif // TICTACTOE_H
