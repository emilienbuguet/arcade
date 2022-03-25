#include <Vector.hpp>

#include <string>

#pragma once

namespace arc {

    /**
     * @brief Represents a drawable object
     *
     */
    struct Object {

        /**
         * @brief Type of the object
         *
         */
        enum Type { TEXT, SPRITE };

        /**
         * @brief Construct a new Object object
         *
         * @param t type of the object
         * @param value value of the object
         */
        Object(arc::Object::Type t, const std::string value, arc::Vector pos);

        /**
         * @brief Destroy the Object object
         *
         */
        ~Object();

        /**
         * @brief Type of the object
         *
         */
        Type type;

        /**
         * @brief Content or name of the asset
         *
         */
        const std::string value;

        /**
         * @brief Position of the object
         *
         */
        arc::Vector pos;
    }; /* struct Object */

    struct Text : public Object {

        /**
         * @brief Color of the text
         *
         */
        struct Color {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        };

        struct Colors {
            static constexpr Text::Color white = arc::Text::Color { 255, 255, 255, 255 };
            static constexpr Text::Color black = arc::Text::Color { 0, 0, 0, 255 };
        };

        /**
         * @brief Construct a new Text object
         *
         * @param content Content of the text
         * @param pos Position of the text
         * @param size Font size
         * @param color Font color
         */
        Text(const std::string content, arc::Vector pos, int size, arc::Text::Color color);

        /**
         * @brief Destroy the Text object
         *
         */
        ~Text();

        /**
         * @brief Character size
         *
         */
        int size;

        /**
         * @brief Color of the text
         *
         */
        Text::Color color;

    }; /* struct Text */

    struct Sprite : public Object {

        /**
         * @brief Construct a new Sprite object
         *
         * @param name name of the sprite
         * @param pos position of the sprite
         * @param height height of the sprite (default 0)
         * @param width width of the sprite (default 0)
         */
        Sprite(const std::string name, arc::Vector pos, int height = 0, int width = 0, arc::Vector = arc::Vector{100, 100});

        /**
         * @brief Destroy the Sprite object
         *
         */
        ~Sprite();

        /**
         * @brief Width of the object
         *
         */
        int width;

        /**
         * @brief Height of the object
         *
         */
        int height;

        /**
         * @brief Scale of the object
         *
         */
        arc::Vector scale;
    }; /* struct Sprite */

} /* namespace arc */
