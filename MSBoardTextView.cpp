#include <iostream>
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard & board) : board(board)
{

    height = board.getBoardHeight();
    width = board.getBoardWidth();

}

void MSBoardTextView::display() const
{
    GameState state = board.getGameState();

    char fieldInfo;

    for (int wiersz = 0; wiersz < height; wiersz++)
    {
        for (int kolumna = 0; kolumna < width; kolumna++)
        {
            fieldInfo = board.getFieldInfo(wiersz, kolumna);
            //std::cout << fieldInfo << " ";

            if (fieldInfo == '#')
                std::cout << "Not contained";

            else if (fieldInfo == 'F')
                std::cout << "[ F ]";

            else if (fieldInfo == '_')
                std::cout << "[ ? ]";

            else if (fieldInfo == 'x')
                std::cout << "[ B ]";

            else if (fieldInfo == ' ')
                std::cout << "[   ]";

            else
                std::cout << "  " << fieldInfo << "  ";

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

