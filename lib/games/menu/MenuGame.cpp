#include <Color.hpp>
#include <MenuGame.hpp>
#include <MenuItem.hpp>
#include <Utils/FileParser.hpp>
#include <Vector.hpp>

#include <iostream>

arc::games::MenuGame::MenuGame()
    : AGame(0)
    , m_props({"", "", ""})
    , m_isStarting(false)
    , m_isSelectingGame(true)
{
    auto tmp = arc::utils::FileParser::getAllLibraries("./lib");
    std::vector<std::string> games = tmp[0];
    std::vector<std::string> displays = tmp[1];
    for (size_t i = 0; i < games.size(); i++) {
        std::string game = games[i].substr(games[i].find_last_of("/") + 1);
        game = game.substr(game.find_first_of("_") + 1, game.find_last_of(".") - game.find_first_of("_") - 1);
        auto gameobj = std::make_shared<arc::games::menu::MenuItem>(game, Vector(8, 8 + 2 * i), 25, arc::Color{255, 255, 255, 255});
        m_games.push_back(gameobj);
    }
    for (size_t i = 0; i < displays.size(); i++) {
        std::string display = displays[i].substr(displays[i].find_last_of("/") + 1);
        display = display.substr(display.find_first_of("_") + 1, display.find_last_of(".") - display.find_first_of("_") - 1);
        auto displayobj = std::make_shared<arc::games::menu::MenuItem>(display, Vector(18, 8 + 2 * i), 25, arc::Color{255, 255, 255, 255});
        m_displays.push_back(displayobj);
    }
    m_displays[0]->setSelected(true);
    m_games[0]->setSelected(true);
    m_props.gamelib = m_games[0]->getValue();
    m_props.graphicslib = m_displays[0]->getValue();
}

arc::games::MenuGame::~MenuGame() = default;

void arc::games::MenuGame::useEvent(arc::Events event)
{
    if (event == arc::Exit)
        this->m_isRunning = false;
    if (event == arc::KeyEsc)
        this->m_isRunning = false;
    if (event == arc::KeyEnter) {
        this->m_isStarting = true;
        this->m_isRunning = false;
    }
    if (event == arc::KeyUp) {
        if (m_isSelectingGame) {
            this->selectPreviousGame();
        } else {
            this->selectPreviousDisplay();
        }
    }
    if (event == arc::KeyDown) {
        if (m_isSelectingGame) {
            this->selectNextGame();
        } else {
            this->selectNextDisplay();
        }
    }
    if (event == arc::KeyRight) {
        this->m_isSelectingGame = false;
    }
    if (event == arc::KeyLeft) {
        this->m_isSelectingGame = true;
    }
}

void arc::games::MenuGame::update()
{
    for (auto& obj : m_games) {
        auto item = std::static_pointer_cast<arc::games::menu::MenuItem>(obj);
        if (item->isSelected())
            item->setColor(arc::Color{255, 255, 0, this->isSelectingGame() ? uint8_t(255) : uint8_t(190)});
        else
            item->setColor(arc::Color{255, 255, 255, this->isSelectingGame() ? uint8_t(255) : uint8_t(190)});
    }
    for (auto& obj : m_displays) {
        auto item = std::static_pointer_cast<arc::games::menu::MenuItem>(obj);
        if (item->isSelected())
            item->setColor(arc::Color{255, 255, 0, this->isSelectingGame() ? uint8_t(190) : uint8_t(255)});
        else
            item->setColor(arc::Color{255, 255, 255, this->isSelectingGame() ? uint8_t(190) : uint8_t(255)});
    }
}

const std::vector<std::shared_ptr<arc::Object>> arc::games::MenuGame::getObjects() const
{
    auto objects = std::vector<std::shared_ptr<arc::Object>>{};
    for (auto obj : m_games) {
        objects.push_back(obj);
    }
    for (auto obj : m_displays) {
        objects.push_back(obj);
    }
    return objects;
}

bool arc::games::MenuGame::isStarting() const
{
    return this->m_isStarting;
}

bool arc::games::MenuGame::isSelectingGame() const
{
    return this->m_isSelectingGame;
}

void arc::games::MenuGame::selectPreviousGame()
{
    if (!m_games[0]->isSelected())
        for (size_t i = 1; i < m_games.size(); i++) {
            if (m_games[i]->isSelected()) {
                m_games[i]->setSelected(false);
                m_games[i - 1]->setSelected(true);
                this->m_props.gamelib = m_games[i - 1]->getValue();
                break;
            }
        }
}

void arc::games::MenuGame::selectNextGame()
{
    if (!m_games[m_games.size() - 1]->isSelected())
        for (size_t i = 0; i < m_games.size() - 1; i++) {
            if (m_games[i]->isSelected()) {
                m_games[i]->setSelected(false);
                m_games[i + 1]->setSelected(true);
                this->m_props.gamelib = m_games[i + 1]->getValue();
                break;
            }
        }
}

void arc::games::MenuGame::selectPreviousDisplay()
{
    if (!m_displays[0]->isSelected())
        for (size_t i = 1; i < m_displays.size(); i++) {
            if (m_displays[i]->isSelected()) {
                m_displays[i]->setSelected(false);
                m_displays[i - 1]->setSelected(true);
                this->m_props.graphicslib = m_displays[i - 1]->getValue();
                break;
            }
        }
}

void arc::games::MenuGame::selectNextDisplay()
{
    if (!m_displays[m_displays.size() - 1]->isSelected())
        for (size_t i = 0; i < m_displays.size() - 1; i++) {
            if (m_displays[i]->isSelected()) {
                m_displays[i]->setSelected(false);
                m_displays[i + 1]->setSelected(true);
                this->m_props.graphicslib = m_displays[i + 1]->getValue();
                break;
            }
        }
}
