
#pragma once

#include "./tictactoe.h"
#include "./terminalmanager.h"

class TicTacToe {

private:
    int board[9];
    int* boardPointer;

    // Terminal manager for the window.
    TerminalManager *terminalManager_;

    bool running = true;

public:
    TicTacToe(TerminalManager *terminalManager);
    
    void run();
    void markCell(int row, int col);

private:
    void initGame();
    void drawBoard();
    void checkIfGameEnds();
    void handleKey(UserInput userInput);

};
