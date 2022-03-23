#include <CentipedeGame.hpp>

#pragma once

namespace arc::games {

    extern "C" {
        /**
         * @brief Create a new Instance of Centipede game
         *
         * @return Centipede* - Pointer to an instance of Centipede game
         */
        Centipede* createInstance();
    }; /* extern "C" */

}; // namespace arc::games
