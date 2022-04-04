/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SnakeCell
*/

#pragma once

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

    private:
        int sc_Xpos;
        int sc_Ypos;
        int sc_prevXpos;
        int sc_prevYpos;
};