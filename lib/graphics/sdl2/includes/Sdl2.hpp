#include <Sdl2Display.hpp>

#pragma once

namespace arc::display {

    extern "C" {
        /**
         * @brief Create a Instance of the Sdl2Display class
         *
         * @return std::unique_ptr<Sdl2Display> - pointer to an instance of the class
         */
        std::shared_ptr<Sdl2Display> createInstance();
    } /* extern "C" */
}; /* namespace arc::display */
