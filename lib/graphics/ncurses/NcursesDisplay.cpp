#include <iostream>
#include "NcursesDisplay.hpp"

arc::display::NcursesDisplay::NcursesDisplay()
{
    initscr();
    nodelay(stdscr, TRUE);
}

arc::display::NcursesDisplay::~NcursesDisplay()
{
    endwin();
}

void arc::display::NcursesDisplay::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    clear();
    for (std::shared_ptr<arc::Object> i : objs) {
        arc::Object obj = *i.get();
        if (obj.type == obj.TEXT)
            mvprintw(obj.x, obj.y, obj.value.c_str());
        else {
            mvprintw(obj.x, obj.y, getTexture(obj.value));
        }
    }
}

const arc::Events arc::display::NcursesDisplay::getEvent() const
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

char *arc::display::NcursesDisplay::getTexture(const std::string fileName)
{
    std::ifstream asset("src/assets/ncurses/" + fileName);
    std::string texture("");
    if (asset.is_open())
        asset >> texture;
    return (texture);
}