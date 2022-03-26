/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Centipede
*/

#include <CentipedeGame.hpp>

#include <cstdlib>

arc::games::Centipede::Centipede()
    : AGame()
    , snakes({})
    , mushrooms({})
    , player(nullptr)
{
    this->player = std::make_unique<arc::games::centipede::Player>(arc::games::centipede::Player{});
    this->snakes.push_back(std::make_shared<arc::games::centipede::Snake>(arc::games::centipede::Snake{10, 16, 0}));
    for (int i = 0; i < 19; i++) {
        int nb1 = 0, nb2 = 0, nb3 = 0;
        nb1 = rand() % 32;
        this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(arc::games::centipede::Mushroom{nb1, i}));
        for (; nb2 == nb1; nb2 = rand() % 32);
        this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(arc::games::centipede::Mushroom{nb2, i}));
        for (; nb2 == nb || nb3 == nb1; nb = rand() % 32);
        this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(arc::games::centipede::Mushroom{nb3, i}));
    }
}

arc::games::Centipede::~Centipede()
{
}
