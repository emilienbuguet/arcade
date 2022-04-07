/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** SnakeCell
*/

#include "SnakeCell.hpp"

arc::games::SnakeCell::SnakeCell(int x, int y)
    : sc_Xpos(x)
    , sc_Ypos(y)
    , sc_prevXpos(x)
    , sc_prevYpos(y)
    , sc_axis(direction::axis::HORIZONTAL)
{
}

arc::games::SnakeCell::~SnakeCell()
{
}

void arc::games::SnakeCell::setPos(int x, int y)
{
    sc_Xpos = x;
    sc_Ypos = y;
}

void arc::games::SnakeCell::setPrevPos(int x, int y)
{
    sc_prevXpos = x;
    sc_prevYpos = y;
}

int arc::games::SnakeCell::getXpos()
{
    return sc_Xpos;
}

int arc::games::SnakeCell::getYpos()
{
    return sc_Ypos;
}

int arc::games::SnakeCell::getPrevXpos()
{
    return sc_prevXpos;
}

int arc::games::SnakeCell::getPrevYpos()
{
    return sc_prevYpos;
}

direction::axis arc::games::SnakeCell::getAxis()
{
    return sc_axis;
}

void arc::games::SnakeCell::setAxis(direction::axis axis)
{
    sc_axis = axis;
}

const std::shared_ptr<arc::Object> arc::games::SnakeCell::getObject() const
{
    std::string name = "";
    if (sc_axis == direction::axis::HORIZONTAL)
        name = "snake_body_horizontal";
    else
        name = "snake_body_vertical";
    arc::Sprite sprite(name, arc::Vector(sc_Xpos, sc_Ypos));
    return std::make_shared<arc::Object>(sprite);
}

void arc::games::SnakeCell::updateAxis()
{
    if (sc_prevXpos == sc_Xpos)
        sc_axis = direction::axis::VERTICAL;
    else
        sc_axis = direction::axis::HORIZONTAL;
}