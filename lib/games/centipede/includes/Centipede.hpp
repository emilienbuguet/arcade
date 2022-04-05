#include <CentipedeGame.hpp>

#include <exception>
#include <string>

#pragma once

namespace arc::games
{

    /**
     * @brief Create a Instance of the Centipede class
     *
     * @return Centipede* - pointer to an instance of the class
     */
    extern "C"
    {
        Centipede *createInstance();
    }; /* extern "C" */

}; /* namespace arc::display */
