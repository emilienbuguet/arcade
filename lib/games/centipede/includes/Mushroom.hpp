/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Mushroom
*/

#pragma once

#include <Object.hpp>

namespace arc::games::centipede {

    class Mushroom : public arc::Sprite
    {
    public:
        /**
         * @brief Construct a new Mushroom object
         *
         */
        Mushroom(int x, int y);
        /**
         * @brief Destroy the Mushroom object
         *
         */
        ~Mushroom();

        /**
         * @brief Update the state of the object
         *
         */
        void update();

    private:
        /**
         * @brief Life of mushroom
         *
         */
        int life;
    };
}