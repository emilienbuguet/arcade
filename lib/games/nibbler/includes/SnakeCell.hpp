/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SnakeCell
*/

#pragma once
#include "Direction.hpp"
#include <memory>
#include "Object.hpp"

namespace arc::games {
class SnakeCell : public Sprite{
    public:
        SnakeCell(int x, int y);
        ~SnakeCell();

        /**
         * @brief Set the position of the previous
         *
         */
        void setPrevPos();

        /**
         * @brief Get the x position
         *
         * @return int
         */
        int getXpos();

        /**
         * @brief Get the y position
         *
         * @return int
         */
        int getYpos();

        /**
         * @brief Get the previous x position
         *
         * @return int
         */
        int getPrevXpos();

        /**
         * @brief Get the previous y position
         *
         * @return int
         */
        int getPrevYpos();

        /**
         * @brief Update the Axis variable
         *
         */
        void updateAxis();

    private :
        int sc_prevXpos;
        int sc_prevYpos;
};
}
