#include <Error.hpp>
#include <Utils/FileParser.hpp>

#include <dirent.h>
#include <iostream>

std::string arc::utils::FileParser::getLibraryName(const std::string &pathToLib)
{
    std::string lastPart = pathToLib.substr(pathToLib.find_last_of("_") + 1);
    return lastPart.substr(0, lastPart.find_last_of("."));
}

std::array<std::vector<std::string>, 2> arc::utils::FileParser::getAllLibraries(const std::string &path)
{
    struct dirent* d;
    DIR* dr;
    std::array<std::vector<std::string>, 2> result;

    dr = opendir(path.c_str());
    if (dr != NULL) {
        for (d = readdir(dr); d != NULL; d = readdir(dr)) {
            std::string tmp(d->d_name);
            if (tmp.ends_with(".so") && tmp != "arcade_menu.so") {
                if (tmp == "arcade_centipede.so" || tmp == "arcade_nibbler.so" ||
                    tmp == "arcade_pacman.so" || tmp == "arcade_qix.so" || tmp == "arcade_solarfox.so") {
                    result[0].push_back((path.ends_with("/") ? path : path + "/") + d->d_name);
                }
                if (tmp == "arcade_sfml.so" || tmp == "arcade_ndk++.so" || tmp == "arcade_aalib.so" || tmp == "arcade_libcaca.so"
                    || tmp == "arcade_allegro5.so" || tmp == "arcade_xlib.so" || tmp == "arcade_gtk+.so" || tmp == "arcade_irrlicht.so"
                    || tmp == "arcade_opengl.so" || tmp == "arcade_vulkan.so" || tmp == "arcade_qt5.so" || tmp == "arcade_ncurses.so"
                    || tmp == "arcade_sdl2.so") {
                    result[1].push_back((path.ends_with("/") ? path : path + "/") + d->d_name);
                }
            }
        }
        closedir(dr);
    } else {
        throw new arc::Error("Unable to open dir : " + path);
    }
    return result;
}
