#include <Error.hpp>

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <string>

#pragma once

namespace arc {

    template <class T>
    class DLLoader {
        public:

            /**
             * @brief load a new library
             *
             * @param pathToLib path to the lib to be loaded
             */
            DLLoader(const std::string& pathToLib)
                : l_lib(dlopen(pathToLib.c_str(), RTLD_LAZY | RTLD_LOCAL))
            {
            }

            /**
             * @brief unload the library
             *
             */
            ~DLLoader() = default;

            /**
             * @brief load an instance of the lib class
             *
             * @param name name of the builder function
             *
             */
            std::shared_ptr<T> getInstance(const std::string &name)
            {
                void *func = dlsym(this->l_lib, name.c_str());
                if (func == NULL) {
                    throw arc::Error("Wrong lib format: " + name);
                }

                return (reinterpret_cast<std::shared_ptr<T> (*)()>(func))();
            }

        private:
            /**
             * @brief currently loaded lib
             *
             */
            void *l_lib;

    }; /* class DLOpener */
} /* namespace arc */
