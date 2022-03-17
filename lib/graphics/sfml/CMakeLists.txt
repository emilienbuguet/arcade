cmake_minimum_required(VERSION 3.10)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    ./Sfml.cpp
)

find_package(SFML 2 REQUIRED network audio graphics window system)

add_library(sfml SHARED
    ${SRCS}
)

set_target_properties(sfml PROPERTIES
    PREFIX "arcade_"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/"
)

target_include_directories(sfml PRIVATE
    ${CMAKE_BINARY_DIR}/lib/graphics/sfml/includes
    ${CMAKE_BINARY_DIR}/lib/graphics/includes
    ${CMAKE_BINARY_DIR}/src/includes
    ${SFML_INCLUDE_DIR}
)

target_link_libraries(sfml ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
