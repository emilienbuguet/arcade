#include <Interfaces/IGameModule.hpp>
#include <Interfaces/IDisplayModule.hpp>

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
             * @brief current loaded game
             *
             */
            std::shared_ptr<arc::games::IGameModule> c_game;

            /**
             * @brief current loaded display
             *
             */
            std::shared_ptr<arc::display::IDisplayModule> c_display;

            /**
             * @brief name of the current loaded display
             *
             */
            std::string displayName;

            /**
             * @brief name of the current loaded game
             *
             */
            std::string gameName;
    }; /* class Core */

} /* namespace arc */
