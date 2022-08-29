cmake_minimum_required(VERSION 3.13.0)

project(engine)

add_executable(engine main.cpp)

target_link_libraries(engine PRIVATE math)