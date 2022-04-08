#include <Error.hpp>
#include <SfmlDisplay.hpp>

#include <iostream>

arc::display::SfmlDisplay::SfmlDisplay()
    : m_window(nullptr)
    , m_textures()
    , m_font(std::make_unique<sf::Font>(sf::Font{}))
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Fullscreen);
    m_font->loadFromFile("./assets/fonts/GoldenAge.ttf");
    if (!m_font)
        throw new arc::display::SfmlError{"unable to load font"};
}

arc::display::SfmlDisplay::~SfmlDisplay() = default;

std::shared_ptr<sf::Texture> arc::display::SfmlDisplay::getTexture(const std::string& name)
{
    auto it = m_textures.find(name);
    if (it != m_textures.end()) {
        return it->second;
    } else {
        std::shared_ptr<sf::Texture> tmp = std::make_shared<sf::Texture>(sf::Texture{});
        if (!tmp->loadFromFile("./assets/" + name + ".png")) {
            if (!tmp->loadFromFile("./assets/" + name + ".jpg")) {
                if (!tmp->loadFromFile("./assets/" + name + ".bmp")) {
                    throw new arc::display::SfmlError{std::string("unable to load texture: ") + name};
                }
            }
        }
        m_textures.insert(std::make_pair(name, tmp));
        return m_textures.at(name);
    }
}

void arc::display::SfmlDisplay::drawSprite(std::shared_ptr<arc::Object> obj)
{
    auto sprite = std::static_pointer_cast<arc::Sprite>(obj);
    if (sprite) {
        sf::Rect rect{0, 0, sprite->getWidth(), sprite->getHeight()};
        sf::Sprite s{*getTexture(sprite->getValue())};
        if (sprite->getHeight() == 0 || sprite->getWidth() == 0) {
            s.setTextureRect(sf::IntRect{
                    0,
                    0,
                    static_cast<int>(s.getTexture()->getSize().x),
                    static_cast<int>(s.getTexture()->getSize().y)
            });
        } else {
            s.setTextureRect(rect);
        }
        s.setPosition(sf::Vector2f{static_cast<float>(sprite->getPosition().x), static_cast<float>(sprite->getPosition().y)});
        this->m_window->draw(s);
    }
}

void arc::display::SfmlDisplay::drawText(std::shared_ptr<arc::Object> obj)
{
    auto text = std::static_pointer_cast<arc::Text>(obj);
    if (text) {
        sf::Text t{text->getValue(), *m_font, static_cast<unsigned int>(text->getSize())};
        sf::Color color{text->getColor().r, text->getColor().g, text->getColor().b, text->getColor().a};
        t.setPosition(static_cast<float>(text->getPosition().x), static_cast<float>(text->getPosition().y));
        t.setFillColor(color);
        this->m_window->draw(t);
    }
}

void arc::display::SfmlDisplay::placeObjectOnBoard(std::shared_ptr<arc::Object> obj)
{
    sf::Vector2u size = this->m_window->getSize();
    arc::Vector origin { static_cast<int>(size.x) / 2 - 400, static_cast<int>(size.y) / 2 - 300 };
    obj->setPosition(arc::Vector { origin.x + obj->getPosition().x, origin.y + obj->getPosition().y });
}

void arc::display::SfmlDisplay::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    this->m_window->clear();
    for (auto it = objs.begin(); it != objs.end(); it++) {
        if ((*it)->getType() == arc::Object::Type::SPRITE) {
            auto obj = std::static_pointer_cast<arc::Sprite>(*it);
            std::shared_ptr<arc::Sprite> sprite = std::make_shared<arc::Sprite>(
                obj->getValue(),
                arc::Vector {
                    obj->getPosition().x * 25,
                    obj->getPosition().y * 25
                },
                obj->getHeight() * 25,
                obj->getWidth() * 25,
                obj->getScale()
            );
            placeObjectOnBoard(sprite);
            this->drawSprite(sprite);
        } else if ((*it)->getType() == arc::Object::Type::TEXT) {
            auto obj = std::static_pointer_cast<arc::Text>(*it);
            std::shared_ptr<arc::Text> text = std::make_shared<arc::Text>(
                obj->getValue(),
                arc::Vector {
                    obj->getPosition().x * 25,
                    obj->getPosition().y * 25
                },
                obj->getSize(),
                obj->getColor()
            );
            placeObjectOnBoard(text);
            this->drawText(text);
        }
    }
}

