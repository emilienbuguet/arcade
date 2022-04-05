#pragma once

#include <AGame.hpp>
#include <Mushroom.hpp>
#include <Player.hpp>
#include <Snake.hpp>

#include <ctime>
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

            /**
             * @brief Handle the given event
             *
             * @param event
             */
            void useEvent(arc::Events event) override;

            /**
             * @brief Update the game entities
             *
             */
            void update() override;

            /**
             * @brief Get the Objects object
             *
             * @return const std::vector<std::shared_ptr<arc::Object>>
             */
            const std::vector<std::shared_ptr<arc::Object>> getObjects() const override;

        private:
            std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes;
            std::shared_ptr<arc::games::centipede::Player> player;
            std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms;
            std::clock_t clock;
    };
};
