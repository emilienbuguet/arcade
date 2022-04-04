cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set( CMAKE_CXX_FLAGS "-lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2 -Wall -Wextra -Wpedantic " )

set(SRCS
    ./Sdl2.cpp
    ./Sdl2Display.cpp
    ./Error.cpp
    ${CMAKE_SOURCE_DIR}/src/Object.cpp
    ${CMAKE_SOURCE_DIR}/src/Color.cpp
)

find_package(SDL2 REQUIRED)

add_library(sdl2 SHARED
    ${SRCS}
)

set_target_properties(sdl2 PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(sdl2 PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/graphics/sdl2/includes
    ${CMAKE_SOURCE_DIR}/lib/graphics/includes
    ${CMAKE_SOURCE_DIR}/src/includes
    ${SDL2_INCLUDE_DIR}
)
