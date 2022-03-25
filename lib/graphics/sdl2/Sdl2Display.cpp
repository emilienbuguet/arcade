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
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &this->m_window, &this->m_renderer) < 0) {
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        throw new arc::display::Sdl2Error{std::string("unable to create window: ") + SDL_GetError()};
    }
    SDL_SetWindowTitle(this->m_window, "Arcade");
    this->font = TTF_OpenFont("./assets/fonts/GoldenAge.ttf", 5);
    if (this->font == nullptr)
        throw arc::display::Sdl2Error("unable to load font");
}

arc::display::Sdl2Display::~Sdl2Display()
{
    TTF_CloseFont(this->font);
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
        SDL_Surface* tmp = IMG_Load(("./assets/sdl2/" + name + ".bmp").c_str());
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
    arc::Sprite *sprite = static_cast<arc::Sprite *>(obj.get());
    SDL_Rect src { 0, 0, sprite->width, sprite->height };
    if (sprite->width == 0 || sprite->height == 0) {
        SDL_QueryTexture(this->getTexture(sprite->value), NULL, NULL, &src.w, &src.h);
    }
    SDL_Rect dest { sprite->pos.x, sprite->pos.y, src.w, src.h };
    SDL_RenderCopy(this->m_renderer, this->getTexture(sprite->value), &src, &dest);
    //todo free surface
}

void arc::display::Sdl2Display::drawText(std::shared_ptr<arc::Object> obj)
{
    arc::Text *text = static_cast<arc::Text *>(obj.get());
    TTF_SetFontSize(this->font, text->size);
    SDL_Rect src {0, 0, 0, 0};
    SDL_Color color = {text->color.r, text->color.g, text->color.b, text->color.a};

    // todo debug
    SDL_Surface* surf = TTF_RenderText_Shaded(this->font, text->value.c_str(), color, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->m_renderer, surf);
    SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
    SDL_Rect dest { text->pos.x, text->pos.y, src.w, src.h };
    SDL_RenderCopy(this->m_renderer, texture, &src, &dest);
    //todo free surface
}

void arc::display::Sdl2Display::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);
    for (std::shared_ptr<arc::Object>& obj : objs) {
        if (obj->type == arc::Object::SPRITE)
            this->drawSprite(obj);
        else
            this->drawText(obj);
    }
    SDL_RenderPresent(this->m_renderer);
}

arc::Events arc::display::Sdl2Display::getEvent() const
{
    SDL_Event events;
    while (SDL_PollEvent(&events)) {
        if (events.type == SDL_QUIT)
            return arc::Exit;
    }
    return arc::None;
}
