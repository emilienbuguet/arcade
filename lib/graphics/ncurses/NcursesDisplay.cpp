#include <iostream>
#include "NcursesDisplay.hpp"

arc::display::NcursesDisplay::NcursesDisplay()
{
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);
    attron(A_BOLD);
}

arc::display::NcursesDisplay::~NcursesDisplay()
{
    endwin();
}

void arc::display::NcursesDisplay::printMiddle(int y, int x, const std::string text, arc::Color color)
{
    switch(color.color) {
        case arc::Color::ColorType::RED:
            attron(COLOR_PAIR(1));
            break;
        case arc::Color::ColorType::GREEN:
            attron(COLOR_PAIR(2));
            break;
        case arc::Color::ColorType::BLUE:
            attron(COLOR_PAIR(3));
            break;
        case arc::Color::ColorType::YELLOW:
            attron(COLOR_PAIR(4));
            break;
        case arc::Color::ColorType::MAGENTA:
            attron(COLOR_PAIR(5));
            break;
        case arc::Color::ColorType::CYAN:
            attron(COLOR_PAIR(6));
            break;
        case arc::Color::ColorType::WHITE:
            attron(COLOR_PAIR(7));
            break;
        case arc::Color::ColorType::BLACK:
            attron(COLOR_PAIR(8));
            break;
        default:
            break;
    }
    mvprintw(y, x, text.c_str());
}

void arc::display::NcursesDisplay::drawObjects(std::vector<std::shared_ptr<arc::Object>> objs)
{
    for (std::shared_ptr<arc::Object> i : objs) {
        if (i->getType() == arc::Object::Type::TEXT) {
            auto txt = std::static_pointer_cast<arc::Text>(i);
            printMiddle(txt->getPosition().y, txt->getPosition().x, txt->getValue(), txt->getColor());
        } else {
            arc::Object obj = *i.get();
            getTexture(obj.getValue(), obj.getPosition().y, obj.getPosition().x);
        }
    }
    refresh();
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
    case 10:
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
    case 27:
        return arc::KeyEsc;
    default:
        return arc::None;
    }
}

arc::Color arc::display::NcursesDisplay::getSpriteColor(std::string line)
{
    if (line == "RED")
        return arc::Color(arc::Color::ColorType::RED);
    if (line == "GREEN")
        return arc::Color(arc::Color::ColorType::GREEN);
    if (line == "BLUE")
        return arc::Color(arc::Color::ColorType::BLUE);
    if (line == "YELLOW")
        return arc::Color(arc::Color::ColorType::YELLOW);
    if (line == "MAGENTA")
        return arc::Color(arc::Color::ColorType::MAGENTA);
    if (line == "CYAN")
        return arc::Color(arc::Color::ColorType::CYAN);
    if (line == "WHITE")
        return arc::Color(arc::Color::ColorType::WHITE);
    if (line == "BLACK")
        return arc::Color(arc::Color::ColorType::BLACK);
    return arc::Color(arc::Color::ColorType::WHITE);
}

void arc::display::NcursesDisplay::getTexture(const std::string fileName, int y, int x)
{
    std::ifstream file("src/assets/ncurses/" + fileName);
    std::string line;
    std::string sprite = "";
    arc::Color color(arc::Color::ColorType::WHITE);

    for (int i = 0; std::getline(file, line); i++) {
        if (i == 0) {
            color = getSpriteColor(line);
            continue;
        }
        sprite = sprite + line;
    }
    printMiddle(y, x, sprite, color);
}

void arc::display::NcursesDisplay::drawInterface(__attribute__((unused)) std::vector<std::shared_ptr<arc::Object>> objs)
{

}