#include <MenuGame.hpp>

#include <iostream>

arc::games::MenuGame::MenuGame()
    : AGame(0)
    , m_props({"", "", ""})
    , m_isStarting(false)
{
}

arc::games::MenuGame::~MenuGame() = default;

void arc::games::MenuGame::useEvent(arc::Events event)
{
    if (event == arc::Exit)
        this->m_isRunning = false;
}

void arc::games::MenuGame::update()
{
    //todo update game state
}

const arc::games::MenuProprieties arc::games::MenuGame::getProps() const
{
    return this->m_props;
}

bool arc::games::MenuGame::isStarting() const
{
    return this->m_isStarting;
}
