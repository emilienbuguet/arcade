#include <NibblerGame.hpp>

#include <exception>
#include <string>

#pragma once

namespace arc::games {

/**
 * @brief Create a Instance of the NibblerGame class
 *
 * @return std::unique_ptr<NibblerGame> - pointer to an instance of the class
 */
extern "C" {
NibblerGame *createInstance();
}; /* extern "C" */

}; /* namespace arc::display */