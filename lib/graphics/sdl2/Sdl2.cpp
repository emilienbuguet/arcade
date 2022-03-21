#include <Sdl2.hpp>

#include <iostream>
#include <memory>

extern "C" {

    std::shared_ptr<arc::display::Sdl2Display> arc::display::createInstance()
    {
        return std::make_shared<arc::display::Sdl2Display>(arc::display::Sdl2Display{});
    }

};
