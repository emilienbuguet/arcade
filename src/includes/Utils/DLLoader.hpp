#include <Error.hpp>

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <string>

#include <MenuGame.hpp>

#pragma once

namespace arc {

    /**
     * @brief Loads shared libraries of games or displays
     *
     * @tparam T IGameModule or IDisplayModule
     */
    template <class T>
    class DLLoader {
        public:

            /**
             * @brief Construct a new DLLoader
             *
             */
            DLLoader() = default;

            /**
             * @brief
             *
             * @param path path to the library to be loaded
             */
            DLLoader(const std::string& path)
                : l_lib(nullptr)
                , l_instance(nullptr)
            {
                this->load(path);
            }

            /**
             * @brief Unique pointer
             * 
             */
            DLLoader(DLLoader& other) = delete;

            /**
             * @brief unload the library
             *
             */
            ~DLLoader()
            {
                this->free();
            }

            /**
             * @brief Frees previous lib and loads a new one
             *
             * @param path path to the new lib
             */
            void load(const std::string &path)
            {
                this->free();
                this->l_lib = dlopen(path.c_str(), RTLD_NOW | RTLD_LOCAL);
                if (!l_lib)
                    throw new arc::Error("Could not open lib: " + path + ", " + dlerror());
                void* func = dlsym(this->l_lib, "createInstance");
                if (func == NULL)
                    throw new arc::Error("Wrong lib format: " + path + ", " + dlerror());
                l_instance = reinterpret_cast<T* (*)()>(func)();
                if (l_instance == NULL)
                    throw new arc::Error("Could not create instance of lib: " + path + ", " + dlerror());
            }

            /**
             * @brief Free the currently loaded lib
             *
             */
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

            /**
             * @brief Unique pointer
             *
             */
            DLLoader& operator=(DLLoader& other) = delete;

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
