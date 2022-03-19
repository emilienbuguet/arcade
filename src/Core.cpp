#include <Core.hpp>
#include <Utils/DLLoader.hpp>
#include <Utils/FileParser.hpp>

#include <iostream>

arc::Core::Core(const std::string& lib)
    : c_game(nullptr)
    , c_display(nullptr)
    , displayName(arc::utils::FileParser::getLibraryName(lib))
    , gameName("")
{
    arc::DLLoader<arc::display::IDisplayModule> disp { lib };
    this->c_display = disp.getInstance("createInstance");
    std::cout << "Core built on lib " + displayName + "!" << std::endl;
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
