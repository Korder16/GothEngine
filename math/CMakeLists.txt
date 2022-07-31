cmake_minimum_required(VERSION 3.10.0)

project(math)

set(HEADER_FILES vec2.hpp vec3.hpp)
set(SOURCE_FILES vec2.cpp vec3.cpp)

add_library(math 
            STATIC 
            ${HEADER_FILES}
            ${SOURCE_FILES}
            )