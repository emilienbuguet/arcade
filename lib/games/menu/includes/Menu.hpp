#include <MenuGame.hpp>

#include <exception>
#include <string>

#pragma once

namespace arc::games {

    /**
     * @brief Create a Instance of the MenuGame class
     *
     * @return MenuGame* - pointer to an instance of the class
     */
    extern "C" {
        MenuGame *createInstance();
    }; /* extern "C" */

}; /* namespace arc::display */
