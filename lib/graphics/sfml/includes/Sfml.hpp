#include <SfmlDisplay.hpp>
#include <exception>
#include <string>

#pragma once

namespace arc::display {

    extern "C" {
        /**
         * @brief Create a new instance of the SfmlDisplay
         *
         * @return SfmlDisplay* - A pointer to the new instance
         */
        SfmlDisplay *createInstance();
    } /* extern "C" */

}; /* namespace arc::display */
