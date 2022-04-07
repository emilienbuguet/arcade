#include <Sfml.hpp>

extern "C" {
    arc::display::SfmlDisplay* arc::display::createInstance() {
        return (new arc::display::SfmlDisplay{});
    }
}
