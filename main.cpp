#include <iostream>

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

  
}


int main() 
{
  std::cout << "Hello World!\n";

  //Zmiana
}