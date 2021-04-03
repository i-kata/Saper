#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) : width(width), height(height), mode(mode)
{
    width = width;
    height = height;
    mode = mode;

    firstMove = true;

    state = RUNNING;

    int minecount = 0;

    for (int wier = 0; wier < height; wier++)
    {

        if (mode == DEBUG)
        {
            for (int kol = 0; kol < width; kol++)
            {
                if (wier == kol)
                    Board[wier][kol].hasMine = true;

                if (wier == 0)
                    Board[wier][kol].hasMine = true;

                if (kol == 0 and wier % 2 == 0)
                    Board[wier][kol].hasMine = true;

                Board[wier][kol].isRevealed = false;
                Board[wier][kol].hasFlag = false;
            }
        }

        if (mode == EASY)
        {
            int mines = 0.1 * width * height;

            while (minecount < mines)
            {
                int wiersz = rand() % height;
                int kolumna = rand() % width;

                if (Board[wiersz][kolumna].hasMine == false)
                {
                    Board[wiersz][kolumna].hasMine = true;
                    minecount++;
                }
            }
        }

        if (mode == NORMAL)
        {
            int mines = 0.2 * width * height;

            while (minecount < mines)
            {
                int wiersz = rand() % height;
                int kolumna = rand() % width;

                if (Board[wiersz][kolumna].hasMine == false)
                {
                    Board[wiersz][kolumna].hasMine = true;
                    minecount++;
                }
            }
        }

        if (mode == HARD)
        {
            int mines = 0.3 * width * height;

            std::cout << mines << std::endl;
            while (minecount < mines)
            {
                int wiersz = rand() % height;
                int kolumna = rand() % width;

                if (Board[wiersz][kolumna].hasMine == false)
                {
                    Board[wiersz][kolumna].hasMine = true;
                    minecount++;
                }
            }
        }
    }
}


bool MinesweeperBoard::containedInBoard(int wier, int kol) const
{
    if (wier >= 0 and wier <= height)
    {
        if (kol >= 0 and kol <= width)
            return true;
    }

    return false;
}


void MinesweeperBoard::debug_display() const
{
    for (int wier = 0; wier < height; wier++)
    {
        for (int kol = 0; kol < width; kol++)
        {
            if (Board[wier][kol].hasMine == true)
                std::cout << "[M";
            else
                std::cout << "[.";

            if (Board[wier][kol].isRevealed == true)
                std::cout << "o";
            else
                std::cout << ".";

            if (Board[wier][kol].hasFlag == true)
                std::cout << "f]";
            else
                std::cout << ".]";
        }

        std::cout << std::endl;
    }
}


int MinesweeperBoard::getBoardWidth() const
{
    return width;
}


int MinesweeperBoard::getBoardHeight() const
{
    return height;
}


int MinesweeperBoard::getMineCount() const
{
    int minecount = 0;

    for (int wier = 0; wier < height; wier++)
    {
        for (int kol = 0; kol < width; kol++)
        {
            if (Board[wier][kol].hasMine == true)
                minecount++;
        }
    }

    return minecount;
}


int MinesweeperBoard::countMines(int wier, int kol) const
{
    int minecount = 0;

    if (containedInBoard(wier - 1, kol - 1))
        minecount++;

    if (containedInBoard(wier, kol - 1))
        minecount++;

    if (containedInBoard(wier + 1, kol - 1))
        minecount++;

    if (containedInBoard(wier - 1, kol))
        minecount++;

    if (containedInBoard(wier + 1, kol))
        minecount++;

    if (containedInBoard(wier - 1, kol + 1))
        minecount++;

    if (containedInBoard(wier, kol + 1))
        minecount++;

    if (containedInBoard(wier + 1, kol + 1))
        minecount++;

    return minecount;
}


