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
    : arc::Sprite(type == BODY ? "centipede_snakecell_1" : "centipede_snakehead_1", arc::Vector{x, y})
    , x(0)
    , y(0)
    , frame(1)
    , type(type)
{
}

arc::games::centipede::SnakeCell::~SnakeCell() = default;

void arc::games::centipede::SnakeCell::update()
{
    if (frame == 8) {
        frame = 1;
    } else {
        frame++;
    }
    this->setValue(type == BODY ? "centipede_snakecell_" : "centipede_snakehead_" + std::to_string(frame));
}

/************* Snake methods  ***************/

arc::games::centipede::Snake::Snake(int size, int x, int y)
    : cells({})
{
    for (int i = 0; i < size; i++) {
        this->cells.push_back(std::make_shared<arc::games::centipede::SnakeCell>(arc::games::centipede::SnakeCell{
            x, y - i, i == 0 ? arc::games::centipede::SnakeCell::HEAD : arc::games::centipede::SnakeCell::BODY
        }));
    }
}

arc::games::centipede::Snake::~Snake() = default;

std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> arc::games::centipede::Snake::getCells() const
{
    return this->cells;
}

void arc::games::centipede::Snake::update()
{
    for (auto &cell : this->cells) {
        cell->update();
    }
}
