
#ifndef Minesweeperboard_H_
#define Minesweeperboard_H_

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

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
  MinesweeperBoard(int width, int height, GameMode mode);
  void debug_display() const;
};


#endif