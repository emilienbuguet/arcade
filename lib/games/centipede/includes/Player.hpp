/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

#pragma once

#include <iostream>
#include "Centipede.hpp"

namespace arc::games {
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
            checkCell(arc::games::Mushroom::mushrooms);
        protected:
        private:
            enum DIRECTION {LEFT, UP, RIGHT, DOWN, STAY};
            int x;
            int y;
            int height;
            int width;
            DIRECTION dir;
    };
}
