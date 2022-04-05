/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Snake
*/

#include "Centipede.hpp"
#include "Snake.hpp"

/************* SnakeCell methods **************/

arc::games::centipede::SnakeCell::SnakeCell(int x, int y, arc::games::centipede::SnakeCell::Type type, arc::games::centipede::SnakeCell::Direction dir)
    : arc::Sprite(type == BODY ? "centipede_snakecell_down_1" : "centipede_snakehead_down_1", arc::Vector{x, y})
    , x(0)
    , y(0)
    , frame(1)
    , type(type)
    , dir(dir)
{
}

// arc::games::centipede::SnakeCell::~SnakeCell() = default;

// void arc::games::centipede::SnakeCell::hit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
// {
//     for(auto mushroom : mushrooms) {
//         if (this->dir == arc::games::centipede::SnakeCell::Direction::LEFT && this->getPosition().x - 1 != mushroom->getPosition().x)
//             this->dir = arc::games::centipede::SnakeCell::Direction::DOWN;
//         else
//             this->dir = arc::games::centipede::SnakeCell::Direction::RIGHT;
//         if (dir == arc::games::centipede::SnakeCell::Direction::RIGHT && this->getPosition().x + 1 != mushroom->getPosition().x)
//             this->dir = arc::games::centipede::SnakeCell::Direction::DOWN;
//         else
//             this->dir = arc::games::centipede::SnakeCell::Direction::LEFT;
//         if (dir == arc::games::centipede::SnakeCell::Direction::DOWN) {
//             if (this->getPosition().x - 1 != mushroom->getPosition().x)
//                 this->dir = arc::games::centipede::SnakeCell::Direction::LEFT;
//             else if (this->getPosition().x + 1 != mushroom->getPosition().x)
//                 this->dir = arc::games::centipede::SnakeCell::Direction::RIGHT;
//             else
//                 this->dir = static_cast<arc::games::centipede::SnakeCell::Direction>(rand() % 3);
//         }
//     }

// }

void arc::games::centipede::SnakeCell::move()
{
    if (this->dir == arc::games::centipede::SnakeCell::Direction::LEFT && this->getPosition().x - 1 >= 0)
        this->setPosition(arc::Vector{this->getPosition().x - 1, this->getPosition().y});
    if (dir == arc::games::centipede::SnakeCell::Direction::RIGHT && this->getPosition().x + 1 < 32)
        this->setPosition(arc::Vector{this->getPosition().x + 1, this->getPosition().y});
    if (dir == arc::games::centipede::SnakeCell::Direction::DOWN && this->getPosition().x + 1 < 24)
        this->setPosition(arc::Vector{this->getPosition().x, this->getPosition().y + 1});
}

void arc::games::centipede::SnakeCell::update()
{
    std::string direction;

    this->move();
    if (frame == 8) {
        frame = 1;
    } else {
        frame++;
    }
    if (dir == DOWN) {
        direction = "down_";
    } else if (dir == LEFT) {
        direction = "left_";
    } else if (dir == RIGHT) {
        direction = "right_";
    }
    std::string value(type == BODY ? std::string("centipede_snakecell_") : std::string("centipede_snakehead_"));
    value += direction + std::to_string(frame);
    this->setValue(value);
}

std::string operator<<(std::string s, arc::games::centipede::SnakeCell::Direction& d)
{
    if (d == arc::games::centipede::SnakeCell::DOWN) {
        s += "d";
    } else if (d == arc::games::centipede::SnakeCell::RIGHT) {
        s += "r";
    } else {
        s += "l";
    }
    return s;
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

void arc::games::centipede::Snake::checkHit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    for (auto mushroom : mushrooms) {
        for (auto cell : this->cells) {
            if (cell->getPosition().x == mushroom->getPosition().x && cell->getPosition().y == mushroom->getPosition().y)
                return;
        }
    }
}