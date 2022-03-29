#include <iostream>
#include "NcursesDisplay.hpp"

arc::display::NcursesDisplay::NcursesDisplay()
{
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
}

arc::display::NcursesDisplay::~NcursesDisplay()
{
    endwin();
}

void arc::display::NcursesDisplay::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    for (std::shared_ptr<arc::Object> i : objs) {
        arc::Object obj = *i.get();
        if (obj.getType() == arc::Object::Type::TEXT)
            mvprintw(obj.getPosition().y, obj.getPosition().x, obj.getValue().c_str());
        else {
            mvprintw(obj.getPosition().y, obj.getPosition().x, getTexture(obj.getValue()));
        }
    }
}

arc::Events arc::display::NcursesDisplay::getEvent() const
{
    switch (getch()) {
    case KEY_UP:
        return arc::KeyUp;
    case KEY_DOWN:
        return arc::KeyDown;
    case KEY_LEFT:
        return arc::KeyLeft;
    case KEY_RIGHT:
        return arc::KeyRight;
    case ' ':
        return arc::KeySpace;
    case KEY_ENTER:
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
    case '0':
        return arc::Key0;
    case '1':
        return arc::Key1;
    case '2':
        return arc::Key2;
    case '3':
        return arc::Key3;
    case '4':
        return arc::Key4;
    case '5':
        return arc::Key5;
    case '6':
        return arc::Key6;
    case '7':
        return arc::Key7;
    case '8':
        return arc::Key8;
    case '9':
        return arc::Key9;
    case 127:
        clear();
        return arc::KeyDel;
    default:
        return arc::None;
    }
}

const char *arc::display::NcursesDisplay::getTexture(const std::string fileName)
{
    std::ifstream asset("src/assets/ncurses/" + fileName);
    std::string texture("");
    if (asset.is_open())
        asset >> texture;
    return (texture.c_str());
}

void arc::display::NcursesDisplay::drawInterface(__attribute__((unused)) std::vector<std::shared_ptr<arc::Object>> objs)
{

}