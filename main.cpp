#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <ctime>

int main() 
{
    srand(time(0));

    MinesweeperBoard board (10, 10, GameMode::EASY);
    MSBoardTextView view ( board );

    board.revealField(3, 5);
    board.revealField(0, 0);
    board.revealField(3, 1);

    board.debug_display();
    std::cout << std::endl;
    view.display();
}
//sfml