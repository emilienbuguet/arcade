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
        auto gameobj = std::make_shared<arc::games::menu::MenuItem>(game, Vector(8, 8 + 2 * i), 25, arc::Color{arc::Color::WHITE});
        m_games.push_back(gameobj);
    }
    for (size_t i = 0; i < displays.size(); i++) {
        std::string display = displays[i].substr(displays[i].find_last_of("/") + 1);
        display = display.substr(display.find_first_of("_") + 1, display.find_last_of(".") - display.find_first_of("_") - 1);
        auto displayobj = std::make_shared<arc::games::menu::MenuItem>(display, Vector(18, 8 + 2 * i), 25, arc::Color {arc::Color::WHITE });
        m_displays.push_back(displayobj);
    }
    m_displays[0]->setSelected(true);
    m_games[0]->setSelected(true);
    m_props.gamelib = m_games[0]->getValue();
    m_props.graphicslib = m_displays[0]->getValue();
    m_ui.push_back(std::make_shared<arc::games::menu::MenuItem>("Username: ", Vector(8, 20), 25, arc::Color { arc::Color::WHITE }));
    m_ui.push_back(std::make_shared<arc::games::menu::MenuItem>("(Max: 12 characters)", Vector(8, 21), 12, arc::Color { arc::Color::WHITE }));
}

arc::games::MenuGame::~MenuGame() = default;

void arc::games::MenuGame::useCharacterEvent(arc::Events event)
{
    switch (event) {
        case arc::Events::KeyA:
            m_props.username += "a";
            break;
        case arc::Events::KeyB:
            m_props.username += "b";
            break;
        case arc::Events::KeyC:
            m_props.username += "c";
            break;
        case arc::Events::KeyD:
            m_props.username += "d";
            break;
        case arc::Events::KeyE:
            m_props.username += "e";
            break;
        case arc::Events::KeyF:
            m_props.username += "f";
            break;
        case arc::Events::KeyG:
            m_props.username += "g";
            break;
        case arc::Events::KeyH:
            m_props.username += "h";
            break;
        case arc::Events::KeyI:
            m_props.username += "i";
            break;
        case arc::Events::KeyJ:
            m_props.username += "j";
            break;
        case arc::Events::KeyK:
            m_props.username += "k";
            break;
        case arc::Events::KeyL:
            m_props.username += "l";
            break;
        case arc::Events::KeyM:
            m_props.username += "m";
            break;
        case arc::Events::KeyN:
            m_props.username += "n";
            break;
        case arc::Events::KeyO:
            m_props.username += "o";
            break;
        case arc::Events::KeyP:
            m_props.username += "p";
            break;
        case arc::Events::KeyQ:
            m_props.username += "q";
            break;
        case arc::Events::KeyR:
            m_props.username += "r";
            break;
        case arc::Events::KeyS:
            m_props.username += "s";
            break;
        case arc::Events::KeyT:
            m_props.username += "t";
            break;
        case arc::Events::KeyU:
            m_props.username += "u";
            break;
        case arc::Events::KeyV:
            m_props.username += "v";
            break;
        case arc::Events::KeyW:
            m_props.username += "w";
            break;
        case arc::Events::KeyX:
            m_props.username += "x";
            break;
        case arc::Events::KeyY:
            m_props.username += "y";
            break;
        case arc::Events::KeyZ:
            m_props.username += "z";
            break;
        case arc::Events::KeyDel:
            if (m_props.username.size() > 0)
                m_props.username.pop_back();
            break;
        default:
            break;
    }
    if (m_props.username.size() > 12)
        m_props.username.pop_back();
}

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
    this->useCharacterEvent(event);
}

void arc::games::MenuGame::update()
{
    for (auto& obj : m_games) {
        auto item = std::static_pointer_cast<arc::games::menu::MenuItem>(obj);
        if (item->isSelected())
            item->setColor(arc::Color { 255, 255, 0, this->isSelectingGame() ? uint8_t(255) : uint8_t(190), arc::Color::YELLOW });
        else
            item->setColor(arc::Color { 255, 255, 255, this->isSelectingGame() ? uint8_t(255) : uint8_t(190), arc::Color::WHITE });
    }
    for (auto& obj : m_displays) {
        auto item = std::static_pointer_cast<arc::games::menu::MenuItem>(obj);
        if (item->isSelected())
            item->setColor(arc::Color { 255, 255, 0, this->isSelectingGame() ? uint8_t(190) : uint8_t(255), arc::Color::YELLOW });
        else
            item->setColor(arc::Color { 255, 255, 255, this->isSelectingGame() ? uint8_t(190) : uint8_t(255), arc::Color::WHITE });
    }
    if (this->m_ui.size() > 0)
        this->m_ui[0]->setValue("Username: " + this->m_props.username);
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
    for (auto obj : m_ui) {
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
