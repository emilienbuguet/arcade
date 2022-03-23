#pragma once

#include <Interfaces/IGameModule.hpp>
#include <Object.hpp>
#include "Snake.hpp"

#include <iostream>

namespace arc::games {

    class Centipede : public arc::games::IGameModule {
        public:
            /**
             * @brief Construct a new Centipede object
             *
             */
            Centipede();

            /**
             * @brief Destroy the Centipede object
             *
             */
            ~Centipede();
            /**
             * @brief Create a Snake object
             *
             * @param size
             * @param x
             * @param y
             */
            void CreateSnake(int size, int x, int y);
            /**
             * @brief move the Centipede Snakes
             *
             */
            void MoveSnakes();
            void MovePlayer();
        private:
            std::vector<arc::games::Player> player;
            std::vector<arc::games::Snake> snakes;
            std::vector<arc::Object> entities;

    };

    struct mushroomData
    {
        /**
         * @brief position of cell in x axis
         *
         */
        int x;
        /**
         * @brief position of cell in y axis
         *
         */
        int y;
        /**
         * @brief width of cell
         *
         */
        int width;
        /**
         * @brief heigth of cell
         *
         */
        int height;
        /**
         * @brief life of cell
         *
         */
        int life;
    }
    class Mushroom {
        public:
            /**
             * @brief Construct a new Mushroom object
             *
             */
            Mushroom();
            /**
             * @brief Destroy the Mushroom object
             *
             */
            ~Mushroom();

        private:
            /**
             * @brief map of mushroom
             *
             */
            std::vector<arc::games::mushroomData> mushrooms;
    }
};
