#include <Core.hpp>
#include <Utils/DLLoader.hpp>
#include <Utils/FileParser.hpp>
#include <Vector.hpp>

#include <Menu.hpp>

#include <iostream>

arc::Core::Core(const std::string& lib)
    : c_game("./lib/arcade_menu.so")
    , c_display(lib)
    , currentDisplay(arc::utils::FileParser::getLibraryName(lib))
    , currentGame("menu")
    , c_highscore(std::make_unique<arc::utils::HighscoreHandler>())
    , c_score(0)
{
    std::cout << "Core built on lib " + currentDisplay + "!" << std::endl;
    std::cout << "Current game is " + currentGame + "!" << std::endl;
    auto libs = arc::utils::FileParser::getAllLibraries("./lib");
    this->c_games = libs[0];
    this->c_displays = libs[1];
    this->c_interface.push_back(std::make_shared<arc::Text>("Menu", Vector(920, 50), 40, arc::Color { arc::Color::WHITE }));
    this->c_interface.push_back(std::make_shared<arc::Sprite>("board", Vector(1920 / 2 - 401, 1080 / 2 - 301)));
    this->c_interface.push_back(std::make_shared<arc::Text>("Score: " + std::to_string(this->c_score), Vector(900, 950), 40, arc::Color { arc::Color::WHITE }));
    std::vector<std::shared_ptr<arc::Object>> scores = this->c_highscore->toObjects();
    for (size_t i = 0; i < scores.size(); i++) {
        this->c_interface.push_back(scores[i]);
    }
    this->c_interface.push_back(std::make_shared<arc::Text>("Keybindings",
                            arc::Vector{ 1550, 300 },
                            30,
                            arc::Color{ arc::Color::YELLOW }
                        ));
    this->c_interface.push_back(std::make_shared<arc::Text>("ESC to quit", Vector(1550, 400), 30, arc::Color { arc::Color::WHITE }));
    this->c_interface.push_back(std::make_shared<arc::Text>("ENTER to start", Vector(1520, 440), 30, arc::Color { arc::Color::WHITE }));
    this->c_games = arc::utils::FileParser::getLibrariesNames(this->c_games);
    this->c_displays = arc::utils::FileParser::getLibrariesNames(this->c_displays);
}

arc::Core::~Core()
{
    if (this->c_username != "") {
        this->c_highscore->addHighscore(this->c_username, this->c_score);
        this->c_highscore->saveHighscores();
    }
}

bool arc::Core::useEvent(arc::Events event)
{
    if (this->currentGame == "menu")
        return false;
    switch (event) {
        case arc::KeyA:
            this->previousGame();
            return true;
        case arc::KeyZ:
            this->nextGame();
            return true;
        case arc::KeyO:
            this->previousDisplay();
            return true;
        case arc::KeyP:
            this->nextDisplay();
            return true;
        default:
            return false;
    }
}

void arc::Core::run()
{
    arc::Events event = arc::None;
    while (this->c_game->isRunning()) {
        this->update();
        event = this->c_display->getEvent();
        if (!this->useEvent(event))
            this->c_game->useEvent(event);
        this->c_game->update();
        this->c_display->drawObjects(this->c_game->getObjects());
        this->c_display->drawInterface(this->c_interface);
    }
    if (this->currentGame == "menu" && event != arc::Exit && event != arc::KeyEsc) {
        auto props = static_cast<arc::games::MenuGame*>(this->c_game.getInstance())->getProps();
        if (this->currentDisplay != props.graphicslib)
            this->c_display.load("./lib/arcade_" + props.graphicslib + ".so");
        if (this->currentGame != props.gamelib)
            this->c_game.load("./lib/arcade_" + props.gamelib + ".so");
        this->c_username = props.username;
        this->currentGame = props.gamelib;
        this->currentDisplay = props.graphicslib;
        this->c_interface.pop_back();
        this->run();
    }
    std::cout << this->c_interface[c_interface.size() - 1]->getValue() << std::endl;
    std::cout << "Core finished running!" << std::endl;
}

void arc::Core::update()
{
    this->c_interface[0]->setValue(this->currentGame);
    this->c_interface[2]->setValue("Score: " + std::to_string(this->c_score + static_cast<arc::games::AGame*>(this->c_game.getInstance())->getScore()));
}

void arc::Core::nextGame()
{
    size_t i = 0;
    for (; i < this->c_games.size(); i++) {
        if (this->c_games[i] == this->currentGame)
            break;
    }
    this->c_score += static_cast<arc::games::AGame *> (this->c_game.getInstance())->getScore();
    this->currentGame = this->c_games[(i + 1) % this->c_games.size()];
    this->c_game.load("./lib/arcade_" + this->currentGame + ".so");
}

void arc::Core::previousGame()
{
    size_t i = 0;
    for (; i < this->c_games.size(); i++) {
        if (this->c_games[i] == this->currentGame)
            break;
    }
    this->c_score += static_cast<arc::games::AGame*>(this->c_game.getInstance())->getScore();
    this->currentGame = this->c_games[(i - 1 + this->c_games.size()) % this->c_games.size()];
    this->c_game.load("./lib/arcade_" + this->currentGame + ".so");
}

void arc::Core::nextDisplay()
{
    size_t i = 0;
    for (; i < this->c_displays.size(); i++) {
        if (this->c_displays[i] == this->currentDisplay)
            break;
    }
    this->currentDisplay = this->c_displays[(i + 1) % this->c_displays.size()];
    this->c_display.load("./lib/arcade_" + this->currentDisplay + ".so");
}

void arc::Core::previousDisplay()
{
    size_t i = 0;
    for (; i < this->c_displays.size(); i++) {
        if (this->c_displays[i] == this->currentDisplay)
            break;
    }
    this->currentDisplay = this->c_displays[(i - 1 + this->c_displays.size()) % this->c_displays.size()];
    this->c_display.load("./lib/arcade_" + this->currentDisplay + ".so");
}
