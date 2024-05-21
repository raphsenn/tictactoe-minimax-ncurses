
#include "./tictactoe.h"

#include "./text.h"

// ____________________________________________________________________________
TicTacToe::TicTacToe(TerminalManager *terminalManager) {
    terminalManager_ = terminalManager;
}

// ____________________________________________________________________________
void TicTacToe::run() {
    initGame();
    while (running) {
        UserInput userInput = (*terminalManager_).getUserInput();        
        if (userInput.isEscape()) { running = false; return; } 
        handleKey(userInput);
        drawBoard();

        // Refresh. 
        (*terminalManager_).refresh(); 
    }

}

// ____________________________________________________________________________
void TicTacToe::markCell(int row, int col) {}

// ____________________________________________________________________________
void TicTacToe::initGame() {
    boardPointer = board;
    boardSizeX = 12;
    boardSizeY = 8;
                        
    boardPosX = ((*terminalManager_).getNumCols() - boardSizeX) / 2 ;
    boardPosY = ((*terminalManager_).getNumRows() - boardSizeY) / 2;
}

// ____________________________________________________________________________
void TicTacToe::drawBoard() {
    // Grid size of the board 3 X 3.
    int gridSize = 3;
    
    // Draw the board
    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 13; col++) {
            if (row % 2 == 0 && col % 4 == 0) {
                (*terminalManager_).drawItem(boardPosY + row, boardPosX + col, 1, "+");
            } else if (row % 2 == 0) {
                (*terminalManager_).drawItem(boardPosY + row, boardPosX + col, 1, "-");
            } else if (col % 4 == 0) {
                (*terminalManager_).drawItem(boardPosY + row, boardPosX + col, 1, "|");
            } else {
                (*terminalManager_).drawItem(boardPosY + row, boardPosX + col, 1, " ");
            }
        }
    }

    // Draw current state of the board.


}

// ____________________________________________________________________________
void TicTacToe::checkIfGameEnds() {}

// ____________________________________________________________________________
void TicTacToe::handleKey(UserInput userinput) {}

