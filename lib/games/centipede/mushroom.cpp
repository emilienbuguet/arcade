/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** mushroom
*/

#include <Centipede.hpp>

arc::game::Mushroom::Mushroom()
{
    int i = 0;

    for (; i < 20; i++)
    {
        mushrooms.push_back(arc::game::mushroomData{});
        mushrooms[i].x = (rand() % 25) * 25;
        mushrooms[i].y = (rand() % 25) * 25;
        mushrooms[i].width = 25;
        mushrooms[i].height = 25;
        mushrooms[i].life = 5;
    }
}

arc::game::Mushroom::~Mushroom()
{

}