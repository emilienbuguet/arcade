/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** mushroom
*/

#include <Centipede.hpp>

arc::games::centipede::Mushroom::Mushroom(int x, int y)
    : arc::Sprite("centipede_mushroom_4", arc::Vector{x, y})
    , life(4)
{
}

arc::games::centipede::Mushroom::~Mushroom() = default;

void arc::games::centipede::Mushroom::update()
{
    this->setValue(std::string("centipede_mushroom_") + std::to_string(life));
}
