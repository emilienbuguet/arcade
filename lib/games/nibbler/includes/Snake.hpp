/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** snake
*/

#pragma once
#include "SnakeCell.hpp"
#include "Direction.hpp"
#include <vector>

namespace arc::games {
class Snake {
    public:
        Snake(int x, int y);
        ~Snake();

        /**
         * @brief move the snake by one cell, in 's_facing' direction
         *
         *
         */
        void moveSnake();

        /**
         * @brief add a body cell
         *
         */
        void eat();

        /**
         * @brief Get the x pos object
         *
         * @return int
         */
        int getXpos();

        /**
         * @brief Get the y pos object
         *
         * @return int
         */
        int getYpos();

        /**
         * @brief change the facing direction of the snake
         *
         */
        void changeFacing(direction::Facing facing);

        /**
         * @brief set the OldFacing to Facing
         *
         */
        void updateOldFacing();

        /**
         * @brief Get the Body object
         *
         * @return std::vector<SnakeCell>
         */
        std::vector<SnakeCell> getBody();

        /**
         * @brief get a vector of object of the whole snake
         *
         */
        const std::vector<std::shared_ptr<arc::Object>> getObjects() const;

        /**
         * @brief check if the snake has a cell at position (x, y)
         *
         * @param x X position
         * @param y Y position
         * @return true
         * @return false
         */
        bool hasPosition(int x, int y);

        /**
         * @brief check if the snake has a cell at previous position (x, y)
         *
         * @param x X position
         * @param y Y position
         * @return true
         * @return false
         */
        bool hasPrevPosition(int x, int y);

    private :
        int s_Xpos;
        int s_Ypos;
        direction::Facing s_facing;
        direction::Facing s_OldFacing;
        std::vector<SnakeCell> body;
};
}
