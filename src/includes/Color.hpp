#include <cstdint>
#include <iostream>

#pragma once

namespace arc {

    /**
     * @brief Represents a color
     *
     */
    struct Color {
        /**
         * @brief Default types
         *
         */
        enum ColorType
        {
            RED,
            GREEN,
            BLUE,
            YELLOW,
            MAGENTA,
            CYAN,
            WHITE,
            BLACK,
        };

        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
        ColorType color;

        /**
         * @brief Construct a new Color object
         *
         * @param r red value (0-255)
         * @param g green value) (0-255)
         * @param b blue value (0-255)
         * @param a opacity value (0-255)
         * @param color
         */
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, ColorType color);

        /**
         * @brief Construct a new Color object
         *
         * @param type Color type
         */
        Color(ColorType type);
    }; /* struct Color */

} /* namespace arc */

std::ostream& operator<<(std::ostream& os, arc::Color& c);
