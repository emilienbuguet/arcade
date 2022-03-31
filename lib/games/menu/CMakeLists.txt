cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set( CMAKE_CXX_FLAGS "-lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2 -Wall -Wextra -Wpedantic -g3 " )

set(SRCS
    ./Menu.cpp
    ./MenuGame.cpp
    ./MenuItem.cpp
    ${CMAKE_SOURCE_DIR}/lib/games/AGame.cpp
    ${CMAKE_SOURCE_DIR}/src/Utils/FileParser.cpp
    ${CMAKE_SOURCE_DIR}/src/Error.cpp
    ${CMAKE_SOURCE_DIR}/src/Object.cpp
    ${CMAKE_SOURCE_DIR}/src/Color.cpp
)

add_library(menu SHARED
    ${SRCS}
)

set_target_properties(menu PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(menu PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/games/menu/includes
    ${CMAKE_SOURCE_DIR}/lib/games/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)
