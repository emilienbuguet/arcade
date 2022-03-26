#include <MenuItem.hpp>

arc::games::menu::MenuItem::MenuItem(const std::string value, Vector pos, int size, Color color)
    : Text(value, pos, size, color)
    , m_selected(false)
{
}

bool arc::games::menu::MenuItem::isSelected() const
{
    return this->m_selected;
}

void arc::games::menu::MenuItem::setSelected(bool selected)
{
    this->m_selected = selected;
}
