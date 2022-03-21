#include <Sdl2.hpp>

#include <iostream>
#include <memory>

extern "C" {

    arc::display::Sdl2Display* arc::display::createInstance()
    {
        return (new arc::display::Sdl2Display{});
    }

};