bool MinesweeperBoard::hasFlag(int wier, int kol) const
{
    if (containedInBoard(wier, kol) == true)
    {
        if (Board[wier][kol].hasFlag == false)
            return false;

        if (Board[wier][kol].isRevealed == true)
            return false;

        if (Board[wier][kol].hasFlag == true)
            return true;
    }

    else
    {
        std::cout << "Field in not contained in Board" << std::endl;
    }
}


void MinesweeperBoard::toggleFlag(int wier, int kol)
{
    if (containedInBoard(wier, kol) == true)
    {
        if (Board[wier][kol].isRevealed == false)
            Board[wier][kol].hasFlag = true;

        if (Board[wier][kol].isRevealed == true)
            return;

        if (state == FINISHED_LOSS or state == FINISHED_WIN)
            return;
    }

    else
    {
        std::cout << "Field in not contained in Board" << std::endl;
    }
}


bool MinesweeperBoard::isRevealed(int wier, int kol) const
{
    if (containedInBoard(wier, kol) == true)
    {
        if (Board[wier][kol].isRevealed == true)
            return true;

        return false;
    }

    else
    {
        std::cout << "Field in not contained in Board" << std::endl;
    }
}


void MinesweeperBoard::revealField(int wier, int kol)
{

    if (containedInBoard(wier, kol) == true)
    {
        if (Board[wier][kol].isRevealed == true)
            return;

        if (Board[wier][kol].hasFlag == true)
            return;

        if (state == FINISHED_LOSS or state == FINISHED_WIN)
            return;

        if (Board[wier][kol].isRevealed == false and Board[wier][kol].hasMine == false)
            Board[wier][kol].isRevealed = true;


        if (Board[wier][kol].isRevealed == false and Board[wier][kol].hasMine == true)
        {
            int fields = width * height;
            int notDiscoveredFields = 0;

            for (int wiersz = 0; wiersz < height; wiersz++)
            {
                for (int kolumna = 0; kolumna < width; kolumna++)
                {
                    if (Board[wiersz][kolumna].isRevealed == false)
                        notDiscoveredFields++;
                }
            }

            if (fields == notDiscoveredFields)
            {
                bool bombMoved = false;

                while (bombMoved == false)
                {
                    Board[wier][kol].hasMine = false;
                    Board[wier][kol].isRevealed = true;

                    int newKol = rand() % width;
                    int newWier = rand() % height;

                    if (Board[newWier][newKol].hasMine == false and newKol != kol and newWier != wier)
                    {
                        Board[newWier][newKol].hasMine = true;
                        bombMoved = true;
                    }
                }
            }

            else
            {
                Board[wier][kol].isRevealed = true;
                state = FINISHED_LOSS;
            }
        }

    }

    else
    {
        std::cout << "Field is not contained in Board" << std::endl;
    }
}


char MinesweeperBoard::getFieldInfo(int wier, int kol) const
{

    int mineCount = countMines(wier, kol);

    if (containedInBoard(wier, kol) == false)
        return '#';

    if (Board[wier][kol].isRevealed == false and Board[wier][kol].hasFlag == true)
        return 'F';

    if (Board[wier][kol].isRevealed == false and Board[wier][kol].hasFlag == false)
        return '_';

    if (Board[wier][kol].isRevealed == true and Board[wier][kol].hasMine == true)
        return 'x';

    if (Board[wier][kol].isRevealed == true and mineCount == 0)
        return ' ';

    if (Board[wier][kol].isRevealed == true and mineCount != 0)
        return '0' + mineCount;

}

GameState MinesweeperBoard::getGameState() const
{
    if (state == RUNNING)
        return RUNNING;

    else if (state == FINISHED_LOSS)
        return FINISHED_LOSS;

    else
    {
        int discoveredFieldsCount = 0;

        for (int wiersz = 0; wiersz < height; wiersz++)
        {
            for (int kolumna = 0; kolumna < width; kolumna++)
            {
                if (Board[wiersz][kolumna].isRevealed == true)
                    discoveredFieldsCount++;
            }
        }

        if (discoveredFieldsCount + getMineCount() == width*height)
            return FINISHED_WIN;
    }
}