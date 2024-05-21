
#include "./terminalmanager.h"
#include <ncurses.h>

// ____________________________________________________________________________
TerminalManager::TerminalManager() {
    // Initialize ncurses. 
    initscr();
    cbreak();
    noecho();
    curs_set(false);
    nodelay(stdscr, true);
    keypad(stdscr, true);

    // Initilaize ncurses colors. 
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    // Set dimension of the screen.
    numRows_ = LINES;
    numCols_ = COLS / 2;
}

// ____________________________________________________________________________
TerminalManager::~TerminalManager() { endwin(); }

// ____________________________________________________________________________
void TerminalManager::refresh() { ::refresh(); }

void TerminalManager::drawItem(int row, int col, int color, char* item) {
    if (color == COLOR_WHITE) {
        attron(COLOR_PAIR(1));
    } else if (color == COLOR_GREEN) {
        attron(COLOR_PAIR(2));
    }
    mvprintw(row, 2 * col, "%s", item);
}

UserInput TerminalManager::getUserInput() {
    UserInput userInput;
    userInput.keycode_ = getch();
    return userInput;
}