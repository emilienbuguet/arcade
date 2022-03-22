cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Menu.cpp
    ./MenuGame.cpp
    ../AGame.cpp
)

add_library(menu SHARED
    ${SRCS}
)

set_target_properties(menu PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/"
)

target_include_directories(menu PRIVATE
    ${CMAKE_BINARY_DIR}/lib/games/menu/includes
    ${CMAKE_BINARY_DIR}/lib/games/includes
    ${CMAKE_BINARY_DIR}/src/includes
)
