#pragma once

#include <Centipede.hpp>
#include <Object.hpp>
#include <iostream>

namespace arc::games::centipede  {
    class SnakeCell : public arc::Sprite
    {
        public:
            /**
             * @brief Type of the Cell
             *
             */
            enum Type { HEAD, BODY};

            /**
             * @brief Construct a new Snake Cell object
             *
             * @param x position of the Cell on the x axis
             * @param y position of the Cell on the y axiss
             * @param type type of the Cell
             */
            SnakeCell(int x, int y, Type type);

            /**
             * @brief Destroy the Snake Cell object
             *
             */
            ~SnakeCell();

        private:
            int x;
            int y;
            Type type;
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
        std::vector<arc::games::centipede::SnakeCell> snake;
    };
}