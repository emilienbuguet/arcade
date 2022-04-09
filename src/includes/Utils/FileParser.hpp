#include <array>
#include <string>
#include <vector>

#pragma once

namespace arc::utils {

    /**
     * @brief Handles file manipulation
     *
     */
    class FileParser {
        public:

            /**
             * @brief Get the name of a .so arcade library
             *
             * @param pathToLib full path to the target library
             * @return std::string
             */
            static std::string getLibraryName(const std::string &pathToLib);

            /**
             * @brief Get the names of all libraries in a list
             *
             */
            static std::vector<std::string> getLibrariesNames(const std::vector<std::string> libs);

            /**
             * @brief Get the all the available libraries
             *
             * @param path path to the lib directory
             * @return std::vector<std::string>
             */
            static std::array<std::vector<std::string>, 2> getAllLibraries(const std::string& path = "./lib/");

            /**
             * @brief Checks if given library is a display or not
             *
             * @param libName name of the library
             * @return true if it is a display
             */
            static bool isDisplayLibrary(const std::string libName);
    }; /* class FileParser */

} /* namespace arc::utils */
