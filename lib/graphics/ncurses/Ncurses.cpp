#include "Ncurses.hpp"

extern "C" {

arc::display::NcursesDisplay *arc::display::createInstance()
{
    return (new arc::display::NcursesDisplay {});
}
};