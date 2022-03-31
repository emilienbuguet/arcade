cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Pacman.cpp
)

add_library(pacman SHARED
    ${SRCS}
)

set_target_properties(pacman PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(pacman PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/games/pacman/includes
    ${CMAKE_SOURCE_DIR}/lib/games/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)
