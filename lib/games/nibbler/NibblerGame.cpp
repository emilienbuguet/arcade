/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "NibblerGame.hpp"

arc::games::NibblerGame::NibblerGame()
    : snake(16, 8)
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
    if (clock() - n_clock >= 100000) {
        n_clock = clock();
        snake.moveSnake();
        if (n_map[snake.getYpos()][snake.getXpos()] == 'X') {
            std::cout << "skake hitted the wall starfullah " << std::endl;
            this->m_isRunning = false;
        }
    }
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::NibblerGame::getObjects() const
{
    std::vector<std::shared_ptr<arc::Object>> objects;
    std::vector<std::shared_ptr<arc::Object>> snakeObj(snake.getObjects());
    arc::Sprite sprite("map", arc::Vector(0, 0), 26, 32);
    //add food
    objects.push_back(std::make_shared<arc::Sprite>(sprite));
    objects.insert(std::end(objects), std::begin(snakeObj), std::end(snakeObj));
    return objects;
}