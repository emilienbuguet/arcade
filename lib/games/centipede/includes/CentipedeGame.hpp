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

            /**
             * @brief Split the snake if it is hit by a shot
             *
             * @param snake Snake to split
             * @param cell Cell to split at
             */
            void splitSnake(std::shared_ptr<arc::games::centipede::Snake> snake, std::shared_ptr<arc::games::centipede::SnakeCell> cell);

        private : std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes;
            std::shared_ptr<arc::games::centipede::Player> player;
            std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms;
            std::clock_t clock;
            std::clock_t shootClock;
            std::clock_t shootMoveClock;
    };
};
