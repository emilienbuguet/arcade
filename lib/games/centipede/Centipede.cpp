/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Centipede
*/

#include "Centipede.hpp"
#include "Snake.hpp"

arc::games::Centipede::Centipede()
{
    snakes.push_back(new arc::game::snake(15, 300, 0));
}

arc::games::Centipede::~Centipede()
{

}

void arc::games::Centipede::CreateSnake(int size, int x, int y)
{
    snakes.push_back(new arc::game::snake(size, x, y));
}

void arc::games::Centipede::MoveSnakes()
{
    for (auto& snake : snakes) {
        if (snake.direction == LEFT )
            snake.x = snake.x - 25;
        if (snake.direction == RIGHT)
            snake.x = snake.x + 25;
        if (snake.direction == DOWN)
            snake.y = snake.y + 25;
    }
}

void arc::games::Centipede::MovePlayer()
{
    for (auto& player : player) {
        if (player.direction == LEFT)
            player.x = player.x - 25;
        if (player.direction == RIGHT)
            player.x = player.x + 25;
        if (player.direction == DOWN)
            player.y = player.y + 25;
        if (player.direction == UP)
            player.y = player.y - 25;
    }
}