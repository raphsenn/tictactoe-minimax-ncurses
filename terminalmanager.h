
#pragma once

#include <string>

class UserInput {
public:
    int keycode_;
    bool isEscape();
};


class TerminalManager {
private:
    int numRows_;
    int numCols_; 

public:
    static int White;
    static int Green;
    static int Red;

    int getNumRows() { return numRows_; }
    int getNumCols() { return numCols_; }

    // Constructor.
    TerminalManager();

    // Destructor.
    ~TerminalManager();

    // Refresh the screen.
    void refresh();

    void drawItem(int row, int col, int color, char* item);

    UserInput getUserInput();
};
