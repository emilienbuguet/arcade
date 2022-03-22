#include <MenuGame.hpp>
#include <Utils/FileParser.hpp>

#include <iostream>

arc::games::MenuGame::MenuGame()
    : AGame(0)
    , m_props({"", "", ""})
    , m_isStarting(false)
{
    this->m_objects.push_back(std::make_shared<arc::Object>(arc::Object{
        "test", 200, 50, 0, 0
    }));
    auto tmp = arc::utils::FileParser::getAllLibraries("./lib");
    m_games = tmp[0];
    m_displays = tmp[1];
    std::cout << "Games:" << std::endl;
    for (auto lib : this->m_games)
        std::cout << lib << std::endl;
    std::cout << "Displays:" << std::endl;
    for (auto lib : this->m_displays)
        std::cout << lib << std::endl;
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
