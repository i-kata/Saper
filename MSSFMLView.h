#include "MinesweeperBoard.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include<SFML/Graphics.hpp>


#ifndef MSSFMLView_H_
#define MSSFMLView_H_

class MSSFMLView
{
    int height;
    int width;
    MinesweeperBoard& board;

public:

    MSSFMLView(MinesweeperBoard & board);
    void drawWidnow (sf::RenderWindow & win);
};

#endif