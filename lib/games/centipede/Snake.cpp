/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Snake
*/

#include "Centipede.hpp"
#include "Snake.hpp"

/************* SnakeCell methods **************/

arc::games::centipede::SnakeCell::SnakeCell(int x, int y, arc::games::centipede::SnakeCell::Type type)
    : arc::Sprite("snakecell", arc::Vector{x, y})
    , type(type)
{
}

arc::games::centipede::SnakeCell::~SnakeCell() = default;

/************* Snake methods  ***************/

arc::games::centipede::Snake::Snake(int size, int x, int y)
{
    for (int i = 0; i < size; i++) {
        this->cells.push_back(std::make_shared<arc::games::centipede::SnakeCell>(arc::games::centipede::SnakeCell{
            x, y - i, i == 0 ? arc::games::centipede::SnakeCell::HEAD : arc::games::centipede::SnakeCell::BODY
        }));
    }
}

arc::games::centipede::Snake::~Snake() = default;
