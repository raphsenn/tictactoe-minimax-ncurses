
#include <ncurses.h>

#include "./tictactoe.h"

// ----------------------------------------------------------------------------
// Information in header file.
int board[9];
int* boardPointer;

int dimX;
int dimY;

bool running;

// ----------------------------------------------------------------------------
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  start_color();
  dimX = COLS / 2;
  dimY = LINES;
}

// ----------------------------------------------------------------------------
void initGame() {
  running = true;
}

void processUserInput(int keycode) {
  switch (keycode) {
    case 113: running = false; break;
  }
}

