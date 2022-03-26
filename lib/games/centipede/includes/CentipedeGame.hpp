#pragma once

#include <AGame.hpp>
#include <Mushroom.hpp>
#include <Player.hpp>
#include <Snake.hpp>

#include <iostream>
#include <memory>
#include <vector>

namespace arc::games {


    class Centipede : public arc::games::AGame {
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
            std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes;
            std::unique_ptr<arc::games::centipede::Player> player;
            std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms;
    };
};
