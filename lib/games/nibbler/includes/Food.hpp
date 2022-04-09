#pragma once
#include <time.h>
#include <string>
#include "Snake.hpp"
namespace arc::games {
    class Food {
        public:
            Food(std::vector<std::string> map, std::shared_ptr<Snake> snake);
            ~Food();

            /**
             * @brief Get the Pos X object
             *
             * @return int
             */
            int getXpos() const;

            /**
             * @brief Get the Pos Y object
             *
             * @return int
             */
            int getYpos() const;

            /**
             * @brief Get the Clock object
             *
             * @return clock_t
             */
            clock_t getClock();

        private : int pos_x;
            int pos_y;
            clock_t f_clock;
    };
}