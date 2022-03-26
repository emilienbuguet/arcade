#include <Color.hpp>
#include <Vector.hpp>

#include <string>

#pragma once

namespace arc {

    /**
     * @brief Represents a drawable object
     *
     */
    class Object {
        public:
            /**
             * @brief Enumeration of the different types of objects
             *
             */
            enum class Type {
                TEXT,
                SPRITE
            };

            /**
             * @brief Constructor
             *
             * @param t Type of the object
             * @param value Value of the object
             * @param pos Position of the object
             */
            Object(Type t, const std::string value, Vector pos);

            /**
             * @brief Destructor
             *
             */
            ~Object() = default;

            /**
             * @brief Getter for the type of the object
             *
             * @return Type of the object
             */
            Type getType() const;

            /**
             * @brief Getter for the value of the object
             *
             * @return Value of the object
             */
            const std::string &getValue() const;

            /**
             * @brief Getter for the position of the object
             *
             * @return Position of the object
             */
            Vector getPosition() const;

            private:
                Type m_type;
                std::string m_value;
                Vector m_position;
    };

    /**
     * @brief Represents a text object
     *
     */
    class Text : public Object {
        public:
            /**
             * @brief Constructor
             *
             * @param content Content of the text
             * @param pos Position of the text
             * @param size Size of the text
             * @param color Color of the text
             */
            Text(const std::string content, Vector pos, int size, Color color);

            /**
             * @brief Destructor
             *
             */
            ~Text() = default;

            /**
             * @brief Getter for the color of the text
             *
             * @return Color of the text
             */
            Color getColor() const;

            /**
             * @brief Getter for the size of the text
             *
             * @return Size of the text
             */
            int getSize() const;

            /**
             * @brief Setter for the color of the text
             *
             * @param color Color of the text
             */
            void setColor(Color color);

            /**
             * @brief Setter for the size of the text
             *
             * @param size Size of the text
             */
            void setSize(int size);

        private:
            Color m_color;
            int m_size;

    }; /* class Text */

    /**
     * @brief Represents a sprite object
     *
     */
    class Sprite : public Object {
        public:
            /**
             * @brief Constructor
             *
             * @param name Name of the sprite
             * @param pos Position of the sprite
             * @param height Height of the sprite
             * @param width Width of the sprite
             * @param scale Scale of the sprite
             */
            Sprite(const std::string name, Vector pos, int height = 0, int width = 0, Vector scale = Vector(100, 100));

            /**
             * @brief Destructor
             *
             */
            ~Sprite() = default;

            /**
             * @brief Getter for the height of the sprite
             *
             * @return Height of the sprite
             */
            int getHeight() const;

            /**
             * @brief Getter for the width of the sprite
             *
             * @return Width of the sprite
             */
            int getWidth() const;

            /**
             * @brief Getter for the scale of the sprite
             *
             * @return Scale of the sprite
             */
            Vector getScale() const;

            /**
             * @brief Setter for the height of the sprite
             *
             * @param height Height of the sprite
             */
            int setHeight(int height);

            /**
             * @brief Setter for the width of the sprite
             *
             * @param width Width of the sprite
             */
            int setWidth(int width);

            /**
             * @brief Setter for the scale of the sprite
             *
             * @param scale Scale of the sprite
             */
            void setScale(Vector scale);

        private:
            int m_height;
            int m_width;
            Vector m_scale;
    }; /* class Sprite */

} /* namespace arc */
