#include <string>

#pragma once

namespace arc::utils {

    class FileParser {
        public:
            /**
             * @brief Get the name of a .so arcade library
             *
             * @param pathToLib full path to the target library
             * @return std::string
             */
            static std::string getLibraryName(const std::string &pathToLib);
    }; /* class FileParser */

} /* namespace arc::utils */
