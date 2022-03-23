/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

<<<<<<< HEAD
#include <Player.hpp>

arc::games::centipede::Player::Player()
    : arc::Sprite("centipede_player", arc::Vector{16, 19})
    , dir(arc::games::centipede::Player::STAY)
{
}

arc::games::centipede::Player::~Player()
{
=======
#include "Player.hpp"
#include "Snake.hpp"
#include "Centipede.hpp"

arc::games::Player::Player()
{
    x = 25 * 11;
    y = 25 * 22;
    height = 25;
    width = 25;$
    direction = STAY;
}

arc::games::Player::~Player()
{
}

arc::games::Player::checkCell(arc::games::Mushroom::mushrooms)
{
    bool isChecking = false;

    if ((direction == UP) && (x ))
>>>>>>> 87fad53 (Add centipede)
}