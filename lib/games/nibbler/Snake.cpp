/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake(int x, int y)
    : s_Xpos(x), s_Ypos(y)
{
    s_facing = direction::Facing::RIGHT;
    body.push_back(SnakeCell(3, 0));
    body.push_back(SnakeCell(2, 0));
    body.push_back(SnakeCell(1, 0));
}

Snake::~Snake()
{
}

void Snake::moveSnake()
{
    if (s_facing == direction::Facing::UP)
        s_Ypos -= 1;
    if (s_facing == direction::Facing::RIGHT)
        s_Xpos += 1;
    if (s_facing == direction::Facing::DOWN)
        s_Ypos += 1;
    if (s_facing == direction::Facing::LEFT)
        s_Xpos -= 1;

    body[0].setPos(s_Xpos, s_Ypos);
    int size = body.size();
    for (int i = 1; i < size; i++)
        body[i].setPos(body[i - 1].getPrevXpos(), body[i - 1].getPrevYpos());
}

int Snake::getXpos()
{
    return s_Xpos;
}

int Snake::getYpos()
{
    return s_Ypos;
}

void Snake::eat()
{
    SnakeCell newSnakeCell(body.back().getXpos(), body.back().getYpos());
    body.push_back(newSnakeCell);
}

void Snake::changeFacing(direction::Facing facing)
{
    s_facing = facing;
}

std::vector<SnakeCell> Snake::getBody()
{
    return body;
}