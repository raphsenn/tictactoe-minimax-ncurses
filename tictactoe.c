
#include <ncurses.h>

#include "./tictactoe.h"

// ----------------------------------------------------------------------------
// Information in header file.
int board[9];
int* boardPointer;

int dimX;
int dimY;

int sizeGridX;
int sizeGridY;

bool running;

// ----------------------------------------------------------------------------
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE); 
  dimX = COLS;
  dimY = LINES;
}

// ----------------------------------------------------------------------------
void initGame() {
  running = true;
  sizeGridX = dimX / 3;
  sizeGridY = dimY / 3;
}

// ----------------------------------------------------------------------------
void drawBoard() { 

  // Draw board grid.
  // Horizontal lines.
  attron(COLOR_PAIR(1)| A_REVERSE);
  for (int i = sizeGridY; i <= 2 * sizeGridY; i += sizeGridY) {
    for (int j = 0; j < dimX-1; j++) {
      mvprintw(i, j, "  ");
    }
  }
  // Vertical lines.
  for (int i = sizeGridX; i <= 2 * sizeGridX; i += sizeGridX) {
    for (int j = 0; j < dimY; j++) {
      mvprintw(j, i, "  ");
    }
  }
  attroff(COLOR_PAIR(1) | A_REVERSE);
  refresh();
}

// ----------------------------------------------------------------------------
void processUserInput(int keycode) {
  switch (keycode) {
    case 113: running = false; break;
  }
}

