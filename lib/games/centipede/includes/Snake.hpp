/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Snake
*/

#pragma once

#include "Centipede.hpp"


namespace arc::games {
    class SnakeCell
    {
    public:
        /**
         * @brief Construct a new check Cell object
         *
         */
        checkCell(arc::games::Mushroom::mushrooms);

    private:
        /**
         * @brief Direction of cell
         *
         */
        enum Direction
        {
            LEFT,
            RIGHT,
            DOWN
        };
        /**
         * @brief Define what is cell
         *
         */
        enum Type
        {
            HEAD,
            BODY
        };

        /**
         * @brief Origin of cell on x axis
         *
         */
        int x;
        /**
         * @brief Origin of cell on y axis
         *
         */
        int y;
        /**
         * @brief Size of cell on x axis
         *
         */
        int width;
        /**
         * @brief Size of cell on y axis
         *
         */
        int height;
        /**
         * @brief Type
         *
         */
        Type type;
        /**
         * @brief DIRECTION
         *
         */
        Direction direction;
    };

    class Snake
    {
    public:
        /**
         * @brief Construct a new Snake object
         *
         */
        Snake(int size, int x, int y);
        /**
         * @brief Destroy the Snake object
         *
         */
        ~Snake();

    private:
        /**
         * @brief Array of cell = Snake
         *
         */
        std::vector<arc::games::SnakeCells> snake;
    };
}