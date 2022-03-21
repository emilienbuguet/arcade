#include <Interfaces/IGameModule.hpp>
#include <Interfaces/IDisplayModule.hpp>
#include <Utils/DLLoader.hpp>

#include <memory>
#include <string>

#pragma once

namespace arc {

    /**
     * @brief Arcade core, links both game and display libraries
     *
     */
    class Core {
        public:

            /**
             * @brief Construct a new Core object
             *
             */
            Core(const std::string &lib);

            /**
             * @brief Destroy the Core object
             *
             */
            ~Core();

            /**
             * @brief Get the loaded display module
             *
             * @returns std::unique_ptr<arc::display::IDisplayModule>
             *
             */
            std::unique_ptr<arc::display::IDisplayModule> getDisplay() const;

            /**
             * @brief get the loaded game module
             *
             * @returns std::unique_ptr<arc::games::IGameModule>
             *
             */
            std::unique_ptr<arc::games::IGameModule> getGame() const;

            /**
             * @brief starts the arcade machine
             *
             */
            void run();

            /**
             * @brief Get the name of the loaded game
             *
             * @return const std::string&
             */
            const std::string &getGameName() const;

            /**
             * @brief Get the name of the loaded display
             *
             * @return const std::string&
             */
            const std::string &getDisplayName() const;

        private:

            /**
             * @brief Current loaded game
             *
             */
            arc::DLLoader<arc::games::IGameModule> c_game;

            /**
             * @brief Current loaded display
             *
             */
            arc::DLLoader<arc::display::IDisplayModule> c_display;

            /**
             * @brief Name of the current loaded display
             *
             */
            std::string displayName;

            /**
             * @brief Name of the current loaded game
             *
             */
            std::string gameName;
    }; /* class Core */

} /* namespace arc */
