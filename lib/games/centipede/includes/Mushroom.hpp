/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Mushroom
*/

#pragma once

#include <Object.hpp>

namespace arc::games::centipede {

    class Mushroom : public arc::Sprite
    {
    public:
        /**
         * @brief Construct a new Mushroom object
         *
         */
        Mushroom(int x, int y);
        /**
         * @brief Destroy the Mushroom object
         *
         */
        ~Mushroom();

        /**
         * @brief Update the state of the object
         *
         */
        void update();

        /**
         * @brief
         *
         * @param life
         */
        void setlife(int life);

        /**
         * @brief
         *
         * @return int
         */
        int getlife();

        /**
         * @brief check if the object is dead
         *
         */
        void checkDead();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool isDead() const;

    private:
        /**
         * @brief Life of mushroom
         *
         */
        int life;
        /**
         * @brief
         *
         */
        bool m_isDead;
    };
}