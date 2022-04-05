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