void arc::display::SfmlDisplay::drawInterface(std::vector<std::shared_ptr<arc::Object>> objs)
{
    for (auto it = objs.begin(); it != objs.end(); it++) {
        if ((*it)->getType() == arc::Object::Type::SPRITE) {
            this->drawSprite(*it);
        } else if ((*it)->getType() == arc::Object::Type::TEXT) {
            this->drawText(*it);
        }
    }
    this->m_window->display();
}

arc::Events arc::display::SfmlDisplay::getEvent() const
{
    sf::Event event;
    while (this->m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return arc::Events::Exit;
        if (event.type == sf::Event::KeyPressed)
            return interpretKeyboardEvent(event.key);
    }
    return arc::Events::None;
}

arc::Events arc::display::SfmlDisplay::interpretKeyboardEvent(const sf::Event::KeyEvent& event) const
{
    switch (event.code) {
        case sf::Keyboard::Escape:
            return arc::KeyEsc;
        case sf::Keyboard::Left:
            return arc::KeyLeft;
        case sf::Keyboard::Right:
            return arc::KeyRight;
        case sf::Keyboard::Up:
            return arc::KeyUp;
        case sf::Keyboard::Down:
            return arc::KeyDown;
        case sf::Keyboard::Space:
            return arc::KeySpace;
        case sf::Keyboard::Return:
            return arc::KeyEnter;
        case sf::Keyboard::A:
            return arc::KeyA;
        case sf::Keyboard::B:
            return arc::KeyB;
        case sf::Keyboard::C:
            return arc::KeyC;
        case sf::Keyboard::D:
            return arc::KeyD;
        case sf::Keyboard::E:
            return arc::KeyE;
        case sf::Keyboard::F:
            return arc::KeyF;
        case sf::Keyboard::G:
            return arc::KeyG;
        case sf::Keyboard::H:
            return arc::KeyH;
        case sf::Keyboard::I:
            return arc::KeyI;
        case sf::Keyboard::J:
            return arc::KeyJ;
        case sf::Keyboard::K:
            return arc::KeyK;
        case sf::Keyboard::L:
            return arc::KeyL;
        case sf::Keyboard::M:
            return arc::KeyM;
        case sf::Keyboard::N:
            return arc::KeyN;
        case sf::Keyboard::O:
            return arc::KeyO;
        case sf::Keyboard::P:
            return arc::KeyP;
        case sf::Keyboard::Q:
            return arc::KeyQ;
        case sf::Keyboard::R:
            return arc::KeyR;
        case sf::Keyboard::S:
            return arc::KeyS;
        case sf::Keyboard::T:
            return arc::KeyT;
        case sf::Keyboard::U:
            return arc::KeyU;
        case sf::Keyboard::V:
            return arc::KeyV;
        case sf::Keyboard::W:
            return arc::KeyW;
        case sf::Keyboard::X:
            return arc::KeyX;
        case sf::Keyboard::Y:
            return arc::KeyY;
        case sf::Keyboard::Z:
            return arc::KeyZ;
        case sf::Keyboard::Num0:
            return arc::Key0;
        case sf::Keyboard::Num1:
            return arc::Key1;
        case sf::Keyboard::Num2:
            return arc::Key2;
        case sf::Keyboard::Num3:
            return arc::Key3;
        case sf::Keyboard::Num4:
            return arc::Key4;
        case sf::Keyboard::Num5:
            return arc::Key5;
        case sf::Keyboard::Num6:
            return arc::Key6;
        case sf::Keyboard::Num7:
            return arc::Key7;
        case sf::Keyboard::Num8:
            return arc::Key8;
        case sf::Keyboard::Num9:
            return arc::Key9;
        case sf::Keyboard::Backspace:
            return arc::KeyDel;
        default:
            return arc::None;
    }
}
