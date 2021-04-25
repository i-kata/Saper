#include <iostream>
#include <vector>
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board(board)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSSFMLView::drawWidnow(sf::RenderWindow &win)
{
    GameState state = board.getGameState();
    int screenHeight = win.getSize().x;
    int screenWidth = win.getSize().y;
    float boardFieldPosX;
    float boardFieldPosY;
    fieldSizeX = screenWidth / width;
    fieldSizeY = screenHeight / height;
    sf::RectangleShape boardField(sf::Vector2f(fieldSizeX, fieldSizeY));

    for (int wier = 0; wier < width; wier++)
    {
        for (int kol = 0; kol < height; kol++)
        {
            char fieldInfo = board.getFieldInfo(wier, kol);
            boardFieldPosX = kol * fieldSizeX;
            boardFieldPosY = wier * fieldSizeY;

            if (fieldInfo == '#')
                std::cout << "Not contained" << std::endl;

            else if (fieldInfo == 'F')
            {
                sf::Texture texture;
                texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_flaga.png");
                sf::Sprite sprite(texture);
                sprite.setPosition(boardFieldPosX, boardFieldPosY);
                win.draw(sprite);
            }

            else if (fieldInfo == '_')
            {
                sf::Texture texture;
                texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek.png");
                sf::Sprite sprite(texture);
                sprite.setPosition(boardFieldPosX, boardFieldPosY);
                win.draw(sprite);
            }

            else if (fieldInfo == 'x')
            {
                sf::Texture texture;
                texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_bomba.png");
                sf::Sprite sprite(texture);
                sprite.setPosition(boardFieldPosX, boardFieldPosY);
                win.draw(sprite);
            }

            else if (fieldInfo == ' ')
                boardField.setFillColor(sf::Color::Black);

            else
            {
                if (fieldInfo == '1')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr1.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '2')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr2.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '3')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr3.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '4')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr4.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '5')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr5.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '6')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr6.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '7')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr7.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else if (fieldInfo == '8')
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr8.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }

                else
                {
                    sf::Texture texture;
                    texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/kafelek_nr9.png");
                    sf::Sprite sprite(texture);
                    sprite.setPosition(boardFieldPosX, boardFieldPosY);
                    win.draw(sprite);
                }
            }
        }
    }

    if (state != RUNNING)
    {
        if (state == FINISHED_WIN)
        {
            sf::Texture texture;
            texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/youwon.png");
            sf::Sprite sprite(texture);
            sprite.setPosition(0, 200);
            win.draw(sprite);
        }

        else
        {
            sf::Texture texture;
            texture.loadFromFile("C:/Users/Iwan/OneDrive/Pulpit/Ikony/youlost.png");
            sf::Sprite sprite(texture);
            sprite.setPosition(0, 200);
            win.draw(sprite);
        }
    }
    std::cout << state << std::endl;
}

std::vector<int> MSSFMLView::mouse2boardConverter(int mousePosX, int mousePosY)
{
    std::vector<int> retVals;
    int boardX = mousePosX / fieldSizeX;
    int boardY = mousePosY / fieldSizeY;
    retVals.push_back(boardX);
    retVals.push_back(boardY);

    return retVals;
}


