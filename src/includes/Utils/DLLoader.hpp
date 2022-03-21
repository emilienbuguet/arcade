#include <Error.hpp>

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <string>

#pragma once

namespace arc {

    /**
     * @brief Loads shared libraries of games or displays
     *
     * @tparam T
     */
    template <class T>
    class DLLoader {
        public:

            /**
             * @brief load a new library
             *
             * @param pathToLib path to the lib to be loaded
             */
            DLLoader() = default;

            /**
             * @brief unload the library
             *
             */
            ~DLLoader() = default;

            void load(const std::string &path)
            {
                this->free();
                this->l_lib = dlopen(path.c_str(), RTLD_NOW | RTLD_LOCAL);
                if (!l_lib)
                    throw new arc::Error("Could not open lib: " + path);
                void* func = dlsym(this->l_lib, "createInstance");
                if (func == NULL)
                    throw new arc::Error("Wrong lib format: " + path);
                l_instance = reinterpret_cast<T* (*)()>(func)();
            }

            void free()
            {
                if (this->l_instance)
                    delete l_instance;
                if (this->l_lib)
                    dlclose(this->l_lib);
                l_instance = nullptr;
                l_lib = nullptr;
            }

            /**
             * @brief Get the loaded instance
             *
             * @return Pointer to the loaded instance
             */
            T *getInstance() const
            {
                return l_instance;
            }

            /**
             * @brief Get the loaded instance
             *
             * @return Pointer to the loaded instance
             */
            T* operator->() const
            {
                return l_instance;
            }

        private:
            /**
             * @brief currently loaded lib
             *
             */
            void *l_lib;

            /**
             * @brief Instance of the loaded lib class
             *
             */
            T* l_instance;

    }; /* class DLOpener */

} /* namespace arc */
