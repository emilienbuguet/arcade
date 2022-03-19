#include "Sdl2Display.hpp"

#include <iostream>


arc::display::Sdl2Display::Sdl2Display()
{

}

arc::display::Sdl2Display::~Sdl2Display() = default;

void arc::display::Sdl2Display::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    std::cout << "Draw objects here ..." << std::endl;
}

arc::Events arc::display::Sdl2Display::getEvent() const
{
    return arc::None;
}
