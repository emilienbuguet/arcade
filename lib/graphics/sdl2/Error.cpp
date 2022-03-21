#include <Error.hpp>

#include <iostream>

arc::display::Sdl2Error::Sdl2Error(const std::string& message)
    : e_message(message)
{
    std::cout << e_message << std::endl;
}

arc::display::Sdl2Error::~Sdl2Error() = default;

const char* arc::display::Sdl2Error::what() const noexcept
{
    return this->e_message.c_str();
}
