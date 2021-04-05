#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : board(board), view(view)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSTextController::play()
{
    GameState state = board.getGameState();

    int wier;
    int kol;
    char choice;
    char fieldInfo;

    while (true)
    {
        view.display();

        if (state != RUNNING)
            break;

        std::cout << "Wprowadz kolejno WIERSZ KOLUMNE I AKCJE (F - oflaguj, R - odkryj pole, Q - wyjscie)." << std::endl;

        std::cout << "WIERSZ: ";
        std::cin >> wier;

        std::cout << std::endl;

        std::cout << "KOLUMNA: ";
        std::cin >> kol;

        std::cout << std::endl;

        std::cout << "AKCJA: ";
        std::cin >> choice;

        std::cout << std::endl;

        fieldInfo = board.getFieldInfo(wier, kol);

        if (fieldInfo == '#')
            std::cout << "Not contained in Board" << std::endl;

        if (choice == 'R')
            board.revealField(wier, kol);

        if (choice == 'F')
            board.toggleFlag(wier, kol);

        if (choice == 'Q')
            break;
    }
}