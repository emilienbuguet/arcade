#pragma once

#include <Centipede.hpp>
#include <Object.hpp>

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
             * @param size amount of Cells the Snake contains
             * @param x position of the head on the x axis
             * @param y position of the head on the y axis
             */
            Snake(int size, int x, int y);

            /**
             * @brief Destroy the Snake object
             *
             */
            ~Snake();

        private:
            std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> cells;
    };
}