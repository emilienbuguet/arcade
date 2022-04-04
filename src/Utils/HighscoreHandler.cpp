#include <Utils/HighscoreHandler.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

arc::utils::HighscoreHandler::HighscoreHandler()
    : m_highscores({})
    , m_filePath("highscores.arc")
{
    std::ifstream file(m_filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::string name;
        int value;
        std::istringstream iss(line);
        iss >> name >> value;
        m_highscores.push_back(std::make_pair(name, value));
    }
}

std::vector<std::pair<std::string, int>> arc::utils::HighscoreHandler::getHighscores() const
{
    return m_highscores;
}

void arc::utils::HighscoreHandler::setHighscores(std::vector<std::pair<std::string, int>> highscores)
{
    m_highscores = highscores;
}

void arc::utils::HighscoreHandler::addHighscore(const std::string& name, int score)
{
    m_highscores.push_back(std::make_pair(name, score));
}

void arc::utils::HighscoreHandler::saveHighscores()
{
    std::ofstream file(m_filePath);
    for (auto& highscore : m_highscores) {
        file << highscore.first << " " << highscore.second << std::endl;
    }
}

std::vector<std::shared_ptr<arc::Object>> arc::utils::HighscoreHandler::toObjects()
{
    std::vector<std::shared_ptr<arc::Object>> objects;
    objects.push_back(std::make_shared<arc::Text>(
        "Highscores",
        arc::Vector { 110, 300 },
        30,
        arc::Color { arc::Color::YELLOW }));
    for (size_t i = 0; i < m_highscores.size() && i < 10; i++) {
        objects.push_back(std::make_shared<arc::Text>(
            m_highscores[i].first + " " + std::to_string(m_highscores[i].second),
            arc::Vector(100, 400 + i * 28),
            25,
            arc::Color(arc::Color::WHITE)));
    }
    return objects;
}