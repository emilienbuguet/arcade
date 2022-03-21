#include <Error.hpp>

#include <iostream>

arc::Error::Error(const std::string &message)
    : e_message(message)
{
}

arc::Error::~Error() = default;

const char *arc::Error::what() const noexcept
{
    return this->e_message.c_str();
}
