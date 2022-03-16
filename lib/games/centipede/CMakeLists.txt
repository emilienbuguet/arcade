cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Centipede.cpp
)

add_library(centipede SHARED
    ${SRCS}
)

set_target_properties(centipede PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/"
)

target_include_directories(centipede PRIVATE
    ${CMAKE_BINARY_DIR}/lib/games/centipede/includes
    ${CMAKE_BINARY_DIR}/lib/games/includes
    ${CMAKE_BINARY_DIR}/src/includes
)
