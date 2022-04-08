#include <iostream>
#include <string>

#include <Core.hpp>
#include <Error.hpp>


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "USAGE:" << std::endl;
        std::cerr << "\t\t ./arcade display_lib" << std::endl;
        return 84;
    }
    try {
    arc::Core core(argv[1]);
        core.run();
    } catch (arc::Error *e) {
        std::cout << std::string("arcade: ") + e->what() << std::endl;
        return 84;
    } catch (std::exception *e) {
        std::cout << std::string("error: ") + e->what() << std::endl;
        return 84;
    }
}
