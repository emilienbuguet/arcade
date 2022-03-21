#include <Events.hpp>
#include <Object.hpp>

#include <memory>
#include <vector>

#pragma once

namespace arc::games {

    /**
     * @brief Game module interface
     *
     */
    class IGameModule {
        public:
            /**
             * @brief Destroy the IDisplayModule object
             *
             */
            virtual ~IGameModule() = default;

            /**
             * @brief Apply the current event
             *
             * @param event
             */
            virtual void useEvent(arc::Events event) = 0;

            /**
             * @brief Get the objects to draw
             *
             * @return const std::vector<std::shared_ptr<IObject>>
             */
            virtual const std::vector<std::shared_ptr<arc::Object>> getObjects() const = 0;

            /**
             * @brief Tell if game is running or not
             *
             * @return true or false
             */
            virtual bool isRunning() const = 0;

            /**
             * @brief Update game's entities
             *
             */
            virtual void update() = 0;
    }; /* class IGameModule */

} /* namespace arc::games */
