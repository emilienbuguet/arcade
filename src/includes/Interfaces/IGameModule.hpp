#include <Events.hpp>
#include <Object.hpp>

#include <memory>
#include <vector>

#pragma once

namespace arc::games {

    class IGameModule {
        public:
            /**
             * @brief Destroy the IDisplayModule object
             *
             */
            virtual ~IGameModule() = default;

            /**
             * @brief apply the current event
             *
             * @param event
             */
            virtual void useEvent(arc::Events event) = 0;

            /**
             * @brief Get the objects to draw
             *
             * @return const std::vector<std::shared_ptr<IObject>>
             */
            virtual const std::vector<std::shared_ptr<Object>> getObjects() const = 0;
    }; /* class IGameModule */

}
