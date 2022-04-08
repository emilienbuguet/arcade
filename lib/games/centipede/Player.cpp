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
    std::cout << "This pos is : " << pos.x << " " << pos.y << std::endl;
    std::cout << "Snake size is : " << snake->getCells().size() << std::endl;
    for (auto &cell : snake->getCells()) {
        std::cout << "Cell pos is : " << cell->getPosition().x << " " << cell->getPosition().y << std::endl;
        if (cell->getPosition().x == pos.x && cell->getPosition().y == pos.y - 1) {
            std::cout << "Hit !" << std::endl;
            this->m_isHit = true;
            return cell;
        }
    }

    std::cout << "Miss !" << std::endl;
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

void arc::games::centipede::Player::deleteShoot(std::shared_ptr<arc::games::centipede::Shoot>& shoot)
{
    this->shoots.erase(std::find(this->shoots.begin(), this->shoots.end(), shoot));
}

std::vector<std::shared_ptr<arc::games::centipede::Shoot>> arc::games::centipede::Player::getShoots()
{
    return this->shoots;
}

void arc::games::centipede::Player::update()
{
    for (auto &shoot : this->shoots) {
        shoot->Update();
    }
}

bool arc::games::centipede::Player::lose(std::vector<std::shared_ptr<arc::games::centipede::Mushroom>> mushrooms, std::vector<std::shared_ptr<arc::games::centipede::Snake>> snakes)
{
    for (auto &snake : snakes) {
        for (auto &cell : snake->getCells()) {
            if (cell->getPosition().x == this->getPosition().x && cell->getPosition().y == this->getPosition().y) {
                std::cout << "exit with snake player touch" << std::endl;
                return true;
            }
            if (cell->getPosition().y >= 24) {
                std::cout << "exit with snake out of box" << std::endl;
                return true;
            }
        }
    }
    for (auto &mushroom : mushrooms) {
        if (mushroom->getPosition().x == this->getPosition().x && mushroom->getPosition().y == this->getPosition().y) {
            std::cout << "exit with mushroom" << std::endl;
            return true;
        }
    }
    return false;
}
