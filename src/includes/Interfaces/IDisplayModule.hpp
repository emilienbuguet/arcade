#include <Events.hpp>
#include <Object.hpp>

#include <memory>
#include <vector>

#pragma once

namespace arc::display {

    /**
     * @brief Display module interface
     *
     */
    class IDisplayModule {
        public:

            /**
             * @brief Destroy the IDisplayModule object
             *
             */
            virtual ~IDisplayModule() = default;

            /**
             * @brief draw all the objects generated by the game
             *
             * @param objs
             */
            virtual void drawObjects(std::vector<std::shared_ptr<arc::Object>> objs) = 0;

            /**
             * @brief Draw the interface of the game
             *
             */
            virtual void drawInterface(std::vector<std::shared_ptr<arc::Object>> objs) = 0;

            /**
             * @brief get any event
             *
             * @return const arc::Events
             */
            virtual arc::Events getEvent() const = 0;
    }; /* class IDisplayModule */

} /* namespace arc::display */
