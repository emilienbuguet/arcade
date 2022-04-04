/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler() :
    snake(5, 0)
{
    initscr();
    nodelay(stdscr, TRUE);
    //n_box = subwin(stdscr, 25, 50, (LINES / 2) - 25, (COLS / 2) - 25);
}

Nibbler::~Nibbler()
{
    endwin();
}

void Nibbler::init()
{
    //box(n_box, ACS_VLINE, ACS_HLINE);
    refresh();
    n_highScore = getHighScore();
    n_score = 0;
    n_lives = 3;
    n_timeLeft = 990;
    n_clock = clock();
}

int Nibbler::getHighScore()
{
    std::ifstream file;
    file.open(".score");
    if (!file.is_open())
        return 0;
    std::string score;
    getline(file, score);
    return (stoi(score));
}

void Nibbler::handle_input(int c)
{
    if (c == KEY_UP)
        snake.changeFacing(direction::Facing::UP);
    else if (c == KEY_DOWN)
        snake.changeFacing(direction::Facing::DOWN);
    else if (c == KEY_RIGHT)
        snake.changeFacing(direction::Facing::RIGHT);
    else if (c == KEY_LEFT)
        snake.changeFacing(direction::Facing::LEFT);
}

void Nibbler::update()
{
    int time = clock() - n_clock;
    if (time > 100) {
        n_clock = clock();
        snake.moveSnake();
        //clear();
    }
}

void Nibbler::display()
{
    mvprintw(snake.getXpos(), snake.getYpos(), "O");
    for (SnakeCell &snakeCell : snake.getBody()) {
        mvprintw(snakeCell.getXpos(), snakeCell.getYpos(), "o");
    }
}

int main()
{
    Nibbler nibbler;

    nibbler.init();
    int c;

    while (true) {
        if ((c = getch()) != ERR)
            nibbler.handle_input(c);
        nibbler.update();
        nibbler.display();
    }

    return 0;
}