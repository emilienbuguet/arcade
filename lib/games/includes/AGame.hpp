#include <Interfaces/IGameModule.hpp>

#pragma once

namespace arc::games {

class AGame : public arc::games::IGameModule {
    public:
        /**
         * @brief Construct a new AGame object
         *
         */
        AGame(int score = 0);

        /**
         * @brief Destroy the AGame object
         *
         */
        ~AGame();

        /**
         * @brief Get the score of the current game
         *
         * @return int
         */
        int getScore() const;

        /**
         * @brief Tells if game is still running or not
         *
         * @return true or false
         */
        bool isRunning() const override;

        /**
         * @brief Get the Objects object
         *
         * @return const std::vector<std::shared_ptr<arc::Object>>
         */
        virtual const std::vector<std::shared_ptr<arc::Object>> getObjects() const override;

    protected:
        /**
         * @brief Current score
         *
         */
        int m_score;

        /**
         * @brief Game state : running or not
         *
         */
        bool m_isRunning;


        /**
         * @brief All entities of the game
         *
         */
        std::vector<std::shared_ptr<arc::Object>> m_objects;

}; /* class AGame */

} /* namespace arc::games */
