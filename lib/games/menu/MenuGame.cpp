#include <MenuGame.hpp>
#include <Utils/FileParser.hpp>

#include <iostream>

arc::games::MenuGame::MenuGame()
    : AGame(0)
    , m_props({"", "", ""})
    , m_isStarting(false)
{
   /* this->m_objects.push_back(std::make_shared<arc::Object>(arc::Sprite{
        "test", arc::Vector{200, 50}
    }));
    this->m_objects.push_back(std::make_shared<arc::Object>(arc::Sprite{
        "xhydra", arc::Vector{700, 200}
    }));*/
    auto tmp = arc::utils::FileParser::getAllLibraries("./lib");
    m_games = tmp[0];
    m_displays = tmp[1];
    for (size_t i = 0; i < this->m_games.size(); i++) {
        this->m_objects.push_back(std::make_shared<arc::Object>(arc::Text {
            this->m_games[i], arc::Vector{200, 50 * static_cast<int>(i)}, 14, arc::Text::Colors::white
        }));
    }
    for (size_t i = 0; i < this->m_displays.size(); i++) {
        this->m_objects.push_back(std::make_shared<arc::Object>(arc::Text {
            this->m_displays[i], arc::Vector{600, 50 * static_cast<int>(i)}, 14, arc::Text::Colors::white
        }));
    }
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
