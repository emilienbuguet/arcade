#include <Error.hpp>
#include <Sdl2Display.hpp>

#include <SDL2/SDL_image.h>
#include <iostream>


arc::display::Sdl2Display::Sdl2Display()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw new arc::display::Sdl2Error{std::string("unable to init sdl2: ") + SDL_GetError()};
    }
    if (TTF_Init() < 0) {
        SDL_Quit();
        throw new arc::display::Sdl2Error{std::string("unable to init sld2_ttf") + TTF_GetError()};
    }
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0) {
        TTF_Quit();
        SDL_Quit();
        throw new arc::display::Sdl2Error{std::string("unable to init sdl2_image") + IMG_GetError()};
    }
    if (SDL_CreateWindowAndRenderer(1920, 1080, SDL_WINDOW_SHOWN, &this->m_window, &this->m_renderer) < 0) {
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        throw new arc::display::Sdl2Error{std::string("unable to create window: ") + SDL_GetError()};
    }
    SDL_SetWindowFullscreen(this->m_window, SDL_WINDOW_FULLSCREEN);
    SDL_SetWindowTitle(this->m_window, "Arcade");
}

arc::display::Sdl2Display::~Sdl2Display()
{
    for (auto it = this->m_textures.begin(); it != this->m_textures.end(); it++) {
        if (it->second) {
            SDL_DestroyTexture(it->second);
            it->second = NULL;
        }
    }
    if (this->m_renderer != NULL) {
        SDL_DestroyRenderer(this->m_renderer);
    }
    if (this->m_window != NULL) {
        SDL_DestroyWindow(this->m_window);
    }
    SDL_Quit();
}

SDL_Texture *arc::display::Sdl2Display::getTexture(const std::string& name)
{
    auto it = this->m_textures.find(name);
    if (it != this->m_textures.end()) {
        return it->second;
    } else {
        SDL_Surface* tmp = IMG_Load(("./assets/" + name + ".bmp").c_str());
        if (!tmp)
            tmp = IMG_Load(("./assets/sdl2/" + name + ".png").c_str());
        if (!tmp)
            IMG_Load(("./assets/sdl2/" + name + ".jpg").c_str());
        if (!tmp)
            throw new arc::display::Sdl2Error("unable to load image : " + name);
        SDL_Texture *text = SDL_CreateTextureFromSurface(this->m_renderer, tmp);
        SDL_FreeSurface(tmp);
        this->m_textures.insert(std::pair<std::string, SDL_Texture *>(name, text));
        return text;
    }
}

void arc::display::Sdl2Display::drawSprite(std::shared_ptr<arc::Object> obj)
{
    auto sprite = std::static_pointer_cast<arc::Sprite>(obj);
    if (sprite) {
        SDL_Rect rect;
        rect.x = sprite->getPosition().x;
        rect.y = sprite->getPosition().y;
        rect.h = sprite->getHeight();
        rect.w = sprite->getWidth();
        if (sprite->getHeight() == 0 || sprite->getWidth() == 0)
            SDL_QueryTexture(this->getTexture(sprite->getValue()), NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(this->m_renderer, this->getTexture(sprite->getValue()), NULL, &rect);
    }
}

void arc::display::Sdl2Display::drawText(std::shared_ptr<arc::Object> obj)
{
    auto text = std::static_pointer_cast<arc::Text>(obj);
    TTF_Font *font = TTF_OpenFont("assets/fonts/GoldenAge.ttf", text->getSize());

    if (font == nullptr)
        throw arc::display::Sdl2Error("unable to load font");
    if (text) {
        SDL_Color color = {text->getColor().r, text->getColor().g, text->getColor().b, text->getColor().a};
        SDL_Surface* tmp = TTF_RenderText_Shaded(font, text->getValue().c_str(), color, {0, 0, 0, 255});
        if (!tmp)
            throw new arc::display::Sdl2Error("unable to render text");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->m_renderer, tmp);
        SDL_FreeSurface(tmp);
        SDL_Rect rect;
        rect.x = text->getPosition().x;
        rect.y = text->getPosition().y;
        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(this->m_renderer, texture, NULL, &rect);
    }
    TTF_CloseFont(font);
}

