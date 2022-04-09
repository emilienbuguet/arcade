#include "Nibbler.hpp"

extern "C" {
arc::games::NibblerGame* arc::games::createInstance()
{
    srand((unsigned int)time(NULL));
    return (new arc::games::NibblerGame {});
}
}