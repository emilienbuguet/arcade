#include <Core.hpp>
#include <Utils/DLLoader.hpp>
#include <Utils/FileParser.hpp>

#include <Menu.hpp>

#include <iostream>

arc::Core::Core(const std::string& lib)
    : c_game()
    , c_display()
    , displayName(arc::utils::FileParser::getLibraryName(lib))
    , gameName("menu")
{
    c_display.load(lib);
    c_game.load("./lib/arcade_menu.so");
    std::cout << "Core built on lib " + displayName + "!" << std::endl;
}

arc::Core::~Core() = default;

void arc::Core::run()
{
    std::cout << static_cast<void *>(this->c_game.getInstance()) << std::endl;
    while (!this->c_game.getInstance()->isRunning()) {
         arc::Events event = this->c_display->getEvent();
         this->c_game->useEvent(event);
         this->c_game->update();
         this->c_display->drawObjects(this->c_game->getObjects());
    }
    std::cout << "Core finished running!" << std::endl;
}
