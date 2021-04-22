#include <iostream>
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board(board)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSSFMLView::drawWidnow(sf::RenderWindow &win) {
    GameState state = board.getGameState();
    int screenHeight = win.getSize().x;
    int screenWidth = win.getSize().y;
    float boardFieldPosX;
    float boardFieldPosY;
    int spacebFields = 30;
    int fieldSizeX = (screenWidth - ((width + 1) * spacebFields)) / width;
    int fieldSizeY = (screenHeight - ((height + 1) * spacebFields)) / height;
    sf::RectangleShape boardField(sf::Vector2f(fieldSizeX, fieldSizeY));

    for (int wier = 0; wier < width; wier++) {
        for (int kol = 0; kol < height; kol++) {
            char fieldInfo = board.getFieldInfo(wier, kol);
            boardFieldPosX = (kol + 1) * spacebFields + (kol * fieldSizeX);
            boardFieldPosY = (wier + 1) * spacebFields + (wier * fieldSizeY);

            if (fieldInfo == '#')
                std::cout << "Not contained" << std::endl;

            else if (fieldInfo == 'F')
                boardField.setFillColor(sf::Color::Green);

            else if (fieldInfo == '_')
                boardField.setFillColor(sf::Color::White);

            else if (fieldInfo == 'x')
                boardField.setFillColor(sf::Color::Red);

            else if (fieldInfo == ' ')
                boardField.setFillColor(sf::Color::Black);

            else
                std::cout << "  " << fieldInfo << "  ";

            boardField.setPosition(boardFieldPosX, boardFieldPosY);
            win.draw(boardField);
        }
    }
    if (state != RUNNING) {
        if (state == FINISHED_WIN) {
            std::cout << "YOU'RE THE CHAMPION" << std::endl;
        } else {
            std::cout << "YOU NEED PRACTICE WITH BOMBS" << std::endl;
        }
    }
}

