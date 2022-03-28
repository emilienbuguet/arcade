#include "NcursesDisplay.hpp"

#pragma once

namespace arc::display {

extern "C" {
/**
 * @brief Create a Instance of the Sdl2Display class
 *
 * @return Sdl2Display* - pointer to an instance of the class
 */
NcursesDisplay *createInstance();
} /* extern "C" */

}; /* namespace arc::display */