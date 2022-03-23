/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Object.cpp
*/

#include <Object.hpp>

arc::Object::Object(arc::Object::Type t, const std::string value, arc::Vector pos)
    : type(t)
    , value(value)
    , pos(pos)
{
}

arc::Object::~Object() = default;

/********** Text objects **********/

arc::Text::Text(const std::string content, arc::Vector pos, int size, arc::Text::Color color)
    : arc::Object(arc::Object::TEXT, content, pos)
    , size(size)
    , color(color)
{
}

arc::Text::~Text() = default;

/********** Sprite objects **********/

arc::Sprite::Sprite(const std::string name, arc::Vector pos, int height, int width, arc::Vector scale)
    : arc::Object(arc::Object::SPRITE, name, pos)
    , width(width)
    , height(height)
    , scale(scale)
{
}

arc::Sprite::~Sprite() = default;