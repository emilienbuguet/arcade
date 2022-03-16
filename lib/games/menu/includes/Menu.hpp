#include <string>

#pragma once



namespace arc::games {

    struct MenuProprieties {
        std::string username;
        std::string gamelib;
        std::string graphicslib;
    };

    class MenuGame {

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
         * @brief Get the entered username
         *
         * @return const std::string
         */
        const std::string getUsername() const;

        /**
         * @brief Get the properties of the game to start
         *
         * @return const MenuProprieties
         */
        const MenuProprieties getProps() const;

        /**
         * @brief checks if game is starting or not
         *
         * @return true
         * @return false
         */
        const bool isStarting() const;

        private :
            MenuProprieties props;
            bool isStarting;
    }; /* class MenuGame */

} /* namespace arc::games */
