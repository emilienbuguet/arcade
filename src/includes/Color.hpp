#include <cstdint>
#include <iostream>

#pragma once

namespace arc {

    /**
     * @brief Represents a color
     *
     */
    struct Color {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    }; /* struct Color */

} /* namespace arc */

std::ostream& operator<<(std::ostream& os, arc::Color& c);
