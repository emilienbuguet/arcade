#include "Food.hpp"

arc::games::Food::Food(std::vector<std::string> map, std::shared_ptr<Snake> snake)
    : pos_x(0)
    , pos_y(0)
    , f_clock(clock())
{
    int x = rand() % 32;
    int y = rand() % 24;
    while (map[y][x] == 'X' || snake->hasPosition(x, y) == true) {
        x = rand() % 32;
        y = rand() % 24;
    }
    pos_x = x;
    pos_y = y;
}

arc::games::Food::~Food()
{

}

int arc::games::Food::getXpos() const
{
    return pos_x;
}

int arc::games::Food::getYpos() const
{
    return pos_y;
}

clock_t arc::games::Food::getClock()
{
    return f_clock;
}