
#include <ncurses.h>

#include "./tictactoe.h"

int main() {
  initTerminal();
  initGame(); 
  
   while (running) {
    int key = getch();    
    processUserInput(key); 
    drawBoard(); 
  }
  endwin();
  return 0;
}

