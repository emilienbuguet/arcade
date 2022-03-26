#include <memory>
#include <string>


#include <AGame.hpp>
#include <MenuItem.hpp>

#pragma once


namespace arc::games {

    struct MenuProprieties {
        std::string username;
        std::string gamelib;
        std::string graphicslib;
    };

    class MenuGame : public AGame {
        public:
            /**
             * @brief Construct a new Menu Game object
             *
             */
            MenuGame();

            /**
             * @brief Destroy the Menu Game object
             *
             */
            ~MenuGame();

            /**
             * @brief Apply the current event
             *
             * @param event
             */
            void useEvent(arc::Events event) final;

            /**
             * @brief Updates game's entities
             *
             */
            void update() final;

            /**
             * @brief Get the game objects
             *
             * @return Game objects
             */
            const std::vector<std::shared_ptr<arc::Object>> getObjects() const final;

            /**
             * @brief Get the properties of the game to start
             *
             * @return const MenuProprieties
             */
            const MenuProprieties getProps() const {
                return m_props;
            }

            /**
             * @brief Checks if game is starting or not
             *
             * @return true or false
             */
            bool isStarting() const;

            /**
             * @brief Checks if user is selecting game or not
             *
             */
            bool isSelectingGame() const;

            /**
             * @brief Selects previous game
             *
             */
            void selectPreviousGame();

            /**
             * @brief Selects next game
             *
             */
            void selectNextGame();

            /**
             * @brief Selects previous display
             *
             */
            void selectPreviousDisplay();

            /**
             * @brief Selects next display
             *
             */
            void selectNextDisplay();

        private:
            /**
             * @brief Proprieties of the game that is about to start
             *
             */
            MenuProprieties m_props;

            /**
             * @brief True if user wants to start, false otherwise
             *
             */
            bool m_isStarting;

            /**
             * @brief User is selecting his game
             *
             */
            bool m_isSelectingGame;

            /**
             * @brief List of available games
             *
             */
            std::vector<std::shared_ptr<arc::games::menu::MenuItem>> m_games;

            /**
             * @brief List of available displays
             *
             */
            std::vector<std::shared_ptr<arc::games::menu::MenuItem>> m_displays;

            /**
             * @brief List of ui objects
             *
             */
            std::vector<std::shared_ptr<arc::games::menu::MenuItem>> m_ui;

            /**
             * @brief Handle character events and add it to the username
             *
             */
            void useCharacterEvent(arc::Events event);

    }; /* class MenuGame */

} /* namespace arc::games */
