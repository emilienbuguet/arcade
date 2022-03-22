#include <memory>
#include <string>


#include <AGame.hpp>

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
             * @brief Get the properties of the game to start
             *
             * @return const MenuProprieties
             */
            const MenuProprieties getProps() const;

            /**
             * @brief Checks if game is starting or not
             *
             * @return true or false
             */
            bool isStarting() const;

        private :
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
             * @brief List of available games
             *
             */
            std::vector<std::string> m_games;

            /**
             * @brief List of available displays
             *
             */
            std::vector<std::string> m_displays;

    }; /* class MenuGame */

} /* namespace arc::games */
