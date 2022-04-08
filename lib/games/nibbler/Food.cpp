#include "Food.hpp"

arc::games::Food::Food()
    : pos_x(0)
    , pos_y(0)
{
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

void arc::games::Food::setPos(int x, int y)
{
    pos_x = x;
    pos_y = y;
}
