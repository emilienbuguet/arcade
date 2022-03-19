#include <Core.hpp>
#include <Utils/DLLoader.hpp>
#include <Utils/FileParser.hpp>

#include <iostream>


arc::Core::Core(const std::string &lib)
    : c_game(nullptr)
    , c_display(nullptr)
    , displayName(arc::utils::FileParser::getLibraryName(lib))
    , gameName("")
{
    arc::DLLoader<arc::display::IDisplayModule> disp{lib};
    this->c_display = disp.getInstance("createInstance");
    std::cout << "Core built on lib " + displayName + "!" << std::endl;
}

arc::Core::~Core() = default;

void arc::Core::run()
{
    this->c_display->drawObjects(std::vector<std::shared_ptr<arc::Object>>({}));
    std::cout << "Core finished running!" << std::endl;
}
