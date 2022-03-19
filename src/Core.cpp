#include <Core.hpp>
#include <DLLoader.hpp>

#include <iostream>


arc::Core::Core(const std::string &lib)
    : c_game(nullptr)
    , c_display(nullptr)
    , displayName(lib.c_str())
    , gameName("")
{
    arc::DLLoader<arc::display::IDisplayModule> disp{lib};
    this->c_display = disp.getInstance("createInstance");
    std::cout << "Core built!" << std::endl;
}

arc::Core::~Core() = default;

void arc::Core::run()
{
    this->c_display->drawObjects(std::vector<std::shared_ptr<arc::Object>>({}));
    std::cout << "Core finished running!" << std::endl;
}
