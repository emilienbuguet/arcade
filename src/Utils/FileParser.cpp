#include <Utils/FileParser.hpp>

std::string arc::utils::FileParser::getLibraryName(const std::string &pathToLib)
{
    std::string lastPart = pathToLib.substr(pathToLib.find_last_of("_") + 1);
    return lastPart.substr(0, lastPart.find_last_of("."));
}
