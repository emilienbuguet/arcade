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
class SnakeCell {
    public:
        SnakeCell(int x, int y);
        ~SnakeCell();

        /**
         * @brief Set the position of the snake cell
         *
         * @param x
         * @param y
         */
        void setPos(int x, int y);

        /**
         * @brief Set the position of the previous
         *
         */
        void setPrevPos(int x, int y);

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
         * @brief Get the Axis of the cell
         *
         * @return Horizontal or Vertical
         */
        direction::axis getAxis();

        /**
         * @brief Set the axis object
         *
         * @param axis
         */
        void setAxis(direction::axis axis);

        /**
         * @brief Get a sharedPointer of object
         *
         * @return std::shared_ptr<arc::Object>
         */
        const std::shared_ptr<arc::Object> getObject() const;

        /**
         * @brief Update the Axis variable
         *
         */
        void updateAxis();

    private :
        int sc_Xpos;
        int sc_Ypos;
        int sc_prevXpos;
        int sc_prevYpos;
        direction::axis sc_axis;
};
}