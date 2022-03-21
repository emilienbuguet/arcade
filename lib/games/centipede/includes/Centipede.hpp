#pragma once

#include <IGameModule.hpp>
#include <Object.hpp>

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

        private:
            std::vector<arc::Object> entities;

    };


    struct SnakeCells
    {
        /**
         * @brief Define what is cell
         *
         */
        enum Type { HEAD, BODY };

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
        Type type;
    };

    class Snake {
        public:
            /**
             * @brief Construct a new Snake object
             *
             */
            Snake();
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
            /**
             * @brief Size of snake
             *
             */
            int size;
    };
};
