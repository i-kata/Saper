#include <iostream>
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard board) : board(board)
{

    height = board.getBoardHeight();
    width = board.getBoardWidth();

}

void MSBoardTextView::display() const
{
    GameState state = board.getGameState();

    for (int wiersz = 0; wiersz < height; wiersz++)
    {
        for (int kolumna = 0; kolumna < width; kolumna++)
        {
            char info = board.getFieldInfo(wiersz, kolumna);
            std::cout << info;

            if (info == '#')
                std::cout << "Not contained";

            else if (info == 'F')
                std::cout << "F";

            else if (info == '_')
                std::cout << " ? ";

            else if (info == 'x')
                std::cout << "B";

            else if (info == ' ')
                std::cout << " ";

            else
                std::cout << info;
        }
        std::cout << std::endl;
    }

    if (state != RUNNING)
    {
        if (state == FINISHED_WIN)
        {
            std::cout << "YOU'RE THE CHAMPION" << std::endl;
        }
        else
        {
            std::cout << "YOU NEED PRACTICE WITH BOMBS" << std::endl;
        }
    }
}


