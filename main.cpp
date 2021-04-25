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

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }

                case sf::Event::MouseButtonPressed:
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        int mouseX = event.mouseButton.x;
                        int mouseY = event.mouseButton.y;
                        std::vector<int> boardVals = view.mouse2boardConverter(mouseX, mouseY);
                        board.revealField(boardVals[1], boardVals[0]);
                        break;
                    }

                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        int mouseX = event.mouseButton.x;
                        int mouseY = event.mouseButton.y;
                        std::vector<int> boardVals = view.mouse2boardConverter(mouseX, mouseY);
                        board.toggleFlag(boardVals[1], boardVals[0]);
                    }

                }

            }

        }

        window.clear(sf::Color::Black);
        view.drawWidnow(window);
        window.display();

    }

}


