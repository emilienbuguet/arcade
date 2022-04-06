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

            /**
             * @brief check if cell after is not mushroom
             *
             * @param mushrooms
             */
            void hit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

            /**
             * @brief check if dir = down and if we go left or right
             *
             * @param mushrooms = list of mushroom
             */
            void pickADir(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

            /**
             * @brief check if direction = left or right if we can go down or go in oposite direction
             *
             * @param mushrooms
             */
            void pickASideDir(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

            /**
             * @brief
             *
             * @param mushrooms
             * @return true
             * @return false
             */
            bool hasRightMushroom(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

            /**
             * @brief
             *
             * @param mushrooms
             * @return true
             * @return false
             */
            bool hasLeftMushroom(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

            /**
             * @brief
             *
             * @param mushrooms
             * @return true
             * @return false
             */
            bool hasDownMushroom(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms);

            /**
             * @brief Getter for the direction of the object
             *
             * @return Direction
             */
            Direction getDirection() const;

            /**
             * @brief Getter for the type of the Cell
             *
             * @return Type
             */
            Type getCellType() const;

            /**
             * @brief Setter for the direction of the Cell
             *
             * @param dir
             */
            void setDirection(Direction dir);


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