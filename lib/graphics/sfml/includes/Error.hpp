#include <exception>
#include <string>

#pragma once

namespace arc::display {

/**
 * @brief Error class of Sfml library
 *
 */
class SfmlError : public std::exception {
public:
    /**
     * @brief Create a new SfmlError
     *
     * @param message error message
     */
    SfmlError(const std::string& message);

    /**
     * @brief Destroy the Sdl 2 Error object
     *
     */
    ~SfmlError();

    /**
     * @brief Get the error message
     *
     * @return const char*
     */
    const char* what() const noexcept final;

private:
    /**
     * @brief Error message
     *
     */
    const std::string& e_message;

}; /* class SfmlError */

} /* namespace arc::display */