/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** SnakeCell
*/

#include "SnakeCell.hpp"

SnakeCell::SnakeCell(int x, int y)
    : sc_Xpos(x)
    , sc_Ypos(y)
    , sc_prevXpos(x)
    , sc_prevYpos(y)
{
}

SnakeCell::~SnakeCell()
{
}

void SnakeCell::setPos(int x, int y)
{
    sc_Xpos = x;
    sc_Ypos = y;
}

int SnakeCell::getXpos()
{
    return sc_Xpos;
}

int SnakeCell::getYpos()
{
    return sc_Xpos;
}

int SnakeCell::getPrevXpos()
{
    return sc_prevXpos;
}

int SnakeCell::getPrevYpos()
{
    return sc_prevYpos;
}