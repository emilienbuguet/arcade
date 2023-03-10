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
    , player(nullptr)
    , mushrooms({})
    , clock(std::clock())
    , shootClock(std::clock())
    , shootMoveClock(std::clock())
    , snakePopClock(std::clock())
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
    std::clock_t current = std::clock();

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

    if (event == arc::KeySpace && ((current - shootClock) / static_cast<float>(CLOCKS_PER_SEC) > 0.5))
    {
        this->player->createShoot();
        shootClock = current;
    }

}

void arc::games::Centipede::update()
{
    std::clock_t current = std::clock();
    std::clock_t current_s = std::clock();
    std::clock_t current_p = std::clock();

    for (auto &mush : this->mushrooms) {
        mush->checkDead();
        mush->update();
    }
    std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> newMushrooms;
    for (auto &mushroom : this->mushrooms)
    {
        if (!mushroom->isDead())
        {
            newMushrooms.push_back(mushroom);
        }
    }
    this->mushrooms = newMushrooms;

    if ((current - clock) / static_cast<float>(CLOCKS_PER_SEC) > 0.2)
    {
        for (auto &snake : this->snakes)
            snake->checkHit(this->mushrooms);
        for (auto &snake : this->snakes)
            snake->update();
        clock = current;
    }

    if ((current_s - shootMoveClock) / static_cast<float>(CLOCKS_PER_SEC) > 0.05)
    {
        shootMoveClock = current_s;
        for (auto &shoot : this->player->getShoots()) {
            shoot->checkHit(this->mushrooms, this->snakes);
            if (shoot->isHit()) {
                for (auto& snake : this->snakes) {
                    if (shoot->getHit(snake) != nullptr) {
                        auto touch = shoot->getHit(snake);
                        this->splitSnake(snake, touch);
                        break;
                    }
                }
                this->player->deleteShoot(shoot);
            }
        }
        player->update();
    }
    if (player->lose(this->mushrooms, this->snakes))
        this->m_isRunning = false;

    if ((current_p - snakePopClock) / static_cast<float>(CLOCKS_PER_SEC) > 30) {
        this->snakes.push_back(std::make_shared<arc::games::centipede::Snake>(arc::games::centipede::Snake{10, 16, 0}));
        snakePopClock = current_p;
    }
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::Centipede::getObjects() const
{
    std::vector<std::shared_ptr<arc::Object>> objs;
    std::vector<std::shared_ptr<arc::Object>> snakecells;
    std::vector<std::shared_ptr<arc::Object>> mushs;
    std::vector<std::shared_ptr<arc::Object>> shoots;

    objs.push_back(std::static_pointer_cast<arc::Object>(this->player));
    for (auto &snake : this->snakes)
        for (std::shared_ptr<arc::games::centipede::SnakeCell> &cell : snake->getCells())
            snakecells.push_back(std::static_pointer_cast<arc::Object>(cell));
    for (auto &mush : this->mushrooms)
        mushs.push_back(std::static_pointer_cast<arc::Object>(mush));
    for (auto &shoot : this->player->getShoots())
        shoots.push_back(std::static_pointer_cast<arc::Object>(shoot));
    objs.insert(objs.end(), snakecells.begin(), snakecells.end());
    objs.insert(objs.end(), mushs.begin(), mushs.end());
    objs.insert(objs.end(), shoots.begin(), shoots.end());
    return objs;
}

void arc::games::Centipede::splitSnake(std::shared_ptr<arc::games::centipede::Snake> snake, std::shared_ptr<arc::games::centipede::SnakeCell> cell)
{
    std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> snakeCells = snake->getCells();
    std::vector<std::shared_ptr<arc::games::centipede::SnakeCell>> newCells;
    auto it = std::find(snakeCells.begin(), snakeCells.end(), cell);

    this->m_score += 50;
    newCells.insert(newCells.end(), it + 1, snakeCells.end());
    this->mushrooms.push_back(std::make_shared<arc::games::centipede::Mushroom>(cell->getPosition().x, cell->getPosition().y));
    snakeCells.erase(it, snakeCells.end());
    if (newCells.size() > 0)
        newCells[0]->setCellType(arc::games::centipede::SnakeCell::HEAD);
    if (snakeCells.size() > 0) {
        snakeCells[0]->setCellType(arc::games::centipede::SnakeCell::HEAD);
    }
    this->snakes.push_back(std::make_shared<arc::games::centipede::Snake>(newCells));
    snake->setCells(snakeCells);
}
