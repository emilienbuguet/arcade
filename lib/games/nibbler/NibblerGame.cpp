/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "NibblerGame.hpp"

arc::games::NibblerGame::NibblerGame()
    : snake(15, 8)
    , food()
    , n_speed(0)
{
    n_map = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X                              X",
        "X                              X",
        "X                              X",
        "X       XXXXXX    XXXXXX       X",
        "X       X              X       X",
        "X       X              X       X",
        "X       X              X       X",
        "X    XXXX              XXXX    X",
        "X                              X",
        "X                              X",
        "X             XXXX             X",
        "X             XXXX             X",
        "X             XXXX             X",
        "X    XXXX     XXXX     XXXX    X",
        "X                              X",
        "X                              X",
        "X       X     XXXX     X       X",
        "X       X     XXXX     X       X",
        "X       X     XXXX     X       X",
        "X    XXXX     XXXX     XXXX    X",
        "X                              X",
        "X                              X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
    };
    n_clock = clock();
    spawnFood();
}

arc::games::NibblerGame::~NibblerGame()
{

}

void arc::games::NibblerGame::useEvent(arc::Events event)
{
    if (event == arc::KeyUp)
        snake.changeFacing(direction::Facing::UP);
    if (event == arc::KeyLeft)
        snake.changeFacing(direction::Facing::LEFT);
    if (event == arc::KeyRight)
        snake.changeFacing(direction::Facing::RIGHT);
    if (event == arc::KeyDown)
        snake.changeFacing(direction::Facing::DOWN);
    if (event == arc::KeyEsc)
        this->m_isRunning = false;
}

void arc::games::NibblerGame::update()
{
    if (clock() - n_clock >= 250000 - n_speed) {
        n_clock = clock();
        snake.moveSnake();
        if (n_map[snake.getYpos()][snake.getXpos()] == 'X' || snake.hasPrevPosition(snake.getXpos(), snake.getYpos()))
            this->m_isRunning = false;
        snake.updateOldFacing();

        if (snake.getYpos() == food.getYpos() && snake.getXpos() == food.getXpos()) {
            snake.eat();
            this->m_score += 100;
            n_speed += 400;
            spawnFood();
        }
    }
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::NibblerGame::getObjects() const
{
    std::vector<std::shared_ptr<arc::Object>> objects;
    std::vector<std::shared_ptr<arc::Object>> snakeObj(snake.getObjects());
    arc::Sprite sprite("map", arc::Vector(0, 0));
    objects.push_back(std::make_shared<arc::Sprite>(sprite));
    objects.insert(std::end(objects), std::begin(snakeObj), std::end(snakeObj));
    objects.push_back(std::make_shared<arc::Sprite>(arc::Sprite("food", arc::Vector(food.getXpos(), food.getYpos()), 1, 1)));
    return objects;
}

void arc::games::NibblerGame::spawnFood()
{
    int x = rand() % 32;
    int y = rand() % 24;
    while (n_map[y][x] == 'X' || snake.hasPosition(x, y) == true) {
        x = rand() % 32;
        y = rand() % 24;
    }
    food.setPos(x, y);
}