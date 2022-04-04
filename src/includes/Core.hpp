#include <Interfaces/IGameModule.hpp>
#include <Interfaces/IDisplayModule.hpp>
#include <Utils/DLLoader.hpp>
#include <Utils/HighscoreHandler.hpp>

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

            /**
             * @brief Handle the event
             *
             */
            bool useEvent(arc::Events event);

            /**
             * @brief Update the core
             *
             */
            void update();

            /**
             * @brief Switch to the next game
             *
             */
            void nextGame();

            /**
             * @brief Switch to the previous game
             *
             */
            void previousGame();

            /**
             * @brief Switch to the next display
             *
             */
            void nextDisplay();

            /**
             * @brief Switch to the previous display
             *
             */
            void previousDisplay();

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
            std::string currentDisplay;

            /**
             * @brief Name of the current loaded game
             *
             */
            std::string currentGame;

            /**
             * @brief Pathes to all games
             *
             */
            std::vector<std::string> c_games;

            /**
             * @brief Pathes to all displays
             *
             */
            std::vector<std::string> c_displays;

            /**
             * @brief Username of the current user
             *
             */
            std::string c_username;

            /**
             * @brief Objects of the interface
             *
             */
            std::vector<std::shared_ptr<arc::Object>> c_interface;

            /**
             * @brief Highscore handler
             *
             */
            std::unique_ptr<arc::utils::HighscoreHandler> c_highscore;

            /**
             * @brief Score
             *
             */
            int c_score;

    }; /* class Core */

} /* namespace arc */
