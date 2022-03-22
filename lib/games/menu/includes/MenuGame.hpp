#include <memory>
#include <string>


#include <Interfaces/IGameModule.hpp>

#pragma once


namespace arc::games {

    struct MenuProprieties {
        std::string username;
        std::string gamelib;
        std::string graphicslib;
    };

    class MenuGame : public IGameModule {
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
             * @brief Get the Objects object
             *
             * @return const std::vector<std::shared_ptr<arc::Object>>
             */
            const std::vector<std::shared_ptr<arc::Object>> getObjects() const final;

            /**
             * @brief Tells if game is running or not
             *
             * @return true or false
             */
            bool isRunning() const final;

            /**
             * @brief Updates game's entities
             *
             */
            void update() final;

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
             * @brief True if game is still running, false otherwise
             *
             */
            bool m_isRunning;
    }; /* class MenuGame */

} /* namespace arc::games */
