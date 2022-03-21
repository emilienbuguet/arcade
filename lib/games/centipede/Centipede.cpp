/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** main
*/

#include "Centipede.hpp"

arc::games::Centipede::Centipede()
{
}

arc::games::Centipede::~Centipede()
{

}

arc::games::Snake::Snake()
{
    int i = 0;
    int size = 10;
    int ax_x = 0;

    for (; i < size - 1; i++, ax_x += 25) {
            snake.push_back(arc::games::SnakeCells{});
            snake[i].x = ax_x;
            snake[i].y = 0;
            snake[i].width = 25;
            snake[i].height = 25;
        if (i == 0)
            snake[i].type = snake[i].HEAD;
        else
            snake[i].type = snake[i].BODY;
    }
}

arc::games::Snake::~Snake()
{

}