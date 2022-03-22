#include <AGame.hpp>

arc::games::AGame::AGame(int score)
    : m_score(score)
    , m_isRunning(true)
    , m_objects({})
{
}

arc::games::AGame::~AGame() = default;

int arc::games::AGame::getScore() const
{
    return this->m_score;
}

bool arc::games::AGame::isRunning() const
{
    return this->m_isRunning;
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::AGame::getObjects() const
{
    return this->m_objects;
}
