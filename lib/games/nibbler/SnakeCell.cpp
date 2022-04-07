/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** SnakeCell
*/

#include "SnakeCell.hpp"

arc::games::SnakeCell::SnakeCell(int x, int y)
    : arc::Sprite("snake_body_horizontal", arc::Vector(x, y))
    , sc_prevXpos(x)
    , sc_prevYpos(y)
{
}

arc::games::SnakeCell::~SnakeCell()
{
}

void arc::games::SnakeCell::setPrevPos(int x, int y)
{
    sc_prevXpos = this->getPosition().x;
    sc_prevYpos = this->getPosition().y;
}

int arc::games::SnakeCell::getXpos()
{
    return this->getPosition().x;
}

int arc::games::SnakeCell::getYpos()
{
    return this->getPosition().y;
}

int arc::games::SnakeCell::getPrevXpos()
{
    return sc_prevXpos;
}

int arc::games::SnakeCell::getPrevYpos()
{
    return sc_prevYpos;
}

void arc::games::SnakeCell::updateAxis()
{
    if (sc_prevXpos == this->getPosition().x) {
        this->setValue("snake_body_vertical");
    } else {
        this->setValue("snake_body_horizontal");
    }
}