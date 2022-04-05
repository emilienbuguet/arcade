#pragma once

#include <Object.hpp>

#include <ctime>
#include <iostream>
#include <vector>
#include <memory>
namespace arc::games::centipede  {
    class SnakeCell : public arc::Sprite
    {
        public:
            /**
             * @brief Type of the Cell
             *
             */
            enum Type { HEAD, BODY };
            /**
             * @brief direction of the Cell
             *
             */
            enum Direction { DOWN, LEFT, RIGHT };
            /**
             * @brief Construct a new Snake Cell object
             *
             * @param x position of the Cell on the x axis
             * @param y position of the Cell on the y axiss
             * @param type type of the Cell
             */
            SnakeCell(int x, int y, Type type, Direction dir = DOWN);

            /**
             * @brief Destroy the Snake Cell object
             *
             */
            ~SnakeCell();

            /**
             * @brief Move the snake cell
             *
             */
            void move();
            /**
             * @brief Update the state of the Cell
             *
             */
            void update();

        private:
            int x;
            int y;
            int frame;
            Type type;
            Direction dir;
    };

    std::string &operator<<(std::string& s, arc::games::centipede::SnakeCell::Direction& d);

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

        /**
         * @brief Get the Cells object
         *
         * @return std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>>
         */
        std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> getCells() const;

        /**
         * @brief Update the state of the Snake
         *
         */
        void update();

        /**
         * @brief If sprite hit something
         *
         */
        void checkHit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

    private:
        /**
         * @brief Array of cell = Snake
         *
         */
        std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> cells;
    };
}