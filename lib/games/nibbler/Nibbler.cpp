#include "Nibbler.hpp"

extern "C" {
arc::games::NibblerGame* arc::games::createInstance()
{
    return (new arc::games::NibblerGame {});
}
}