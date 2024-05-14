
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
const char* O_ASCII_ART =
"                \n"
"  ,ad8888ba,    \n"
" d8\"'   `\"8b  \n"
"d8'        `8b  \n"
"88          88  \n"
"88          88  \n"
"Y8,        ,8P  \n"
" Y8a.    .a8P   \n"
"  `\"Y8888Y\"'  \n"
"                \n";

const char* X_ASCII_ART = 
"         \n"
"db    db \n"
"`8b  d8' \n"
" `8bd8'  \n"
" .dPYb.  \n"
".8P  Y8. \n"
"YP    YP \n"
"         \n";

int currentPos = 0;

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
  
  // Draw X or O. 
  
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (*(boardPointer + col + row * 3) == 1) { 
        attron(COLOR_PAIR(2) | A_REVERSE);
        mvprintw(row * sizeGridY + sizeGridY / 4, col * sizeGridX + sizeGridX / 4, "%s", X_ASCII_ART); 
        attroff(COLOR_PAIR(2) | A_REVERSE);
      }
    } 
  }
  refresh();
}

// ----------------------------------------------------------------------------
void processUserInput(int keycode) {
  switch (keycode) {
    case 113: running = false; break;
    case 114: *(boardPointer + currentPos) = 1; currentPos++; break;
  
  }
}

