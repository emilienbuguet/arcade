/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

#pragma once

#include <Object.hpp>
#include <Snake.hpp>
#include <Mushroom.hpp>
#include <iostream>

namespace arc::games::centipede {

    class Shoot : public arc::Sprite
    {
        public:
            /**
             * @brief Construct a new Shoot object
             *
             * @param x
             * @param y
             */
            Shoot(int x, int y);

            /**
             * @brief Destroy the Shoot object
             *
             */
            ~Shoot();

            /**
             * @brief Move the shoot
             *
             */
            void Update();

            /**
             * @brief check if cell after is not mushroom or snakes
             *
             * @param mushrooms
             * @param snakes
             */
            std::shared_ptr<arc::games::centipede::SnakeCell> getHit(std::shared_ptr<arc::games::centipede::Snake> snake);

            /**
             * @brief
             *
             * @param mushrooms
             * @param snakes
             * @return true
             * @return false
             */
            void checkHit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms, std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes);

            /**
             * @brief Tells if shoot has hit something or not
             *
             * @return true
             * @return false
             */
            bool isHit() const;

        private:
            bool m_isHit;
    };
    class Player : public arc::Sprite {
        public:
            /**
             * @brief Construct a new Player object
             *
             */
            Player();

            /**
             * @brief Destroy the Player object
             *
             */
            ~Player();

            /**
             * @brief Direction of the Player
             *
             */
            enum Direction {LEFT, UP, RIGHT, DOWN, STAY};

            /**
             * @brief Move the Player
             *
             */
            void move(Direction dir);

            /**
             * @brief Create a Shoot object
             *
             */
            void createShoot();
            /**
             * @brief Update the Player
             *
             */
            void update(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms, std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes);

            /**
             * @brief Get the Shoots object
             *
             * @return std::vector<std::shared_ptr<arc::games::centipede::Shoot>>
             */
            std::vector<std::shared_ptr<arc::games::centipede::Shoot>> getShoots();

            /**
             * @brief
             *
             * @param shoot
             */
            void deleteShoot(std::shared_ptr<arc::games::centipede::Shoot> &shoot);

            /**
             * @brief check if you lose
             *
             */
            bool lose(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms, std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes);

        private:
            /**
             * @brief Position of the player
             *
             */
            Direction dir;

            /**
             * @brief Vector of class shoot
             *
             */
            std::vector<std::shared_ptr<arc::games::centipede::Shoot>> shoots;
    };
}
