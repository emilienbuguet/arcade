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
        ColorType color;
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, ColorType color) : r(r), g(g), b(b), a(a), color(color) {}
        Color(ColorType type)
        {
            switch (type) {
            case RED:
                r = 255;
                g = 0;
                b = 0;
                a = 255;
                color = RED;
                break;
            case GREEN:
                r = 0;
                g = 255;
                b = 0;
                a = 255;
                color = GREEN;
                break;
            case BLUE:
                r = 0;
                g = 0;
                b = 255;
                a = 255;
                color = BLUE;
                break;
            case YELLOW:
                r = 255;
                g = 255;
                b = 0;
                a = 255;
                color = YELLOW;
                break;
            case MAGENTA:
                r = 255;
                g = 0;
                b = 255;
                a = 255;
                color = MAGENTA;
                break;
            case CYAN:
                r = 0;
                g = 255;
                b = 255;
                a = 255;
                color = CYAN;
                break;
            case WHITE:
                r = 255;
                g = 255;
                b = 255;
                a = 255;
                color = WHITE;
                break;
            case BLACK:
                r = 0;
                g = 0;
                b = 0;
                a = 255;
                color = BLACK;
                break;
            }
        }
    }; /* struct Color */

} /* namespace arc */

std::ostream& operator<<(std::ostream& os, arc::Color& c);
