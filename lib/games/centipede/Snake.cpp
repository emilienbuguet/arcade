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
    : arc::Sprite(type == BODY ? "centipede/snakecell_down_1" : "centipede/snakehead_down_1", arc::Vector{x, y})
    , x(0)
    , y(0)
    , frame(1)
    , type(type)
    , dir(dir)
{
}

arc::games::centipede::SnakeCell::~SnakeCell() = default;

void arc::games::centipede::SnakeCell::move()
{
    if (this->dir == arc::games::centipede::SnakeCell::Direction::LEFT)
        this->setPosition(arc::Vector{this->getPosition().x - 1, this->getPosition().y});
    else if (dir == arc::games::centipede::SnakeCell::Direction::RIGHT)
        this->setPosition(arc::Vector{this->getPosition().x + 1, this->getPosition().y});
    else
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
    std::string value(type == BODY ? std::string("centipede/snakecell_") : std::string("centipede/snakehead_"));
    value += direction + std::to_string(frame);
    this->setValue(value);
}

bool arc::games::centipede::SnakeCell::hasRightMushroom(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    auto pos = this->getPosition();
    if (pos.x >= 31)
        return true;
    for (auto &mushroom : mushrooms) {
        auto mushpos = mushroom->getPosition();
        if (pos.x == mushpos.x - 1 && pos.y == mushpos.y) {
            return true;
        }
    }
    return false;
}

bool arc::games::centipede::SnakeCell::hasLeftMushroom(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    auto pos = this->getPosition();
    if (pos.x <= 0)
        return true;
    for (auto &mushroom : mushrooms) {
        auto mushpos = mushroom->getPosition();
        if (pos.x == mushpos.x + 1 && pos.y == mushpos.y) {
            return true;
        }
    }
    return false;
}

bool arc::games::centipede::SnakeCell::hasDownMushroom(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    auto pos = this->getPosition();
    for (auto &mushroom : mushrooms) {
        auto mushpos = mushroom->getPosition();
        if (pos.x == mushpos.x && pos.y + 1 == mushpos.y) {
            return true;
        }
    }
    return false;
}


void arc::games::centipede::SnakeCell::pickADir(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    if (this->hasRightMushroom(mushrooms) && this->hasLeftMushroom(mushrooms)) {
        this->dir = arc::games::centipede::SnakeCell::DOWN;
        return;
    }
    if (this->hasLeftMushroom(mushrooms) && !this->hasRightMushroom(mushrooms)) {
        this->dir = arc::games::centipede::SnakeCell::RIGHT;
        return;
    }
    if (this->hasRightMushroom(mushrooms) && !this->hasLeftMushroom(mushrooms)) {
        this->dir = arc::games::centipede::SnakeCell::LEFT;
        return;
    }
    if (!this->hasLeftMushroom(mushrooms) && !this->hasRightMushroom(mushrooms)) {
        this->dir = static_cast<arc::games::centipede::SnakeCell::Direction>(rand() % 2 + 1);
        return;
    }
}

void arc::games::centipede::SnakeCell::pickASideDir(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    if (this->dir == RIGHT) {
        if (!this->hasRightMushroom(mushrooms)) {
            this->dir = arc::games::centipede::SnakeCell::Direction::RIGHT;
        } else if (this->hasDownMushroom(mushrooms)) {
            this->dir = arc::games::centipede::SnakeCell::Direction::LEFT;
        } else {
            this->dir = arc::games::centipede::SnakeCell::Direction::DOWN;
        }
    } else {
        if (!this->hasLeftMushroom(mushrooms)) {
            this->dir = arc::games::centipede::SnakeCell::Direction::LEFT;
        } else if (this->hasDownMushroom(mushrooms)) {
            this->dir = arc::games::centipede::SnakeCell::Direction::RIGHT;
        } else {
            this->dir = arc::games::centipede::SnakeCell::Direction::DOWN;
        }
    }
}

void arc::games::centipede::SnakeCell::hit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    auto pos = this->getPosition();
    if (pos.y < 0) {
        this->dir = arc::games::centipede::SnakeCell::Direction::DOWN;
        return;
    }
    if (this->dir == arc::games::centipede::SnakeCell::Direction::DOWN) {
        this->pickADir(mushrooms);
    } else {
        this->pickASideDir(mushrooms);
    }
}

arc::games::centipede::SnakeCell::Direction arc::games::centipede::SnakeCell::getDirection() const
{
    return this->dir;
}

void arc::games::centipede::SnakeCell::setDirection(arc::games::centipede::SnakeCell::Direction dir)
{
    this->dir = dir;
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

arc::games::centipede::SnakeCell::Type arc::games::centipede::SnakeCell::getCellType() const
{
    return this->type;
}

void arc::games::centipede::SnakeCell::setCellType(arc::games::centipede::SnakeCell::Type type)
{
    this->type = type;
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

arc::games::centipede::Snake::Snake(std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> ncells)
    : cells(ncells)
{
}

arc::games::centipede::Snake::~Snake() = default;

std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> arc::games::centipede::Snake::getCells() const
{
    return this->cells;
}

void arc::games::centipede::Snake::setCells(std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> ncells)
{
    this->cells = ncells;
    for (auto &cell : cells)
        cell->setCellType(arc::games::centipede::SnakeCell::BODY);
    if (this->cells.size() == 0)
        return;
    cells[0]->setCellType(arc::games::centipede::SnakeCell::HEAD);
}

void arc::games::centipede::Snake::update()
{
    for (auto &cell : this->cells) {
        cell->update();
    }
}

void arc::games::centipede::Snake::checkHit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms)
{
    if (this->cells.size() == 0)
        return;
    auto tmp = this->cells[0]->getDirection();
    this->cells[0]->hit(mushrooms);

    for (auto &cell : this->cells) {
        auto tmp2 = cell->getDirection();
        if (cell->getCellType() == arc::games::centipede::SnakeCell::HEAD)
            continue;
        cell->setDirection(tmp);
        tmp = tmp2;
    }
}
