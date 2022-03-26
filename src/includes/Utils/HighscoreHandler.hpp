#include <Object.hpp>

#include <map>
#include <memory>
#include <string>
#include <vector>

#pragma once

namespace arc::utils {

    class HighscoreHandler {
        public:
            /**
             * @brief Constructor
             *
             */
            HighscoreHandler();

            /**
             * @brief Destructor
             *
             */
            ~HighscoreHandler() = default;

            /**
             * @brief Getter for the highscores
             *
             * @return std::vector<std::pair<std::string, int>>
             */
            std::vector<std::pair<std::string, int>> getHighscores() const;

            /**
             * @brief Setter for the highscores
             *
             * @param highscores
             */
            void setHighscores(std::vector<std::pair<std::string, int>> highscores);

            /**
             * @brief Add a highscore to the highscores
             *
             * @param name Name of the player
             * @param score Score of the player
             */
            void addHighscore(const std::string& name, int score);

            /**
             * @brief Save the highscores to a file
             *
             */
            void saveHighscores();

            /**
             * @brief Convert the highscores to a list of Objects
             *
             */
            std::vector<std::shared_ptr<arc::Object>> toObjects();

            private:
                std::vector<std::pair<std::string, int>> m_highscores;
                std::string m_filePath;

    }; /* class HighscoreHandler */

} /* namespace arc::utils */