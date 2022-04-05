cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Nibbler.cpp
    ./NibblerGame.cpp
    ./Snake.cpp
    ./SnakeCell.cpp
    ./Food.cpp
    ${CMAKE_SOURCE_DIR}/lib/games/AGame.cpp
    ${CMAKE_SOURCE_DIR}/src/Object.cpp
)

add_library(nibbler SHARED
    ${SRCS}
)

set_target_properties(nibbler PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(nibbler PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/games/nibbler/includes
    ${CMAKE_SOURCE_DIR}/lib/games/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)
