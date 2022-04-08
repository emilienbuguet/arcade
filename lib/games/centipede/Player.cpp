/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-arcade-marvin.flamand
** File description:
** Player
*/

#include <Player.hpp>
#include <vector>
#include <memory>

/************* Shoot **************/

arc::games::centipede::Shoot::Shoot(int x, int y)
    : arc::Sprite("centipede/shoot", arc::Vector{x, y})
    , m_isHit(false)
{
}

arc::games::centipede::Shoot::~Shoot() = default;

void arc::games::centipede::Shoot::Update()
{
    this->setPosition(arc::Vector{this->getPosition().x, this->getPosition().y - 1});
}

std::shared_ptr<arc::games::centipede::SnakeCell> arc::games::centipede::Shoot::getHit(std::shared_ptr<arc::games::centipede::Snake> snake)
{
    auto pos = this->getPosition();
    for (auto &cell : snake->getCells()) {
        if (cell->getPosition().x == pos.x && cell->getPosition().y == pos.y - 1) {
            return cell;
        }
    }

    return nullptr;
}

void arc::games::centipede::Shoot::checkHit(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms, std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes)
{
    auto pos = this->getPosition();
    for (auto &snake : snakes) {
        for (auto &cell : snake->getCells()) {
            if (cell->getPosition().x == pos.x && cell->getPosition().y == pos.y - 1) {
                this->m_isHit = true;
            }
        }
    }
    for (auto &mushroom : mushrooms) {
        if (mushroom->getPosition().x == pos.x && mushroom->getPosition().y == pos.y - 1) {
            mushroom->setlife(mushroom->getlife() - 1);
            this->m_isHit = true;
        }
    }
    if (pos.y - 1 < 0)
        this->m_isHit = true;
}

bool arc::games::centipede::Shoot::isHit() const
{
    return this->m_isHit;
}

/************* Player **************/

arc::games::centipede::Player::Player()
    : arc::Sprite("centipede/player", arc::Vector{16, 19})
    , dir(arc::games::centipede::Player::STAY)
    , shoots({})
{
}

arc::games::centipede::Player::~Player() = default;

void arc::games::centipede::Player::move(arc::games::centipede::Player::Direction dir)
{
    if (dir == arc::games::centipede::Player::LEFT && this->getPosition().x - 1 >= 0)
        this->setPosition(arc::Vector{this->getPosition().x - 1, this->getPosition().y});
    if (dir == arc::games::centipede::Player::RIGHT && this->getPosition().x + 1 < 32)
        this->setPosition(arc::Vector{this->getPosition().x + 1, this->getPosition().y});
    if (dir == arc::games::centipede::Player::UP && this->getPosition().y - 1 > 19)
        this->setPosition(arc::Vector{this->getPosition().x, this->getPosition().y - 1});
    if (dir == arc::games::centipede::Player::DOWN && this->getPosition().y + 1 <= 24)
        this->setPosition(arc::Vector{this->getPosition().x, this->getPosition().y + 1});
}

void arc::games::centipede::Player::createShoot()
{
    this->shoots.push_back(std::make_shared<arc::games::centipede::Shoot>(arc::games::centipede::Shoot{this->getPosition().x, this->getPosition().y}));
}

std::vector<std::shared_ptr<arc::games::centipede::Shoot>> arc::games::centipede::Player::getShoots()
{
    return this->shoots;
}

void arc::games::centipede::Player::update(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms, std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes)
{
    for (auto &shoot : this->shoots) {
        shoot->checkHit(mushrooms, snakes);
        shoot->Update();
    }
    std::vector<std::shared_ptr<arc::games::centipede::Shoot>> newShoots;
    for (auto& shoot : this->shoots) {
        if (!shoot->isHit()) {
            newShoots.push_back(shoot);
        }
    }
    this->shoots = newShoots;
}
