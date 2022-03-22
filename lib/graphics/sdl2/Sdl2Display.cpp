#include <Error.hpp>
#include <Sdl2Display.hpp>

#include <iostream>


arc::display::Sdl2Display::Sdl2Display()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw new arc::display::Sdl2Error{std::string("unable to init sdl2: ") + SDL_GetError()};
    }
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &this->m_window, &this->m_renderer) < 0) {
        SDL_Quit();
        throw new arc::display::Sdl2Error{std::string("unable to create window: ") + SDL_GetError()};
    }
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
        SDL_Surface* tmp = SDL_LoadBMP(("./assets/sdl2/" + name + ".bmp").c_str());
        if (!tmp)
            throw new arc::display::Sdl2Error("unable to load image : " + name + ".bmp");
        SDL_Texture *text = SDL_CreateTextureFromSurface(this->m_renderer, tmp);
        SDL_FreeSurface(tmp);
        this->m_textures.insert(std::pair<std::string, SDL_Texture *>(name, text));
        return text;
    }
}

void arc::display::Sdl2Display::drawObject(std::shared_ptr<arc::Object> obj)
{
    SDL_Rect src { 0, 0, obj->width, obj->height };
    if (obj->width == 0 || obj->height == 0) {
        SDL_QueryTexture(this->getTexture(obj->value), NULL, NULL, &src.w, &src.h);
    }
    SDL_Rect dest { obj->x, obj->y, src.w, src.h };
    SDL_RenderCopy(this->m_renderer, this->getTexture(obj->value), &src, &dest);
}

void arc::display::Sdl2Display::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);
    for (std::shared_ptr<arc::Object>& obj : objs) {
        this->drawObject(obj);
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
