/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#pragma once
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Snake.hpp"
#include "Direction.hpp"

class Nibbler {
    public:
        Nibbler();
        ~Nibbler();
        void init();
        void update();
        void display();
        void handle_input(int c);

    private:
        WINDOW *n_box;
        Snake snake;
        int n_highScore;
        int n_score;
        int n_lives;
        int n_timeLeft;
        clock_t n_clock;
        int getHighScore();
};
