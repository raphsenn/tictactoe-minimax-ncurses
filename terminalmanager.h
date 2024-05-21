
#pragma once

#include <string>

class UserInput {
public:
    int keycode_;
    bool isEscape() { return 27; }
};


class TerminalManager {
private:
    int numRows_;
    int numCols_; 

public:
    static int White;
    static int Green;
    static int Red;

    int getNumRows();
    int getNumCols();

    // Constructor.
    TerminalManager();

    // Destructor.
    ~TerminalManager();

    // Refresh the screen.
    void refresh();

    void drawItem(int row, int col, int color, char* item);

    UserInput getUserInput();
};
