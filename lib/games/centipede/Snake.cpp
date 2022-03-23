/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Snake
*/

#include "Centipede.hpp"
#include "Snake.hpp"

arc::games::Snake::Snake(int size, int x, int y)
{
    int i = 0;
    int tmp = 0;

    for (; i < size - 1; i++, tmp += 25)
    {
        snake.push_back(arc::games::SnakeCell{});
        snake[i].x = x + tmp;
        snake[i].y = y;
        snake[i].width = 25;
        snake[i].height = 25;
        if (i == 0)
            snake[i].type = snake[i].HEAD
        else
            snake[i].type = snake[i].BODY;
    }
}

arc::games::Snake::~Snake()
{

}

arc::games::SnakeCells::CheckCell(arc::games::Mushroom::mushrooms)
{
    bool isChecking = true;

    for (auto mushroom : mushrooms) {
        if ((direction == DOWN) && (x + 25 == mushroom.x && y == mushroom.y))
            isChecking = false;
        if ((direction == DOWN) && (x - 25 == mushroom.x && y + 25 == mushroom.y))
            isChecking = false;
        if ((direction == LEFT) && (x - 25 == mushroom.x && x - 25 < 0) && (y == mushroom.y))
            isChecking = false;
        if ((direction == RIGHT) && (x + 25 == mushroom.x && x + 25 < 0) && (y == mushroom.y))
            isChecking = false;
    }
    if (ifChecking == false && direction == LEFT) {
        direction = DOWN;
        isChecking = true;
    }
    if (ifChecking == false && direction == RIGHT) {
        direction = DOWN;
        isChecking = true;
    }
    if (ifChecking == false && direction == DOWN) {
        for (auto mushroom : mushrooms)
        {
            if ((x - 25 == mushroom.x && x - 25 < 0) && (y == mushroom.y))
                direction = LEFT;
            if ((x + 25 == mushroom.x && x + 25 < 0) && (y == mushroom.y))
                direction = RIGHT;
        }
    }
}