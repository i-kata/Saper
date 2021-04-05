#ifndef MSTextController_H_
#define MSTextController_H_
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{

    int height;
    int width;
    MinesweeperBoard & board;
    MSBoardTextView & view;

public:

    MSTextController(MinesweeperBoard & board, MSBoardTextView & view);
    void play();
};

#endif