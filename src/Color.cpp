#include <Color.hpp>


std::ostream& operator<<(std::ostream& os, arc::Color& c)
{
    os << "rgba(" << static_cast<int>(c.r) << "," << static_cast<int>(c.g) << "," << static_cast<int>(c.b) << "," << static_cast<int>(c.a) << ")";
    return os;
}
