#include <Color.hpp>

arc::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, ColorType color)
    : r(r)
    , g(g)
    , b(b)
    , a(a)
    , color(color)
{
}

arc::Color::Color(ColorType type)
    : r(0)
    , g(0)
    , b(0)
    , a(0)
    , color(type)
{
    switch (type)
    {
    case RED:
        r = 255;
        g = 0;
        b = 0;
        a = 255;
        break;
    case GREEN:
        r = 0;
        g = 255;
        b = 0;
        a = 255;
        break;
    case BLUE:
        r = 0;
        g = 0;
        b = 255;
        a = 255;
        break;
    case YELLOW:
        r = 255;
        g = 255;
        b = 0;
        a = 255;
        break;
    case MAGENTA:
        r = 255;
        g = 0;
        b = 255;
        a = 255;
        break;
    case CYAN:
        r = 0;
        g = 255;
        b = 255;
        a = 255;
        break;
    case WHITE:
        r = 255;
        g = 255;
        b = 255;
        a = 255;
        break;
    case BLACK:
        r = 0;
        g = 0;
        b = 0;
        a = 255;
        break;
    }
}

std::ostream& operator<<(std::ostream& os, arc::Color& c)
{
    os << "rgba(" << static_cast<int>(c.r) << "," << static_cast<int>(c.g) << "," << static_cast<int>(c.b) << "," << static_cast<int>(c.a) << ")";
    return os;
}
