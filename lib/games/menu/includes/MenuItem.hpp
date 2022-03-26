#pragma once

#include <Object.hpp>

namespace arc::games::menu {

    class MenuItem : public arc::Text {
        public:
            /**
             * @brief Construct a new Menu Item object
             *
             * @param value
             * @param pos
             * @param size
             * @param color
             */
            MenuItem(const std::string value, Vector pos, int size, Color color);

            /**
             * @brief Destroy the Menu Item object
             *
             */
            ~MenuItem() = default;

            /**
             * @brief Getter for the selected property
             *
             * @return true or false
             */
            bool isSelected() const;

            /**
             * @brief Setter for the selected property
             *
             * @param selected
             */
            void setSelected(bool selected);

        private:
            bool m_selected;
    }; /* MenuItem */


} /* namespace arc::games::menu */