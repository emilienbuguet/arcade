#include <MenuGame.hpp>

#include <iostream>

arc::games::MenuGame::MenuGame()
    : m_props({"", "", ""})
    , m_isStarting(false)
    , m_isRunning(true)
{
}


arc::games::MenuGame::~MenuGame() = default;

void arc::games::MenuGame::useEvent(arc::Events event)
{
    if (event == arc::Exit)
        this->m_isRunning = false;
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::MenuGame::getObjects() const
{
    return {};
}

bool arc::games::MenuGame::isRunning() const
{
    return this->m_isRunning;
}

void arc::games::MenuGame::update()
{
    //todo update game state
}

const std::string arc::games::MenuGame::getUsername() const
{
    return this->m_props.username;
}

const arc::games::MenuProprieties arc::games::MenuGame::getProps() const
{
    return this->m_props;
}

bool arc::games::MenuGame::isStarting() const
{
    return this->m_isStarting;
}
