#include <string>

#pragma once

namespace arc {

    /**
     * @brief Represents a drawable object
     *
     */
    struct Object {

        /**
         * @brief type of the object
         *
         */
        enum Type { TEXT, SPRITE };

        /**
         * @brief name of the object asset (SPRITE)
         *
         */
        const std::string value;

        /**
         * @brief position of the object on the x axis (0 is left side of screen)
         *
         */
        unsigned int x;

        /**
         * @brief position of the object on the y axis (0 is top of screen)
         *
         */
        unsigned int y;
    };

}
