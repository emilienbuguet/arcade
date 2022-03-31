cmake_minimum_required(VERSION 3.17)
project(arcade)

set( CMAKE_CXX_STANDARD 20)

set( CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -g3 " )

add_compile_options(-Wall -Wextra -Weffc++ -g3)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        ${PROJECT_SOURCE_DIR}/arcade
        ${PROJECT_SOURCE_DIR}/lib/arcade_ncurses.so
        ${PROJECT_SOURCE_DIR}/lib/arcade_sdl2.so
        ${PROJECT_SOURCE_DIR}/lib/arcade_sfml.so
        ${PROJECT_SOURCE_DIR}/lib/arcade_nibbler.so
        ${PROJECT_SOURCE_DIR}/lib/arcade_pacman.so
        ${PROJECT_SOURCE_DIR}/lib/arcade_menu.so)

add_executable(arcade
        src/main.cpp
        src/Core.cpp
        src/Color.cpp
        src/Error.cpp
        src/Object.cpp
        src/Utils/FileParser.cpp
        src/Utils/HighscoreHandler.cpp
        )

target_link_libraries(arcade PUBLIC dl)

target_include_directories(arcade PUBLIC
        src/includes
        lib/graphics/includes
        lib/games/includes
        lib/games/menu/includes
        )

add_subdirectory(lib/graphics/ncurses)
add_subdirectory(lib/graphics/sdl2)
add_subdirectory(lib/graphics/sfml)

add_subdirectory(lib/games/centipede)
add_subdirectory(lib/games/pacman)
add_subdirectory(lib/games/menu)

add_dependencies(arcade ncurses sdl2 sfml pacman centipede menu)

if(NOT ${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})
    add_custom_command(TARGET arcade COMMAND cp ${CMAKE_BINARY_DIR}/arcade ${CMAKE_SOURCE_DIR}/arcade)
endif()
