
#include "./terminalmanager.h"
#include "./tictactoe.h"

int main() {

    TerminalManager terminalmanager;
    TicTacToe tictactoe(&terminalmanager);
    tictactoe.run();
}
