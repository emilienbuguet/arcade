/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

#pragma once

#include <Object.hpp>
#include <iostream>

namespace arc::games::centipede {
    class Player : public arc::Sprite {
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
            /**
             * @brief Move the Player
             *
             */
            void move(Direction dir);
        private:
            /**
             * @brief Position of the player
             *
             */
            Direction dir;
    };
}
