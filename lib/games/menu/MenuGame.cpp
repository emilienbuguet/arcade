#include <MenuGame.hpp>

#include <iostream>

arc::games::MenuGame::MenuGame()
    : m_props({"", "", ""})
    , m_isStarting(false)
{
}


arc::games::MenuGame::~MenuGame() = default;

void arc::games::MenuGame::useEvent(arc::Events event)
{
    //todo do something with event
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::MenuGame::getObjects() const
{
    return {};
}

bool arc::games::MenuGame::isRunning() const
{
    return false;
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
