/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "NibblerGame.hpp"

arc::games::NibblerGame::NibblerGame()
    : snake(std::make_shared<arc::games::Snake>(15, 8))
    , n_highScore(0)
    , n_lives(0)
    , n_timeLeft(0)
    , n_map({ "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
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
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" })
    , n_clock(clock())
    , n_foods({})
    , n_speed(0)
{
    n_foods.push_back(std::make_shared<arc::games::Food>(n_map, snake));
    n_foods.push_back(std::make_shared<arc::games::Food>(n_map, snake));
}

arc::games::NibblerGame::~NibblerGame() = default;

void arc::games::NibblerGame::useEvent(arc::Events event)
{
    if (event == arc::KeyUp)
        snake->changeFacing(direction::Facing::UP);
    if (event == arc::KeyLeft)
        snake->changeFacing(direction::Facing::LEFT);
    if (event == arc::KeyRight)
        snake->changeFacing(direction::Facing::RIGHT);
    if (event == arc::KeyDown)
        snake->changeFacing(direction::Facing::DOWN);
    if (event == arc::KeyEsc)
        this->m_isRunning = false;
}

void arc::games::NibblerGame::update()
{
    if (clock() - n_clock >= 250000 - n_speed) {
        n_clock = clock();
        snake->moveSnake();
        if (n_map[snake->getYpos()][snake->getXpos()] == 'X' || snake->hasPrevPosition(snake->getXpos(), snake->getYpos()))
            this->m_isRunning = false;
        snake->updateOldFacing();

        if (snake->getYpos() == n_foods[0]->getYpos() && snake->getXpos() == n_foods[0]->getXpos()) {
            snake->eat();
            this->m_score += 100;
            n_speed += 400;
            std::reverse(n_foods.begin(), n_foods.end());
            n_foods.pop_back();
            n_foods.push_back(std::make_shared<arc::games::Food>(n_map, snake));
            std::reverse(n_foods.begin(), n_foods.end());
        }
        if (snake->getYpos() == n_foods[1]->getYpos() && snake->getXpos() == n_foods[1]->getXpos()) {
            snake->eat();
            this->m_score += 100;
            n_speed += 400;
            n_foods.pop_back();
            n_foods.push_back(std::make_shared<arc::games::Food>(n_map, snake));
        }
    }
    if (clock() - n_foods[0]->getClock() >= 10000000 - n_speed * 100) {
        std::reverse(n_foods.begin(), n_foods.end());
        n_foods.pop_back();
        n_foods.push_back(std::make_shared<arc::games::Food>(n_map, snake));
        std::reverse(n_foods.begin(), n_foods.end());
    }
    if (clock() - n_foods[1]->getClock() >= 10000000 - n_speed * 100) {
        n_foods.pop_back();
        n_foods.push_back(std::make_shared<arc::games::Food>(n_map, snake));
    }
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::NibblerGame::getObjects() const
{
    std::vector<std::shared_ptr<arc::Object>> objects;
    std::vector<std::shared_ptr<arc::Object>> snakeObj(snake->getObjects());
    arc::Sprite sprite("nibbler/map", arc::Vector(0, 0));
    objects.push_back(std::make_shared<arc::Sprite>(sprite));
    objects.insert(std::end(objects), std::begin(snakeObj), std::end(snakeObj));
    objects.push_back(std::make_shared<arc::Sprite>(arc::Sprite("nibbler/food", arc::Vector(n_foods[0]->getXpos(), n_foods[0]->getYpos()), 1, 1)));
    objects.push_back(std::make_shared<arc::Sprite>(arc::Sprite("nibbler/food", arc::Vector(n_foods[1]->getXpos(), n_foods[1]->getYpos()), 1, 1)));
    return objects;
}