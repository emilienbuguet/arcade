cmake_minimum_required(VERSION 3.10)

project(arcade)

set( CMAKE_CXX_STANDARD 20)

set( CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -g3 " )

set(SRCS
    src/Utils/FileParser.cpp
    src/Utils/HighscoreHandler.cpp
    src/Error.cpp
    src/Core.cpp
    src/Object.cpp
    src/Color.cpp
    src/main.cpp
)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    ${CMAKE_SOURCE_DIR}/arcade
    ${CMAKE_SOURCE_DIR}/lib/arcade_ncurses.so
    ${CMAKE_SOURCE_DIR}/lib/arcade_sfml.so
    ${CMAKE_SOURCE_DIR}/lib/arcade_sld2.so
    ${CMAKE_SOURCE_DIR}/lib/arcade_nibbler.so
    ${CMAKE_SOURCE_DIR}/lib/arcade_pacman.so
    ${CMAKE_SOURCE_DIR}/lib/arcade_menu.so
)

add_executable(arcade ${SRCS})

add_subdirectory(lib/games/pacman)
add_subdirectory(lib/games/centipede)
add_subdirectory(lib/games/menu)

add_subdirectory(lib/graphics/ncurses)
add_subdirectory(lib/graphics/sfml)
add_subdirectory(lib/graphics/sdl2)

target_link_libraries(arcade PUBLIC dl)

target_include_directories(arcade PUBLIC
    ${CMAKE_SOURCE_DIR}/src/includes
    ${CMAKE_SOURCE_DIR}/lib/graphics/includes
    ${CMAKE_SOURCE_DIR}/lib/games/includes
    ${CMAKE_SOURCE_DIR}/lib/games/menu/includes
)

add_dependencies(arcade ncurses sfml sdl2 pacman centipede menu)

if(NOT ${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})
    add_custom_command(TARGET arcade COMMAND cp ${CMAKE_BINARY_DIR}/arcade ${CMAKE_SOURCE_DIR}/arcade)
endif()
