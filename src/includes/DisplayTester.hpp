#include <Interfaces/IDisplayModule.hpp>

#pragma once


namespace arc {

    class DisplayTester : public arc::display::IDisplayModule {
        public:
            DisplayTester() = default;
            ~DisplayTester() = default;
    }; /* class DisplayHandler */

} /* namespace arc */
