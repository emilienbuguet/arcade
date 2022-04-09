/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Snake
*/

#include "Snake.hpp"

arc::games::Snake::Snake(int x, int y)
    : s_Xpos(x)
    , s_Ypos(y)
    , s_facing(direction::Facing::RIGHT)
    , s_OldFacing(direction::Facing::RIGHT)
    , body({})
{
    body.push_back(SnakeCell(x - 1, y));
    body.push_back(SnakeCell(x - 2, y));
    body.push_back(SnakeCell(x - 3, y));
}

arc::games::Snake::~Snake()
{
}

void arc::games::Snake::moveSnake()
{
    body[0].setPosition(arc::Vector(s_Xpos, s_Ypos));
    if (s_facing == direction::Facing::UP)
        s_Ypos -= 1;
    if (s_facing == direction::Facing::RIGHT)
        s_Xpos += 1;
    if (s_facing == direction::Facing::DOWN)
        s_Ypos += 1;
    if (s_facing == direction::Facing::LEFT)
        s_Xpos -= 1;

    int size = body.size();
    body[0].updateAxis();
    for (int i = 1; i < size; i++) {
        body[i].setPosition(arc::Vector(body[i - 1].getPrevXpos(), body[i - 1].getPrevYpos()));
        body[i].updateAxis();
        body[i - 1].setPrevPos();
    }
    body[size - 1].setPrevPos();
}

int arc::games::Snake::getXpos()
{
    return s_Xpos;
}

int arc::games::Snake::getYpos()
{
    return s_Ypos;
}

void arc::games::Snake::eat()
{
    SnakeCell newSnakeCell(body.back().getXpos(), body.back().getYpos());
    body.push_back(newSnakeCell);
}

void arc::games::Snake::changeFacing(direction::Facing facing)
{
    if (facing == direction::Facing::UP && s_OldFacing == direction::Facing::DOWN)
        return;
    if (facing == direction::Facing::DOWN && s_OldFacing == direction::Facing::UP)
        return;
    if (facing == direction::Facing::LEFT && s_OldFacing == direction::Facing::RIGHT)
        return;
    if (facing == direction::Facing::RIGHT && s_OldFacing == direction::Facing::LEFT)
        return;
    if (s_facing == direction::Facing::UP && facing != direction::Facing::DOWN) {
        s_facing = facing;
        return;
    }
    if (s_facing == direction::Facing::RIGHT && facing != direction::Facing::LEFT) {
        s_facing = facing;
        return;
    }
    if (s_facing == direction::Facing::DOWN && facing != direction::Facing::UP) {
        s_facing = facing;
        return;
    }
    if (s_facing == direction::Facing::LEFT && facing != direction::Facing::RIGHT) {
        s_facing = facing;
        return;
    }
    return;
}

void arc::games::Snake::updateOldFacing()
{
    s_OldFacing = s_facing;
}

std::vector<arc::games::SnakeCell> arc::games::Snake::getBody()
{
    return body;
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::Snake::getObjects() const
{
    std::string name = "";
    switch (s_facing) {
        case direction::Facing::UP:
            name = "snake_head_up";
            break;
        case direction::Facing::RIGHT:
            name = "snake_head_right";
            break;
        case direction::Facing::DOWN:
            name = "snake_head_down";
            break;
        case direction::Facing::LEFT:
            name = "snake_head_left";
            break;
    }

    std::vector<std::shared_ptr<arc::Object>> objects;

    objects.push_back(std::make_shared<arc::Sprite>("nibbler/" + name, arc::Vector(s_Xpos, s_Ypos)));

    int size = body.size();
    for (int i = 0; i < size; i++)
        objects.push_back(std::static_pointer_cast<arc::Object>(std::make_shared<arc::Sprite>(body[i])));
    return objects;
}

bool arc::games::Snake::hasPosition(int x, int y)
{
    if (s_Xpos == x && s_Ypos == y)
        return true;
    int size = body.size();
    for (int i = 0; i < size; i++)
        if (body[i].getXpos() == x && body[i].getYpos() == y)
            return true;
    return false;
}

bool arc::games::Snake::hasPrevPosition(int x, int y)
{
    int size = body.size();
    for (int i = 0; i < size; i++)
        if (body[i].getPrevXpos() == x && body[i].getPrevYpos() == y)
            return true;
    return false;
}
