#include <iostream>
#include <string>

#include <Core.hpp>


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "arcade: Wrong amount of arguments." << std::endl;
        return 84;
    }
    try {
    arc::Core core(argv[1]);
        core.run();
    } catch (std::exception e) {
        //todo better error handling with our own class
        std::cout << std::string("arcade: ") + e.what() << std::endl;
        return 84;
    }
}
