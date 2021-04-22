#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"


int main()
{
    srand(time(0));

    sf::RenderWindow window (sf::VideoMode(600, 600), "Saper");

    MinesweeperBoard board(10, 10, DEBUG);
    MSSFMLView view (board);

    board.revealField(1, 0);
    board.revealField(3,0);
    board.revealField(9, 2);
    board.toggleFlag(3, 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        view.drawWidnow(window);
        window.display();

    }
}


