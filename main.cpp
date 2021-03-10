#include <iostream>

// IWAN KATA 259026

struct Field
{
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard
{
  Field Board[100][100];
  int width;
  int height;

public:
  MinesweeperBoard();
  void debug_display() const;
};

MinesweeperBoard::MinesweeperBoard()
{
  width = 10;
  height = 10; // dziekuje

  for (int wier = 0; wier < height; wier++)
  {
    for (int kol = 0; kol < width; kol++)
    {
      Board [wier][kol].hasMine = true;
      Board [wier][kol].isRevealed = true;
      Board [wier][kol].hasFlag = false;
    }
  }
}

void MinesweeperBoard::debug_display() const
{
  for (int wier = 0; wier < width; wier++)
  {
    for (int kol = 0; kol < height; kol++)
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


int main() 
{
  MinesweeperBoard b;
  b.debug_display();
}