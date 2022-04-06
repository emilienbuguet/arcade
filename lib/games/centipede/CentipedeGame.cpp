/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Centipede
*/

#include <CentipedeGame.hpp>

#include <cstdlib>
#include <memory>

arc::games::Centipede::Centipede()
    : AGame()
    , snakes({})
    , mushrooms({})
    , player(nullptr)
    , clock(std::clock())
{
    this->player = std::make_shared<arc::games::centipede::Player>(arc::games::centipede::Player{});
    this->snakes.push_back(std::make_shared<arc::games::centipede::Snake>(arc::games::centipede::Snake{10, 16, 0}));
    for (int i = 1; i < 19; i++) {
        int nb1 = rand() % 32, nb2 = rand() % 32, nb3 = rand() % 32;
        if (i == 1)
            nb1 = 16;
        this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(arc::games::centipede::Mushroom{nb1, i}));
        for (; nb2 == nb1 || nb2 == nb3; nb2 = rand() % 32);
        this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(arc::games::centipede::Mushroom{nb2, i}));
        for (;nb3 == nb1 || nb2 == nb3; nb3 = rand() % 32);
        this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(arc::games::centipede::Mushroom{nb3, i}));
    }
}

arc::games::Centipede::~Centipede() = default;


void arc::games::Centipede::useEvent(arc::Events event)
{
    if (event == arc::KeyEsc)
        this->m_isRunning = false;
    if (event == arc::KeyLeft)
        this->player->move(arc::games::centipede::Player::Direction::LEFT);
    if (event == arc::KeyRight)
        this->player->move(arc::games::centipede::Player::Direction::RIGHT);
    if (event == arc::KeyUp)
        this->player->move(arc::games::centipede::Player::Direction::UP);
    if (event == arc::KeyDown)
        this->player->move(arc::games::centipede::Player::Direction::DOWN);
}

void arc::games::Centipede::update()
{
    std::clock_t current = std::clock();

    for (auto &mush : this->mushrooms)
        mush->update();

    if ((current - clock)/static_cast<float>(CLOCKS_PER_SEC) > 0.2) {
        for (auto &snake : this->snakes)
            snake->checkHit(this->mushrooms);
        for (auto &snake : this->snakes)
            snake->update();
        clock = current;
    }
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::Centipede::getObjects() const
{
    std::vector<std::shared_ptr<arc::Object>> objs;
    std::vector<std::shared_ptr<arc::Object>> snakecells;
    std::vector<std::shared_ptr<arc::Object>> mushs;

    objs.push_back(std::static_pointer_cast<arc::Object>(this->player));
    for (auto &snake : this->snakes)
        for (std::shared_ptr<arc::games::centipede::SnakeCell> &cell : snake->getCells())
            snakecells.push_back(std::static_pointer_cast<arc::Object>(cell));
    for (auto &mush : this->mushrooms)
        mushs.push_back(std::static_pointer_cast<arc::Object>(mush));
    objs.insert(objs.end(), snakecells.begin(), snakecells.end());
    objs.insert(objs.end(), mushs.begin(), mushs.end());
    return objs;
}