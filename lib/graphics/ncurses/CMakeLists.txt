cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Ncurses.cpp
)

find_package(Curses REQUIRED)

add_library(ncurses SHARED
    ${SRCS}
)

set_target_properties(ncurses PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

target_include_directories(ncurses PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/graphics/ncurses/includes
    ${CMAKE_SOURCE_DIR}/lib/graphics/includes
    ${CMAKE_SOURCE_DIR}/src/includes
    ${CURSES_INCLUDE_DIR}
)

target_link_libraries(ncurses ${CURSES_LIBRARIES})
