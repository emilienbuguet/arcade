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

void arc::Core::run()
{
    while (this->c_game->isRunning()) {
        arc::Events event = this->c_display->getEvent();
        this->c_game->useEvent(event);
        this->c_game->update();
        this->c_display->drawObjects(this->c_game->getObjects());
    }
    std::cout << "Core finished running!" << std::endl;
}
