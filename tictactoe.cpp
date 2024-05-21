
#include "./tictactoe.h"

TicTacToe::TicTacToe(TerminalManager *terminalManager) {
    terminalManager_ = terminalManager;
}

void TicTacToe::run() {
    initGame();
    while (running) {
        UserInput userInput = (*terminalManager_).getUserInput();        
        if (userInput.isEscape()) { running = false; return; } 
        handleKey(userInput); 
    }

}

void TicTacToe::markCell(int row, int col) {}

void TicTacToe::initGame() {
    boardPointer = board;

}

void TicTacToe::drawBoard() {}

void TicTacToe::checkIfGameEnds() {}

void TicTacToe::handleKey(UserInput userinput) {}

