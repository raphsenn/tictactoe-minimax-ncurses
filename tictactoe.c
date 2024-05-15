
#include <ncurses.h>

#include "./tictactoe.h"

// ----------------------------------------------------------------------------
// Global variables: information in header file.
int board[9];
int* boardPointer = board;

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
  init_pair(1, COLOR_WHITE, COLOR_WHITE); // WHITE:WHITE
  init_pair(2, COLOR_BLACK, COLOR_WHITE); // WHITE:BLACK
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
  // attron(COLOR_PAIR(1)| A_REVERSE);
  for (int i = sizeGridY; i <= 2 * sizeGridY; i += sizeGridY) {
    for (int j = 0; j < dimX-1; j++) {
      attron(COLOR_PAIR(1)| A_REVERSE);
      mvprintw(i, j, "  ");
      attroff(COLOR_PAIR(1) | A_REVERSE);
    }
  }
  // Vertical lines.
  for (int i = sizeGridX; i <= 2 * sizeGridX; i += sizeGridX) {
    for (int j = 0; j < dimY; j++) {
      attron(COLOR_PAIR(1)| A_REVERSE);
      mvprintw(j, i, "  ");
      attroff(COLOR_PAIR(1) | A_REVERSE);
    }
  }
  // attroff(COLOR_PAIR(1) | A_REVERSE);
  
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
    
    } 
  }
  refresh();
}

// ----------------------------------------------------------------------------
void processUserInput(int keycode) {
  switch (keycode) {
    case 113: running = false; break;
  
  }
}

