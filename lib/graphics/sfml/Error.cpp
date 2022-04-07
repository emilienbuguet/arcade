#include <Error.hpp>

#include <iostream>

arc::display::SfmlError::SfmlError(const std::string& message)
    : e_message(message)
{
    std::cout << e_message << std::endl;
}

arc::display::SfmlError::~SfmlError() = default;

const char* arc::display::SfmlError::what() const noexcept
{
    return this->e_message.c_str();
}
