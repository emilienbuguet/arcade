#include <iostream>
#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    initscr();
    nodelay(stdscr, TRUE);
}

Ncurses::~Ncurses()
{
    endwin();
}

void Ncurses::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    clear();
    std::string chr;
    std::ifstream asset;
    for (std::shared_ptr<arc::Object> i : objs) {
        arc::Object obj = *i.get();
        if (obj.type == obj.TEXT)
            mvprintw(obj.x, obj.y, obj.value.c_str());
        else {
            asset.open("src/assets/ncurses/" + obj.value);
            getline(asset, chr);
            mvprintw(obj.x, obj.y, chr.c_str());
        }
    }
}

const arc::Events Ncurses::getEvent() const
{
    char in = getch();
    if (in == ERR)
        return arc::Events::None;
    if (in == KEY_LEFT)
        return arc::Events::KeyLeft;
    if (in == KEY_DOWN)
        return arc::Events::KeyDown;
    if (in == KEY_RIGHT)
        return arc::Events::KeyRight;
    if (in == KEY_UP)
        return arc::Events::KeyUp;
    if (in == ' ')
        return arc::Events::KeySpace;
    return arc::Events::None;
}