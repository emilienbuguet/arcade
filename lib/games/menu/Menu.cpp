#include <Menu.hpp>

extern "C" {
    arc::games::MenuGame *arc::games::createInstance()
    {
        return (new arc::games::MenuGame {});
    }
}
