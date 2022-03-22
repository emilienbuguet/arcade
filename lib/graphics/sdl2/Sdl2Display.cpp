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
    if (this->m_renderer != NULL) {
        SDL_DestroyRenderer(this->m_renderer);
    }
    if (this->m_window != NULL) {
        SDL_DestroyWindow(this->m_window);
    }
    SDL_Quit();
}

void arc::display::Sdl2Display::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    std::cout << "Draw objects here ..." << std::endl;
    SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->m_renderer);
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
