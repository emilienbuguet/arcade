/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#pragma once
#include "Direction.hpp"
#include "Snake.hpp"
#include <AGame.hpp>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <Food.hpp>

namespace arc::games {
class NibblerGame : public AGame {
public:
    /**
     * @brief Construct a new Nibbler Game object
     *
     */
    NibblerGame();

    /**
     * @brief Destroy the Nibbler Game object
     *
     */
    ~NibblerGame();

    /**
     * @brief Apply the current event
     *
     * @param event
     */
    void useEvent(arc::Events event) final;

    /**
     * @brief Updates game's entities
     *
     */
    void update() final;

    /**
     * @brief Get the game objects
     *
     * @return Game objects
     */
    const std::vector<std::shared_ptr<arc::Object>> getObjects() const final;


private:
    Snake snake;
    int n_highScore;
    int n_score;
    int n_lives;
    int n_timeLeft;
    std::vector<std::string> n_map;
    clock_t n_clock;
    Food food;
    int n_speed;

    /**
     * @brief Spawns a food
     *
     */
    void spawnFood();
};
} // namespace arc::games