void arc::display::Sdl2Display::placeObjectOnBoard(std::shared_ptr<arc::Object> obj)
{
    int w, h;
    SDL_GetWindowSize(this->m_window, &w, &h);
    arc::Vector origin{w / 2 - 400, h / 2 - 300};
    obj->setPosition(arc::Vector{origin.x + obj->getPosition().x, origin.y + obj->getPosition().y});
}

void arc::display::Sdl2Display::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);
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

void arc::display::Sdl2Display::drawInterface(std::vector<std::shared_ptr<arc::Object>> objs)
{
    for (auto it = objs.begin(); it != objs.end(); it++) {
        if ((*it)->getType() == arc::Object::Type::SPRITE) {
            this->drawSprite(*it);
        } else if ((*it)->getType() == arc::Object::Type::TEXT) {
            this->drawText(*it);
        }
    }
    SDL_RenderPresent(this->m_renderer);
}

arc::Events arc::display::Sdl2Display::getEvent() const
{
    SDL_Event events;
    while (SDL_PollEvent(&events)) {
        if (events.type == SDL_QUIT)
            return arc::Exit;
        if (events.type == SDL_KEYDOWN)
            return interpretKeyboardEvent(events.key);
    }
    return arc::None;
}

arc::Events arc::display::Sdl2Display::interpretKeyboardEvent(const SDL_KeyboardEvent& event) const
{
    switch (event.keysym.sym) {
        case SDLK_ESCAPE:
            return arc::KeyEsc;
        case SDLK_UP:
            return arc::KeyUp;
        case SDLK_DOWN:
            return arc::KeyDown;
        case SDLK_LEFT:
            return arc::KeyLeft;
        case SDLK_RIGHT:
            return arc::KeyRight;
        case SDLK_SPACE:
            return arc::KeySpace;
        case SDLK_RETURN:
            return arc::KeyEnter;
        case 'a':
            return arc::KeyA;
        case 'b':
            return arc::KeyB;
        case 'c':
            return arc::KeyC;
        case 'd':
            return arc::KeyD;
        case 'e':
            return arc::KeyE;
        case 'f':
            return arc::KeyF;
        case 'g':
            return arc::KeyG;
        case 'h':
            return arc::KeyH;
        case 'i':
            return arc::KeyI;
        case 'j':
            return arc::KeyJ;
        case 'k':
            return arc::KeyK;
        case 'l':
            return arc::KeyL;
        case 'm':
            return arc::KeyM;
        case 'n':
            return arc::KeyN;
        case 'o':
            return arc::KeyO;
        case 'p':
            return arc::KeyP;
        case 'q':
            return arc::KeyQ;
        case 'r':
            return arc::KeyR;
        case 's':
            return arc::KeyS;
        case 't':
            return arc::KeyT;
        case 'u':
            return arc::KeyU;
        case 'v':
            return arc::KeyV;
        case 'w':
            return arc::KeyW;
        case 'x':
            return arc::KeyX;
        case 'y':
            return arc::KeyY;
        case 'z':
            return arc::KeyZ;
        case SDLK_0:
            return arc::Key0;
        case SDLK_1:
            return arc::Key1;
        case SDLK_2:
            return arc::Key2;
        case SDLK_3:
            return arc::Key3;
        case SDLK_4:
            return arc::Key4;
        case SDLK_5:
            return arc::Key5;
        case SDLK_6:
            return arc::Key6;
        case SDLK_7:
            return arc::Key7;
        case SDLK_8:
            return arc::Key8;
        case SDLK_9:
            return arc::Key9;
        case SDLK_BACKSPACE:
            return arc::KeyDel;
        default:
            return arc::None;
    }
}
