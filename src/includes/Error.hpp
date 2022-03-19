#include <exception>
#include <string>

#pragma once

namespace arc {
class Error : public std::exception {
    public:
        /**
         * @brief Construct a new Error object
         *
         * @param message error message
         */
        Error(const std::string &message);

        /**
         * @brief Destroy the Error object
         *
         */
        ~Error();

        /**
         * @brief Gets the error message
         *
         * @return const char* error message
         */
        const char *what() const noexcept final;

    private:
        const std::string &e_message;
}; /* class arc::Error */
} /* namespace arc */
