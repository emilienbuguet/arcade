cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set( CMAKE_CXX_FLAGS "-lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system -Wall -Wextra -Wpedantic " )

set(SRCS
    ./Sfml.cpp
    ./SfmlDisplay.cpp
    ./Error.cpp
    ${CMAKE_SOURCE_DIR}/src/Object.cpp
    ${CMAKE_SOURCE_DIR}/src/Color.cpp
)

add_library(sfml SHARED
    ${SRCS}
)

set_target_properties(sfml PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(sfml PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/graphics/sfml/includes
    ${CMAKE_SOURCE_DIR}/lib/graphics/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)
