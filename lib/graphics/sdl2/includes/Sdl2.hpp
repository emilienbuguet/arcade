#include <Sdl2Display.hpp>

#include <exception>
#include <string>

#pragma once

namespace arc::display {

    extern "C" {
        /**
         * @brief Create a Instance of the Sdl2Display class
         *
         * @return Sdl2Display* - pointer to an instance of the class
         */
        Sdl2Display *createInstance();
    } /* extern "C" */

}; /* namespace arc::display */
