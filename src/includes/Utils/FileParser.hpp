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
             * @brief Get the all the available libraries
             *
             * @param path path to the lib directory
             * @return std::vector<std::string>
             */
            static std::array<std::vector<std::string>, 2> getAllLibraries(const std::string& path = "./lib/");
    }; /* class FileParser */

} /* namespace arc::utils */
