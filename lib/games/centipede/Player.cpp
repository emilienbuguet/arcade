/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

#include <Player.hpp>

arc::games::centipede::Player::Player()
    : arc::Sprite("centipede_player", arc::Vector{16, 19})
    , dir(arc::games::centipede::Player::STAY)
{
}

arc::games::centipede::Player::~Player() = default;

void arc::games::centipede::Player::move(arc::games::centipede::Player::Direction dir)
{
    if (dir == arc::games::centipede::Player::LEFT && this->getPosition().x - 1 >= 0)
        this->setPosition(arc::Vector{this->getPosition().x - 1, this->getPosition().y});
    if (dir == arc::games::centipede::Player::RIGHT && this->getPosition().x + 1 < 32)
        this->setPosition(arc::Vector{this->getPosition().x + 1, this->getPosition().y});
    if (dir == arc::games::centipede::Player::UP && this->getPosition().y - 1 > 19)
        this->setPosition(arc::Vector{this->getPosition().x, this->getPosition().y - 1});
    if (dir == arc::games::centipede::Player::DOWN && this->getPosition().y + 1 <= 24)
        this->setPosition(arc::Vector{this->getPosition().x, this->getPosition().y + 1});
}