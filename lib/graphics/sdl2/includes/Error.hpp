#include <exception>
#include <string>

#pragma once

namespace arc::display {

    /**
     * @brief Error class of Sdl2 library
     *
     */
    class Sdl2Error : public std::exception {
    public:
        /**
         * @brief Create a new Sdl2Error
         *
         * @param message error message
         */
        Sdl2Error(const std::string& message);

        /**
         * @brief Destroy the Sdl 2 Error object
         *
         */
        ~Sdl2Error();

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

    }; /* class Sdl2Error */

} /* namespace arc::display */