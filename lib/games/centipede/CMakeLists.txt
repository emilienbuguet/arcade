cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Centipede.cpp
    ./mushroom.cpp
    ./Snake.cpp
    ./Player.cpp
    ${CMAKE_SOURCE_DIR}/lib/games/AGame.cpp
    ${CMAKE_SOURCE_DIR}/src/Object.cpp
)

add_library(centipede SHARED
    ${SRCS}
)

set_target_properties(centipede PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(centipede PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/games/centipede/includes
    ${CMAKE_SOURCE_DIR}/lib/games/includes
    ${CMAKE_SOURCE_DIR}/src/includes
)
