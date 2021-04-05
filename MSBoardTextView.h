#ifndef MSBoardTextView_H_
#define MSBoardTextView_H_
#include "MinesweeperBoard.h"

class MSBoardTextView
{
    int height;
    int width;
    MinesweeperBoard& board;

public:
    MSBoardTextView(MinesweeperBoard & board);
    void display() const;
};

#endif
