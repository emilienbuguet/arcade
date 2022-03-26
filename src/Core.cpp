#include <Core.hpp>
#include <Utils/DLLoader.hpp>
#include <Utils/FileParser.hpp>

#include <Menu.hpp>

#include <iostream>

arc::Core::Core(const std::string& lib)
    : c_game("./lib/arcade_menu.so")
    , c_display(lib)
    , currentDisplay(arc::utils::FileParser::getLibraryName(lib))
    , currentGame("menu")
{
    std::cout << "Core built on lib " + currentDisplay + "!" << std::endl;
    auto libs = arc::utils::FileParser::getAllLibraries("./lib");
    this->c_games = libs[0];
    this->c_displays = libs[1];
}

arc::Core::~Core() = default;

bool arc::Core::useEvent(arc::Events event)
{
    //todo catch lib changing events here...
    return false;
}

void arc::Core::run()
{
    arc::Events event = arc::None;
    while (this->c_game->isRunning()) {
        event = this->c_display->getEvent();
        if (!this->useEvent(event))
            this->c_game->useEvent(event);
        this->c_game->update();
        this->c_display->drawObjects(this->c_game->getObjects());
    }
    if (this->currentGame == "menu" && event != arc::Exit) {
        auto props = static_cast<arc::games::MenuGame*>(this->c_game.getInstance())->getProps();
        this->c_game.load("./lib/arcade_" + props.gamelib + ".so");
        this->c_display.load("./lib/arcade_" + props.graphicslib + ".so");
        this->run();
    }
    std::cout << "Core finished running!" << std::endl;
}
