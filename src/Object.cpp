#include <Object.hpp>
#include <iostream>

/********* Object class **********/

arc::Object::Object(Type t, const std::string value, Vector pos)
    : m_type(t)
    , m_value(value)
    , m_position(pos)
{
}

arc::Object::Type arc::Object::getType() const
{
    return this->m_type;
}

const std::string& arc::Object::getValue() const
{
    return this->m_value;
}

arc::Vector arc::Object::getPosition() const
{
    return this->m_position;
}

void arc::Object::setValue(const std::string &value)
{
    this->m_value = value;
}

void arc::Object::setPosition(arc::Vector pos)
{
    this->m_position = pos;
}

/********* Text class **********/

arc::Text::Text(const std::string value, Vector pos, int size, Color color)
    : Object(Type::TEXT, value, pos)
    , m_color(color)
    , m_size(size)
{
}

int arc::Text::getSize() const
{
    return this->m_size;
}

arc::Color arc::Text::getColor() const
{
    return this->m_color;
}

void arc::Text::setColor(Color color)
{
    this->m_color = color;
}

void arc::Text::setSize(int size)
{
    this->m_size = size;
}

/********* Sprite class **********/

arc::Sprite::Sprite(const std::string name, Vector pos, int height, int width, Vector scale)
    : Object(Type::SPRITE, name, pos)
    , m_height(height)
    , m_width(width)
    , m_scale(scale)
{
}

int arc::Sprite::getHeight() const
{
    return this->m_height;
}

int arc::Sprite::getWidth() const
{
    return this->m_width;
}

arc::Vector arc::Sprite::getScale() const
{
    return this->m_scale;
}
