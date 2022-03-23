/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

#pragma once

#include <iostream>
#include "Centipede.hpp"

namespace arc::games::centipede {
    class Player {
        public:
            /**
             * @brief Construct a new Player object
             *
             */
            Player();
            /**
             * @brief Destroy the Player object
             *
             */
            ~Player();
            /**
             * @brief Direction of the Player
             *
             */
            enum Direction {LEFT, UP, RIGHT, DOWN, STAY};
        private:
            /**
             * @brief Position of the player
             *
             */
            Direction dir;
    };
}
