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
    , m_isDead(false)
{
}

arc::games::centipede::Mushroom::~Mushroom() = default;

void arc::games::centipede::Mushroom::update()
{
    if (this->life > 0)
        this->setValue(std::string("centipede_mushroom_") + std::to_string(life));
}

void arc::games::centipede::Mushroom::setlife(int life)
{
    this->life = life;
}

int arc::games::centipede::Mushroom::getlife()
{
    return (this->life);
}

void arc::games::centipede::Mushroom::checkDead()
{
    if (this->life <= 0)
        this->m_isDead = true;
}

bool arc::games::centipede::Mushroom::isDead() const
{
    return this->m_isDead;
}