<<<<<<< HEAD
#include <CentipedeGame.hpp>
#include <Centipede.hpp>

#include <cstdlib>
#include <ctime>

extern "C" {
    arc::games::Centipede *arc::games::createInstance()
    {
        std::srand(std::time(nullptr));
        return (new arc::games::Centipede {});
    }
}
