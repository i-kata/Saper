#include <iostream>
#include "MinesweeperBoard.h"


MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
  //width = 10;
  //height = 10; 
  
  for (int wier = 0; wier < height; wier++)
  {
    for (int kol = 0; kol < width; kol++)
    {
      Board [wier][kol].hasMine = false;
      Board [wier][kol].isRevealed = false;
      Board [wier][kol].hasFlag = false;
    }
  }

/*
  Board [0][0].hasMine = true;
  Board [0][0].hasFlag = false;
  Board [0][0].isRevealed = false;

  Board [1][1].hasMine = false;
  Board [1][1].hasFlag = false;
  Board [1][1].isRevealed = true;

  Board [0][2].hasMine = true;
  Board [0][2].hasFlag = true;
  Board [0][2].isRevealed = false;
*/
}

void MinesweeperBoard::debug_display() const
{
  for (int wier = 0; wier < height; wier++)
  {
    for (int kol = 0; kol < width; kol++)
    {
      if (Board [wier][kol].hasMine == true)
        std::cout << "[M";
      else
        std::cout << "[.";

      if (Board [wier][kol].isRevealed == true)
        std::cout << "o";
      else
        std::cout << ".";

      if (Board [wier][kol].hasFlag == true)
        std::cout << "f]";
      else
        std::cout << ".]"; 
    }
    std::cout << std::endl;
  }
}