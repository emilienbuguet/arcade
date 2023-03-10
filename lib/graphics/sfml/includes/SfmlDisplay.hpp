#include <Interfaces/IDisplayModule.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <map>

#pragma once

namespace arc::display {

class SfmlDisplay : public IDisplayModule {
public:
    /**
     * @brief Create a new SfmlDisplay object
     *
     */
    SfmlDisplay();

    /**
     * @brief Destroy a Sld2Display object
     *
     */
    ~SfmlDisplay();

    /**
     * @brief Draw all the objects generated by the game
     *
     * @param objs objects to be drawn
     */
    void drawObjects(std::vector<std::shared_ptr<arc::Object>> objs) override;

    /**
     * @brief Draw the interface of the game
     *
     * @param objs objects to be drawn
     */
    void drawInterface(std::vector<std::shared_ptr<arc::Object>> objs) override;

    /**
     * @brief Get any event
     *
     * @return const arc::Events - event that occured (or arc::Events::NONE)
     */
    arc::Events getEvent() const override;

    /**
     * @brief Place an object on the board
     *
     * @param obj object to be placed
     */
    void placeObjectOnBoard(std::shared_ptr<arc::Object> obj);

private:
    /**
     * @brief Get a texture by name
     *
     * @param name name of the texture
     * @return std::unique_ptr<sf::Texture> - pointer to the texture
     */
    std::shared_ptr<sf::Texture> getTexture(const std::string& name);

    /**
     * @brief Draw an object of type SPRITE
     *
     * @param obj object to draw
     */
    void drawSprite(std::shared_ptr<arc::Object> obj);

    /**
     * @brief Draw an object of type TEXT
     *
     * @param obj
     */
    void drawText(std::shared_ptr<arc::Object> obj);

    /**
     * @brief SFML window
     *
     */
    std::shared_ptr<sf::RenderWindow> m_window;

    /**
     * @brief Loaded textures
     *
     */
    std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;

    /**
     * @brief Loaded font
     *
     */
    std::unique_ptr<sf::Font> m_font;

    /**
     * @brief Interpret SFML Keyboard events
     *
     * @param event SFML Keyboard event
     */
    arc::Events interpretKeyboardEvent(const sf::Event::KeyEvent& event) const;

}; /* class SfmlDisplay */

}; /* namespace arc::display */
